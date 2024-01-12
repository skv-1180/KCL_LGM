vector<vector<int>> adj;
vector<int> vis;
void inp(int n,int e=-1){
  adj.resize(n+1);
  vis.resize(n+1);
  if(e==-1)e=n-1;//tree
  for(int i=0;i<e;++i){
     int v1,v2;cin>>v1>>v2;
     adj[v1].push_back(v2);
     adj[v2].push_back(v1);
  }
}
void reset(int n){
    for(int i=1;i<=n;i++){
       vis[i]=0;
       adj[i].clear();
    }
}
struct Node {//set default value(Id)
    int ans = 0; 
    int lazy = 0; 
};
Node combine(Node& n1, Node& n2) {  // change here
    Node n3;
    n3.ans = (n1.ans + n2.ans);
    //n3.lazy = 0;//set id
    return n3;
}
class lazyST{
    public:
    int n = 0;
    vector<Node> sgt;
    private:
    

    void push(int v, int tl, int tr) { //change here
        if(sgt[v].lazy == 0)return;
        int tm = (tr + tl) >> 1;
        sgt[v<<1].ans += (tm-tl+1)* sgt[v].lazy;
        sgt[v<<1].lazy += sgt[v].lazy;
        sgt[(v<<1)|1].ans +=(tr-tm)* sgt[v].lazy;
        sgt[(v<<1)|1].lazy += sgt[v].lazy;
        sgt[v].lazy = 0;//set id
    }

    void build(int v, int tl, int tr, vector<int>&a) {
        if (tl == tr) {// ans(tl - tr)-> v
            sgt[v].ans = a[tl];// change here
        } else {
            int tm = (tl + tr) >> 1;
            build(v<<1, tl, tm, a);
            build((v<<1)|1, tm + 1, tr, a);
            sgt[v] = combine(sgt[v<<1], sgt[(v<<1)|1]);
        }
    }
    void point_update(int v, int tl, int tr, int pos, int x){
        if(tl == tr){
            sgt[v].ans = x;//change here
        }else{
            int tm = (tl + tr) >> 1;
            if(pos <= tm){
                point_update(v<<1, tl, tm, pos, x);
            }else{
                point_update((v<<1)|1, tm+1, tr, pos, x);
            }
            sgt[v] = combine(sgt[v<<1], sgt[(v<<1)|1]);
        }
    }
    void update_range(int v, int tl, int tr, int l, int r, int x) {
        if (l > r) return;
        if (tl == l && tr == r) {
            sgt[v].ans +=(tr-tl+1)* x;//change here
            sgt[v].lazy += x;//change here
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) >> 1;
            update_range(v<<1, tl, tm, l, min(tm, r), x);
            update_range((v<<1)|1, tm + 1, tr, max(l, tm + 1), r, x);
            sgt[v] = combine(sgt[v<<1], sgt[(v<<1)|1]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            Node n;
            return n;  // change default value
        }
        if (tl == l && tr == r){
            return sgt[v];
        }
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        Node n1 = query(v<<1, tl, tm, l, min(r, tm));
        Node n2 = query((v<<1)|1, tm + 1, tr, max(tm + 1, l), r);
        return combine(n1, n2);
    }
    public:
    lazyST(){}
    lazyST(vector<int>&a, int sz=0){
        n=a.size();
        n=max(sz,n);
        int size = 1;
        while(size < n) size *= 2;
        sgt.resize(2*size);
        build(1,0,n-1,a);
    }
    void set(vector<int>&a, int sz=0){
        n=a.size();
        n=max(sz,n);
        int size = 1;
        while(size < n) size *= 2;
        sgt.resize(2*size);
        build(1,0,n-1,a);
    }
    void point_update(int pos,int val){
        point_update(1,0,n-1,pos,val);
    }
    void range_update(int l, int r, int x){
        update_range(1,0,n-1,l,r,x);
    }
    Node range_query(int l,int r){
        return query(1,0,n-1,l,r);
    }
    void print(){
        for(int i=0;i<n;i++){
            cout<<range_query(i,i).ans<<' ';
        }cout<<endl;
    }
};

//lazyST lt(v,n)
//lt.range_update(l,r,x)//(l,r)0-idx
//lt.range_query(l,r)//(l,r)0-idx
class hld{
    private:
        vector<int> parent, depth, heavy, head, pos;
        int cur_pos;
        lazyST seg;
        int dfs_hld(int v) {
            int size = 1;//number of nodes in subtree of v
            int max_c_size = 0;//max number of subtree nodes for a child of v
            for (int c : adj[v]) {
                if (c != parent[v]) {
                    parent[c] = v, depth[c] = depth[v] + 1;
                    int c_size = dfs_hld(c);
                    size += c_size;
                    if (c_size > max_c_size)
                        max_c_size = c_size, heavy[v] = c;
                }
            }
            return size;
        }
        void decompose(int v, int h) {
            head[v] = h, pos[v] = cur_pos++;
            if (heavy[v] != -1)
                decompose(heavy[v], h);
            for (int c : adj[v]) {
                if (c != parent[v] && c != heavy[v])
                    decompose(c, c);
            }
        }
    public:
        hld(int source , vi& values){
            int n = adj.size();
            parent = vector<int>(n);
            depth = vector<int>(n);
            heavy = vector<int>(n, -1);
            head = vector<int>(n);
            pos = vector<int>(n);
            cur_pos = 0;
            
            dfs_hld(source);
            decompose(source,source);
            parent[1]=1;
            vi v(values.size());//initial segment tree
            for(int i=1;i<v.size();i++){
                v[pos[i]]=values[i];
            }
            seg.set(v);
        }
        Node query(int a, int b) {
            Node res ;
            for (; head[a] != head[b]; b = parent[head[b]]) {
                if (depth[head[a]] > depth[head[b]])
                    swap(a, b);
                Node cur_heavy_path_max = seg.range_query(pos[head[b]], pos[b]);
                res = combine(res, cur_heavy_path_max);
            }
            if (depth[a] > depth[b])
                swap(a, b);
            Node last_heavy_path_max = seg.range_query(pos[a], pos[b]);
            res = combine(res, last_heavy_path_max);
            return res;
        }
        void range_update(int a,int b,int x){
            Node res ;
            for (; head[a] != head[b]; b = parent[head[b]]) {
                if (depth[head[a]] > depth[head[b]])
                    swap(a, b);
                seg.range_update(pos[head[b]], pos[b],x);
            }
            if (depth[a] > depth[b])
                swap(a, b);
            seg.range_update(pos[a], pos[b],x);
        }
        void point_update(int a,int x){
            seg.point_update(pos[a],x);
        }
};
