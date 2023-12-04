//!                ______          ______                  !//
//!  \\\    ///   ///  \\\      |||      |||  |||     |||  !//
//!   \\\  ///   ///    \\\     |||           |||_____|||  !//
//!    \\\///   ///_____\\\    |||______    |||_____|||  !//
//!     \///   ///________\\\            |||  |||_____|||  !//
//!     ///   ///          \\\           |||  |||     |||  !//
//!    ///   ///            \\\ |||______|||  |||     |||  !//
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define endl '\n'
#define ll long long 
#define int long long int
#define pii pair<int,int>
#define popcount __builtin_popcount
#define vi vector<int>
#define vii vector<vector<int>>
#define ff first
#define ss second
#define csort(v) sort(begin(v),end(v),cmp);debug(v)
#define lb(v,x) lower_bound(begin(v),end(v),x,cmp)-begin(v);
#define ub(v,x) upper_bound(begin(v),end(v),x,cmp)-begin(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define input(x) for(auto &a:x)cin>>a;debug(x)
using namespace std;using namespace __gnu_pbds;
template<class T>using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T>using omset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
const ll INF = 1e18 + 10;
const ll M = 1e9 + 7;
const ll N = 1e7 + 10;
#ifndef ONLINE_JUDGE
    #include<bits/debugger.h>
    #define iofiles freopen("output.t","w",stderr);freopen("input.t","r",stdin)
#else
    #define cl()
    #define graph(x,y)
    #define debug(x...)
    #define debugptr(x,y)
    #define iofiles
#endif
bool cmp(ll a,ll k){return k>a;}

class st{
    private:
        vi seg;int n=0;
        vi lazy;int id=1e18;//function identity:(set every time)
        int func(int a,int b){//yahi function hai!!!
            return min(a,b);
        }
        void buildseg(vi& a,ll v,ll tl,ll tr) {
            if (tl == tr) seg[v] = a[tl];
            else {
                ll tm = (tl + tr) >> 1;
                buildseg(a, v<<1, tl, tm);
                buildseg(a, (v<<1)+1, tm+1, tr);
                seg[v] = func(seg[v*2] , seg[v*2+1]); 
            }
        }
        
        void push(ll v,ll tl,ll tr){
            ll tm = (tl+tr)/2;
            seg[v<<1]=func(seg[v<<1],(tm-tl+1)*lazy[v]);
            lazy[v<<1]=func(lazy[v<<1],lazy[v]);
            seg[(v<<1)+1]=func(seg[(v<<1)+1],(tr-tm)*lazy[v]);
            lazy[(v<<1)+1]=func(lazy[(v<<1)+1],lazy[v]);
            lazy[v]=id;  
        }
        
        ll queryseg(ll v,ll tl,ll tr,ll l,ll r) {
            if (l > r) return id; 
            if (l == tl && r == tr) return seg[v];
            push(v,tl,tr);
            ll tm = (tl + tr) >> 1;
            return func(queryseg(v*2, tl, tm, l, min(r, tm)) , queryseg(v*2+1, tm+1, tr, max(l, tm+1), r));
        }
        
        void updateseg(ll v,ll tl,ll tr,ll pos,ll new_val) {
            if (tl == tr) seg[v] = new_val;
            else {
                ll tm = (tl + tr) >> 1;
                if (pos <= tm) updateseg(v*2, tl, tm, pos, new_val);
                else updateseg(v*2+1, tm+1, tr, pos, new_val);
                seg[v] = func(seg[v*2] , seg[v*2+1]);    
            }
        }
        
        void upranseg(ll v,ll tl,ll tr,ll l,ll r,ll addend) {
            if (l > r) return;
            if (l == tl && tr == r) {
                seg[v] =func(seg[v],(tr-tl+1)*addend);  
                lazy[v]=func(lazy[v],addend) ; 
            } 
            else {
                push(v,tl,tr);
                ll tm = (tl + tr) / 2;
                upranseg(v*2, tl, tm, l, min(r, tm), addend);
                upranseg(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
                seg[v] =func (seg[v*2] , seg[v*2+1]);   
            }
        }
    public:
        st(vi &a){
            n=a.size();
            seg.resize(n<<2);
            lazy.assign(n<<2,id);
            buildseg(a,1ll,0ll,n-1);debug(seg)debug(lazy)
        }
        int query(int l,int r){
            return queryseg(1ll,0ll,n-1,l,r);
        }
        void update(int pos,int new_val){
            updateseg(1ll,0ll,n-1,pos,new_val);
        }
        void update(int l,int r,int addend){
            upranseg(1ll,0ll,n-1,l,r,addend);
        }
};

void solve(){
    int n;cin>>n;
    vi v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    st s(v);
    cout<<s.query(2,4)<<endl;
    s.update(3,108);
    cout<<s.query(3,3)<<' '<<s.query(2,4)<<endl;
    s.update(2,5,10);
    for(int i=0;i<=n;i++){
        cout<<s.query(i,i)<<endl;
    }
}


signed main(){
    fast ;
    int t=1,TestCase=0;
    while(t--){
        TestCase++;debug(TestCase)
            solve();
        cl()
    }
return 0;
}