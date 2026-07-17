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
  int n; cin >> n;
  vector<vector<int>> g(n + 1, vector<int>(n + 1, INT_MAX));
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    g[i][i] = 0; cin >> vec[i];
  }

  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
      int a = (i + j) / 2, b = (i + j + 1) / 2;
      g[i][j] = min(g[i][j], vec[a] + vec[b]);
      g[j][i] = min(g[j][i], vec[a] + vec[b]);
    }
  }

  auto cmp = [&](const auto &a, const auto &b) -> bool {
    return a[1] > b[1];
  };  
  priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> pq(cmp);

  auto prime = [&](int s) -> int {
    int ans = 0, cnt = 0;
    vector<int> dis(n + 1, INT_MAX);
    unordered_map<int, int> vis;
    pq.push({s, 0});

    while(!pq.empty()) {
      auto [u, w] = pq.top(); pq.pop();
      if (vis[u]) continue;
      vis[u] = 1; 
      dis[u] = 0; 
      cnt ++; 
      ans += w;
      if (cnt == n) break;
      for(int v = 1; v <= n; v ++) {
        if (!vis[v] && g[u][v] < dis[v]) {
          dis[v] = g[u][v];
          pq.push({v, dis[v]});
        }
      }
    }

    return ans;
  };
  
  cout << prime(1) << endl;
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