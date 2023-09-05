#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define MOD 1000000007
#define ff first
#define ss second
using namespace std;
#define pi acos(-1)
const int N = 1e7 + 10;
const int M = 1e9 + 7 ;
const int L = 1e5 + 10;

//debug(x)-->analyse 'x'//
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<"(Line "<<_LINE<<"):"<<#x << " ";_print(x);cerr<<endl;
#define debugarr(x,y) cerr<<"(Line "<<_LINE<<"):"<<#x<<" ";_print(x,y);cerr<<endl;
#define cl() cerr<<endl;
#else
#define debug(x)
#define debugptr(x,y)
#define cl()
#endif


//cacl mod inverse of i wrt m
//T.C.:O(log(i)/log(log(m))) M.C.:O(1)
int inv(int i,int m) {
  i%=m;
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i,m) % m;
}
//Generates inverse mod(m) till m
//T.C.:O(m) M.C.:O(m)
vector<int>invs;
void generate_inv(int m){
    invs.resize(m);
    invs[1] = 1;
    for(int i = 2; i < m; ++i)
        invs[i] =( m - (long long)(m/i) * invs[m%i] % m)%m;

}
//!!WARNING!!{add:extended_euclid}
//create mod inv of all arr elements mod(m)
std::vector<int> invarr(const std::vector<int> &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    std::vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    int x, y;
    // extended_euclidean(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}
long long crt_coprimes(vector<pair<long long,long long>> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.second;
    }
    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.first;
        long long M_i = M / congruence.second;
        long long N_i = inv(M_i, congruence.second);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}
    ll sum(ll n,int mod=M){
        ll r = ((((n % mod) * ((n + 1) %mod)) % mod) * inv(2,M)) % mod;
        return r;
    }
    
//Calculate n!%p
//T.C.:O(p+logp(n)) M.C.:O(p)
vector<int> f;//f[i]=i!%p
int factmod(int n, int prime) {
    f.resize(prime);
    f[0] = 1;
    //precomputation of f
    for (int i = 1; i < prime; i++)f[i] = f[i-1] * i % prime;

    int res = 1;
    while (n > 1) {
        if ((n/prime) % 2)res = prime - res;
        res = res * f[n%prime] % prime;
        n /= prime;
    }
    return res;
}
//gives power of p=>"prime" in n!
//T.C.:O(p+logp(n)) M.C.:O(1)
int multiplicity_factorial(int n, int p) {
    int count = 0;
    do {
        n /= p;
        count += n;
    } while (n);
    return count;
}

ll sigma(ll n,ll mod=M ){
    ll l = 1;
    ll ans = 0;
 
    while (l <= n)
    {
        ll k = n / l;
        ll r = n / k;
        k %= mod;
        ans += (((sum(r) - sum(l - 1) )%mod) * k) % mod;
        ans %= mod;
        l = r + 1;
    }
    ans = (ans+mod) % mod;
    if (ans < 0){
        return ans+mod;
    }else{
        return ans;
    }
}
 



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1,TestCase=0;
    while(t--){
        TestCase++;
            ll n;cin>>n;
            cout<<sigma(n);
        cl()
    }
return 0;
}