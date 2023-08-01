#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include<bits/debugger.h>
#else
#define cl()
#define setio
#define graph(x,y)
#define debug(x...)
#define debugptr(x,y)
#endif

struct manacher{
    vector<int>p;
    /* Vivek Gupta =>for finding longest palindrome and all palindrome in a string*/
    void run_manacher(string s){ /* O(n+n) => O(n) */
        int n = s.length();
        p.assign(n,1);
        int l=1,r=1;
        for(int i=1;i<n;i++){
            p[i]=max(0, min(r-i,p[l+r-i]));
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]] == s[i-p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }

    void build(string s){
        string t;
        for(auto v:s){
            t += string("#")+v; //* O(1) *//
        }
        t += string("#");
        run_manacher(t);
        debug(t)
        debug(p)

    }

    string getLongestSubstring(string s){
        int mxidx = max_element(begin(p), end(p)) - begin(p);
        int mxLength = p[mxidx]-1;
        int start_idx = ((mxidx-1)/2) - (p[mxidx]-2)/2;
        return s.substr(start_idx, mxLength);
    }

    int getLongest(int cen, bool odd){
        int pos = 2*cen+1+(!odd);
        return p[pos]-1;
    }

    //* 0 indexing *//
    bool checkPalindrome(int l,int r){ //*check whether s.substr(l,r-l+1) is a palindrome or not in O(1) */
        if((r-l+1)<=getLongest((l+r)/2, l%2==r%2)){
            return 1;
        }else{
            return 0;
        }
    }

}m;

void solve(){
    string s="abbab";
    m.build(s);
    cout<<m.getLongestSubstring(s)<<endl;
    int q=10;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<m.checkPalindrome(l,r)<<endl;
    }
}

signed main()
{
   
    solve();
    return 0;
}
