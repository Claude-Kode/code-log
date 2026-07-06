// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, m; cin >> n >> m;
  vector<vector<array<int, 2>>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  unordered_map<int, int> free;
  for(int i = 1; i <= m; i ++) {
    int temp; cin >> temp;
    free[temp] = 1;
  }

  vector<int> cnt_s(n + 1), cnt_f(n + 1);
  vector<array<int, 2>> p(n + 1, {0, 0});
  function<void(int, int)> dfs = [&](int u, int f) -> void {
    cnt_f[u] = free[u];
    if (adj[u].size() == 1 && u != 1) {
      cnt_s[u] = 1;
    }

    for(const auto &[v, w] : adj[u]) if (v != f) {
      p[v] = {u, w};
      dfs(v, u);
      cnt_s[u] += cnt_s[v];
      cnt_f[u] += cnt_f[v];
    }

    if (free[u]) cnt_s[u] = 1;
  };

  dfs(1, 0);

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    if (cnt_s[i] > 1) {
      ans += (cnt_s[i] - 1) * p[i][1];
    } 
  } 

  cout << ans << endl;
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}