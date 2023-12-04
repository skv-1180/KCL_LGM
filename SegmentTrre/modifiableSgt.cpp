#include <bits/stdc++.h>
using namespace std;
#define int long long

const int SZ = 2e5;

struct Node{
    int ans;
};

Node combine(Node n1, Node n2){//change here
    Node n3;
    n3.ans = n1.ans + n2.ans;
    return n3;
}

vector<Node>sgt(4*SZ + 10);
void build(int v, int tl, int tr, vector<int> &a){
    //ans(tl - tr)-> v
    if(tl == tr){
        sgt[v].ans = a[tl];
    }else{
        int tm = (tl + tr) >> 1;
        build(2*v, tl, tm, a);
        build(2*v+1, tm+1, tr, a);

        sgt[v] = combine(sgt[2*v], sgt[2*v+1]);
    }
}
void update(int v, int tl, int tr, int pos, int x){
    if(tl == tr){
        sgt[v].ans = x;
    }else{
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            update(2*v, tl, tm, pos, x);
        }else{
            update(2*v+1, tm+1, tr, pos, x);
        }

        sgt[v] = combine(sgt[2*v], sgt[2*v+1]);
    }
}
Node query(int v, int tl, int tr, int l, int r){
    if(l > r){
        return {0};//change default value
    }
    if(tl == l && tr == r){
        return sgt[v];
    }
    int tm = (tl + tr) >> 1;
    return combine(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(tm+1, l),r));
}
//tl,tr,l,r,a-0-ind,v-1-ind
//l,r - 0 -idx
// build(1, 0, n-1,a);
// update(1,0,n-1,2,5);
// query(1,0,n-1,1,3).ans

signed main()
{
    int n = 4;
    vector<int> a = {1, 2, 3, 4};
    //l,r - 0 -idx
    build(1, 0, n-1,a);
    update(1,0,n-1,2,5);
    cout<<query(1,0,n-1,1,3).ans;

    return 0;
}