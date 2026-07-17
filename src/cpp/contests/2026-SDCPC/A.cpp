// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

using i32 = int32_t;
using i64 = int64_t;

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else
  #define dbug(...)
#endif

void solve() {
  int n, m;
  cin >> n >> m;
  int N = n * m;

  auto dc = [&](char ch) -> int {
    if (ch == 'U') return 0;
    if (ch == 'L') return 1;
    if (ch == 'D') return 2;
    if (ch == 'R') return 3;
    return -1;
  };

  auto id = [&](int x, int y) -> int {
    return (x - 1) * m + y;
  };

  vector<vector<int>> g(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++) {
      char ch; cin >> ch;
      g[i][j] = dc(ch);
    }

  vector<vector<int>> G(N + 1);
  for (int i = 1; i <= n; i ++) {
    int lst = -1;
    for (int j = 1; j <= m; j ++) {
      if (g[i][j] == 1) {
        for (int k = (lst == -1 ? 1 : lst); k < j; k ++)
          G[id(i, j)].push_back(id(i, k));
        lst = j;
      }
    }
  }

  for (int i = 1; i <= n; i ++) {
    int lst = -1;
    for (int j = m; j >= 1; j --) {
      if (g[i][j] == 3) {
        for (int k = (lst == -1 ? m : lst); k > j; k --)
          G[id(i, j)].push_back(id(i, k));
        lst = j;
      }
    }
  }

  for (int j = 1; j <= m; j ++) {
    int lst = -1;
    for (int i = 1; i <= n; i ++) {
      if (g[i][j] == 0) {
        for (int k = (lst == -1 ? 1 : lst); k < i; k ++)
          G[id(i, j)].push_back(id(k, j));
        lst = i;
      }
    }
  }

  for (int j = 1; j <= m; j ++) {
    int lst = -1;
    for (int i = n; i >= 1; i --) {
      if (g[i][j] == 2) {
        for (int k = (lst == -1 ? n : lst); k > i; k --)
          G[id(i, j)].push_back(id(k, j));
        lst = i;
      }
    }
  }

  vector<vector<int>> rev(N + 1);
  for (int u = 1; u <= N; u ++) {
    for (int v : G[u]) {
      rev[v].push_back(u);
    }
  }

  vector<int> indg(N + 1);
  for (int i = 1; i <= N; i ++) {
    indg[i] = G[i].size();
  }

  queue<int> q; 
  for (int i = 1; i <= N; i ++) {
    if (!indg[i]) {
      q.push(i);
    }
  }

  vector<int> topo, vis(N + 1);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    topo.push_back(v);
    vis[v] = 1;
    for (int u : rev[v]) {
      if (!--indg[u]) {
        q.push(u);
      }
    }
  }

  // Bitset DP（逆序）
  vector<bitset<50001>> dp(N + 1);
  for (int u : topo) {
    dp[u].set(u);
    for (int v : G[u]) {
      dp[u].set(v);
      dp[u] |= dp[v];
    }
  }

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      int idx = id(i, j);
      if (vis[idx])
        cout << dp[idx].count() << " ";
      else
        cout << -1 << " ";
      if (j == m) cout << "\n";
    }
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}