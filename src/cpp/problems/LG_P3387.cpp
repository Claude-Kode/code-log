// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define ckmn(x, y)          \
  do {                      \
    auto _v = (y);          \
    if (_v < (x)) (x) = _v; \
  } while (0)
#define ckmx(x, y)          \
  do {                      \
    auto _v = (y);          \
    if (_v > (x)) (x) = _v; \
  } while (0)

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#else
#define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  // 缩点, 就是把一张有向有环图中的环缩成一个个点, 形成一个有向无环图
  int timer = 0, scc_cnt = 0;
  vector<int> low(n + 1), dfn(n + 1), instk(n + 1), scc(n + 1), stk;
  // low, dfn 是 点编号 -> 时间戳
  // 剩下的都是点编号的意义
  auto tarjan = [&](auto&& sef, int u) -> void {
    dfn[u] = low[u] = ++timer;
    stk.push_back(u);
    instk[u] = true;

    for (int& v : g[u]) {
      if (dfn[v] == 0) {
        sef(sef, v);
        low[u] = std::min(low[u], low[v]);
      } else if (instk[v]) {
        low[u] = std::min(low[u], dfn[v]);
      }
    }

    if (low[u] == dfn[u]) {
      ++scc_cnt;
      // 这里 如果栈里面只有 u 自己一个, 直接
      int v = 0;
      do {
        v = stk.back();
        stk.pop_back();
        scc[v] = scc_cnt;
        instk[v] = false;
      } while (v != u);
    }
  };

  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(tarjan, i);
    }
  }

  vector<int> ans(scc_cnt + 1, 0);
  for (int i = 1; i <= n; i++) {
    ans[scc[i]] += a[i];
  }

  vector<vector<int>> dag(scc_cnt + 1);
  for (int u = 1; u <= n; u++) {
    for (int v : g[u]) {
      if (scc[u] != scc[v]) dag[scc[u]].push_back(scc[v]);
    }
  }

  vector<int> dp(scc_cnt + 1);
  dp = ans;  
  for (int u = scc_cnt; u >= 1; u--) {
    for (int v : dag[u]) {
      dp[v] = std::max(dp[v], dp[u] + ans[v]);
    }
  }

  cout << ranges::max(dp);
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}