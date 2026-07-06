#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve() {
  int n, x, a, b;
  cin >> n >> x >> a >> b;
  cout << (b * x + a * (n - x) ) << "\n";
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