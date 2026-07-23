#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long 

void solve() {
  int n, m;
  cin >> n >> m;
  
  if (m <= n - 1) {
    cout << (m - 1) * m / 2 << "\n";
  } else {
    int ans = (n - 2) * (n - 1) / 2;
    m -= (n - 1);
    ans -= m;
    cout << ans << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1;
  cin >> tt;
  while (tt --) {
    solve();
  }
}