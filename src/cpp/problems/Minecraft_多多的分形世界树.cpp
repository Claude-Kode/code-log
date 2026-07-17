// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n; cin >> n;
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 

  vector<int> dep(n + 1);
  function<void(int, int)> dfs = [&](int u, int f) -> void {
    dep[u] = dep[f] + 1;
    for(const int& v : adj[u]) if (v != f) dfs(v, u);
  };

  dfs(1, 0);
  int mx = 0, ans = INT_MAX;
  for(int i = 1; i <= n; i ++) {
    if (mx < dep[i]) mx = dep[i], ans = i;
  }

  cout << ans << ' ' << mx - 1 << endl;
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}