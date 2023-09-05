#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e9+7;
const int M = 1e9+7;
const int INF=1e18+10;
#define colon ;
#define endl '\n'
#define ff first
#define ss second
#define pie acos(-1)
#define pb push_back
#define vi vector<int>
#define pi pair<int,int>
#define cint(x) int x colon cin>>x;
#define cstr(x) string x colon cin>>x;
#define ssort(v) sort(begin(v),end(v));
#define rev(v) reverse(begin(v),end(v));
#define ccint(x,y) int x,y colon cin>>x>>y;
#define ccstr(x,y) string x,y colon cin>>x>>y;
#define cvect(v,n) vector<int>v(n)colon for(int i=0;i<n;i++)cin>>v[i];
#define ll long long
#ifndef ONLINE_JUDGE
#include<bits/debugger.h>
#else
#define cl()
#define graph(x,y)
#define debug(x...)
#define debugptr(x,y)
#endif

//cacl mod inverse of i wrt m
//T.C.:O(log(i)/log(log(m))) M.C.:O(1)
int inv(int i,int m) {
  i%=m;
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i,m) % m;
}
ll sum(ll n,int mod=M){
    ll r = ((((n % mod) * ((n + 1) %mod)) % mod) * inv(2,M)) % mod;
    return r;
}
 

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1,TestCase=0;
    while(t--){
        TestCase++;vi v(1);
            cint(n)int ans=0;
            int sq= sqrt(n);
            for(int i=1;i<=sq;i++){
                if(i*i==n){
                    // debug(ans)
                    ans=(ans+n)%N;
                    continue;
                }
                //?perfect square
                int d1=i%N;
                int d2=(n/i)%N;
                
                int add=(d1*d2)%N;
                
                int nd = (n/(i+1))%N;
                int f2=d2-nd;
                ans=(ans+add)%N;
                if(d1==d2){
                    continue;
                }
                int tmp=((((2*add-((f2-1)*d1)%N)*f2))%N*inv(2,N))%N;
                ans=(ans+tmp)%N;
                // debug(d1,d2,nd,f2,tmp,add,ans)

            }
            int ans1=0;
            // for(int i=1;i<=n;i++){
            //     int p=n/i;
            //     int add=i*p;
            //     ans1=(ans1+add)%N;
            //     cout<<add<<" ";
            //     v.pb(add);
            // }
            cout<<(ans%N+N)%N;
            // debug(ans1%N)
            ssort(v);
            debug(v)
        cl()
    }
return 0;
}