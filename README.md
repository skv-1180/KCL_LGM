/* author:  Shubham Kr. Verma */
#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
#define endl '\n'
#define int long long
#define INF LLONG_MAX
#define vi vector<int>
#define pii pair<int,int>
#define all(v)begin(v),end(v)
#define cint(y...) int y;IN(y);
#define cstr(y...) string y;IN(y);
#define p(x) cout<<x<<' ';
#define pl(x) cout<<x<<endl;
#define print(v)for(auto x:v)cout<<x<<' ';cout<<endl;
#define cvect(v,n)vector<int>v(n);for(auto&x:v)cin>>x;
void IN(auto&x){cin>>x;}void IN(auto &x,auto&... y){IN(x);IN(y...);}

#ifndef ONLINE_JUDGE
#include<bits/debugger.h>
#else
#define graph(x,y)
#define debug(x...)
#endif

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cint(n)
    vector<pii>v(n);
    int sum =0 ;
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i+1;
        sum += v[i].first;
    }
    debug(sum,v)
    sort(all(v));
    reverse(all(v));
    sum-=v[0].first;
    if(v[0].first>sum){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        for(int i=0;i<n;i++){
            cout<<v[i].second<<" ";
        }
        cout<<endl;
    }
return 0;
}
