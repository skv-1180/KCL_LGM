//Preprocessing:T.C.:O(N)      M.C.:O(4*N)
//excessing    :T.C.:O(log(N)) M.C.:O(1)
//note your vector should be 1 indexed and query 1 indexed;
class st{
    private:
        pii id = {-1,-1};//identity of func f
        vector<pii>t;int n=0;int si=0;
        pii f(pii a,pii b){
            return max(a,b);
        }
        void build(vector<pii>&a, int v, int tl, int tr) {
            if (tl == tr)t[v] = a[tl];
            else {
                int tm = (tl + tr) / 2;
                build(a, v*2, tl, tm);
                build(a, v*2+1, tm+1, tr);
                t[v] = f(t[v*2] , t[v*2+1]);
            }
        }
        
        pii func(int v, int tl, int tr, int l, int r){
            if (l > r) return id;
            if (l == tl && r == tr)return t[v];
            int tm = (tl + tr)>>1;
            return f(func(v*2, tl, tm, l, min(r, tm)),func(v*2+1, tm+1, tr, max(l, tm+1), r));
        }
        void modify(int v, int tl, int tr, int pos, pii new_val) {
            if (tl == tr) t[v] = new_val;
            else {
                int tm = (tl + tr) / 2;
                if (pos <= tm)modify(v*2, tl, tm, pos, new_val);
                else     modify(v*2+1,tm+1,tr,pos, new_val);
                t[v] = f(t[v*2] , t[v*2+1]);
            }
        }
    public:
        st(vector<pii>&a,int MAXN){
            t.resize(4*MAXN);si=1;n=a.size();//n=n+1
            build(a,1ll,si,n-1);
            // debug(t)
        }
        void update(int position,pii new_value){
            modify(1ll,si,n-1,position,new_value);
        }
        pii query(int l,int r){
            return func(1ll,si,n-1,l,r);
        }
};
//st s(v,10);//v is your vector 10 is its max size
//s.query(2,5);//it will give f aplied at 2 ,3 , 4,5
//s.update(a,b);//it will update ath number to b in our data
//for convertig to 0 indexing make si=0 && take input as 0 indexing and pass --l,--r,--u//u->update index
