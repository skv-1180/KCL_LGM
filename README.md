//!                ______          ______                  !//
//!  \\\    ///   ///  \\\      |||      |||  |||     |||  !//
//!   \\\  ///   ///    \\\     |||           |||_____|||  !//
//!    \\\///   ///______\\\    |||_______    |||_____|||  !//
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
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
signed main(){
    fast iofiles;
    int t=1,TestCase=0;cin>>t;
    while(t--){
        TestCase++;debug(TestCase)
            int n,m,k;cin>>n>>m>>k;
            if(k>3){
                cout<<0<<endl;continue;
            }
            if(k==1){
                cout<<1<<endl;
            }
            else if(k==2){
                cout<<min(m,k-1+((m-k)/k))<<endl;
            }
            else{
                cout<<max(m-k-((m-k)/k),0ll)<<endl;

            }
        cl()
    }
return 0;
}
