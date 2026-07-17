#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long 

void solve() {
  int n; cin >> n;
  map<int, vector<int>> mp;
  int mx = 0;
  for (int i = 1; i <= n; i ++) {
    int c, d; cin >> c >> d;
    mp[c].push_back(d);
    mx = max(mx, (int)mp[c].size());
  }

  for (auto &[c, v] : mp)  sort(v.rbegin(), v.rend());

  int ans = 0;
  for (int j = 0; j < mx; j++) {
    int cnt = 0, pc = 0, pv = 0;  
    for (auto &[c, v] : mp) {
      int val = j < (int)v.size() ? v[j] : 0;
      cnt = (c == pc + 1 && pv) ? cnt + 1 : 1;
      ans += cnt * val;
      pc = c, pv = val;
    }
  }
  cout << ans << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1; 
  cin >> tt;
  while (tt --) {
    solve();
  }

  return 0;
}