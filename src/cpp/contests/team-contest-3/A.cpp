#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int x, y; cin >> x >> y;
  int res = lcm(x, y) / __gcd(x, y);
  cout << 1 << ' ' << res << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  cin >> tt;
  while(tt --) {
    solve();
  }

  return 0;
}