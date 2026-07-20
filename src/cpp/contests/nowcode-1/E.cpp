#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  int ans = 0;

  auto  pre = a;
  for (int i = 1; i <= n; i ++) {
    pre[i] += pre[i - 1];
    ans += (i - 1) * a[i] - pre[i - 1];
  }

  cout << ans << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }

  return 0;
}