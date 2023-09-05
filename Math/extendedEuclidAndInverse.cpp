#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll x1, y1;
  ll d = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
ll inverse(ll a, ll m) {
  ll x, y;
  ll g = extended_euclid(a, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll x,y;
  extended_euclid(55,80,x,y);
  cout<<x<<" "<<y<<endl;
  ll x1 = 100, m = 37;

  cout << inverse(x1, m) << '\n';
  return 0;
}