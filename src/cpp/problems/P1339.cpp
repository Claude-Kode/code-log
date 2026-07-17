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

int n, m, s, t; 

void solve() { 
  cin >> n >> m >> s >> t;
  vector<vector<array<int, 2>>> adj(n + 1);
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  auto cmp = [&](const auto &a, const auto &b) -> bool {
    return a[1] > b[1];
  };

  priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> pq(cmp);
  pq.push({s, 0});
  vector<int> dis(n + 1, INT_MAX), vis(n + 1); 
  dis[s] = 0;
  while(!pq.empty()) {
    auto [u, w] = pq.top();
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    if (u == t) {cout << w << endl; return;}
    for(const auto &[v, ww] : adj[u]) if (!vis[v] && dis[u] + ww < dis[v]) {
      dis[v] = dis[u] + ww;
      pq.push({v, w + ww});
    }
  }
  
  cout << -1 << endl;
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // whi  le(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}