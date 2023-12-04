#include <bits/stdc++.h>
using namespace std;
#define int long long

const int SZ = 2e5;

struct Node{
    int sum;
};

Node combine(Node n1, Node n2){//change here
    Node n3;
    // n3.sum = n1.sum + n2.sum;
    n3.sum = 0;
    return n3;
}

//tl,tr,l,r,a->(0-indexing), v-(1-indexing)
vector<Node>sgt(4*SZ + 10);

void build(int v, int tl, int tr, vector<int> &a){
    //ans(tl - tr)-> v
    if(tl == tr){
        sgt[v].sum = a[tl];
    }else{
        int tm = (tl + tr) >> 1;
        build(2*v, tl, tm, a);
        build(2*v+1, tm+1, tr, a);

        sgt[v] = combine(sgt[2*v], sgt[2*v+1]);
    }
}
//range update
void range_update(int v, int tl, int tr, int l, int r, int x){
    if(l > r){
        return;
    }
    if(tl == l && tr == r){
        sgt[v].sum += x;
    }else{
        int tm = (tl + tr) >> 1;
        range_update(2*v, tl, tm, l, min(r, tm),x);
        range_update(2*v+1, tm+1, tr, max(tm+1, l),r,x);
    }
}

int query(int v, int tl, int tr, int pos){
    if(tl == tr){
        return sgt[v].sum;
    }else{
        int tm = (tl+tr)>>1;
        if(pos <= tm){
            return sgt[v].sum+query(2*v,tl,tm,pos);
        }else{
            return sgt[v].sum+query(2*v+1,tm+1,tr,pos);
        }
    }
}

signed main()
{
    //l,r - 0-idx
    vector<int> a = {1, 2, 3, 4};
    int n = 4;
    build(1, 0, n-1,a);
    // update(1,0,n-1,2,5);
    // cout<<query(1,0,n-1,1,3);

    return 0;
}