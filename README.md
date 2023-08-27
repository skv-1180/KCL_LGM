/* author:  Shubham Kr. Verma */
#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
#define endl '\n'
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(v)begin(v),end(v)
#define cint(x)int x; cin>>x;
#define cstr(x)string x;cin>>x;
#define ccint(x,y)int x,y;cin>>x>>y;
#define ccstr(x,y)string x,y;cin>>x>>y;
#define print(v)for(auto x:v)cout<<x<<' ';cout<<endl;
#define cvect(v,n)vector<int>v(n);for(auto&x:v)cin>>x;

#ifndef ONLINE_JUDGE
#include<bits/debugger.h>
#else
#define graph(x,y)
#define debug(x...)
#endif


int tl;

bool chk1(int m){
    int p=(m*(m+1))/2;
    return (p*p-9)<tl;
}

int bs1(){
    int s = 0,e=1e4+10;
    int ans=0;
    while(s<=e){
        int m=(s+e)/2;
        // debug(m,tl)
        if(chk1(m)){
            ans=m;
            s=m+1;
        }else{
            e=m-1;
        }
    }
    int p=(ans*(ans+1))/2;
    tl-=((p*p-9));
    ans++;
    return ans;
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    ccint(l,r)
    tl=l;
    int a=1,b=1,c=1,n=3;
    n=bs1();
    debug(n,tl)
    
return 0;
}
