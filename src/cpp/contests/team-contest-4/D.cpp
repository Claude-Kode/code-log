#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int n; cin >> n;
  vector<vector<int>> vec(4);

  for (int i = 1; i <= n; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a) vec[1].push_back(i);
    if (b) vec[2].push_back(i);
    if (c) vec[3].push_back(i);
  }

  int ans = 3;
  vector<int> s = {1, 2, 3};
  do {
    int t = 0;
    vector<int> vis(n + 1);
    int rem = n;
    for (auto &x : s) {
      t ++;
      for (auto &c : vec[x]) {
        if (vis[c]) continue;
        vis[c] = 1;
        rem --;
        if (rem <= 0) break;
      }
      if (rem <= 0) break;
    }
    ans = min(ans, t);
  } while (next_permutation(s.begin(), s.end()));

  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  // cin >> tt;
  while(tt --) {
    solve();
  }

  return 0;
}