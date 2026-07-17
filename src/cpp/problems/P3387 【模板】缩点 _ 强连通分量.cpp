// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define ckmn(x, y) do { auto _v = (y); if (_v < (x)) (x) = _v; } while(0)
#define ckmx(x, y) do { auto _v = (y); if (_v > (x)) (x) = _v; } while(0)

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

  int timer = 0, scc_cnt = 0;
  vector<int> low(n + 1), dfn(n + 1), instk(n + 1), scc(n + 1), stk;
  // low, dfn 是 点编号 -> 时间戳
  // 剩下的都是点编号的意义
  auto tarjan = [&](this auto&& tarjan, int u) -> void {
    dfn[u] = low[u] = ++timer;
    stk.push_back(u);
    instk[u] = true;

    for (int& v : g[u]) {
      if (dfn[v] == 0) {
        tarjan(v);
        ckmn(low[u], low[v]);
      } else if (instk[v]) {
        ckmn(low[u], dfn[v]);
      }
    } 

    if (low[u] == dfn[u] and ++scc_cnt) {
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

  for (int i = 1; i <= n; i ++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }

  vector<int> ans(scc_cnt + 1, 0);
  for (int i = 1; i <= n; i ++) {
    ans[scc[i]] += a[i];
  }

  cout << ranges::max(ans);

// 1. 建 DAG
// 你已经知道每个点属于哪个 SCC（scc[i]）。现在把原图的边"重定向"到 SCC 之间：
// // 读图时顺便把边存起来（你现在的代码只是 g[u].push_back(v)，边信息读后就丢了）
// vector<pair<int,int>> edges;    // 加这行
// for (int i = 1; i <= m; i++) {
//     int u, v;
//     cin >> u >> v;
//     g[u].push_back(v);
//     edges.push_back({u, v});    // 加这行
// }

// // tarjan 之后，建 DAG
// vector<vector<int>> dag(scc_cnt + 1);
// for (auto [u, v] : edges) {
//     int x = scc[u], y = scc[v];
//     if (x != y)
//         dag[x].push_back(y);
// }

// 去重（同一个 SCC 之间可能有多条原边，不处理会多跑 DP）
// // ... 见下
// 直观理解：原图的一条边 u→v，如果 u 和 v 缩进不同 SCC，那就变成 SCC(u) → SCC(v)。如果缩进同一个 SCC，这条边就是 SCC 内部的环边，DAG 上不出现在。
// 2. DAG 上 DP
// 这一步的关键是用拓扑序做 DP。Tarjan 的 scc_cnt 编号有一个天然性质：编号大的 SCC 在拓扑序上排在前面。
// 回忆代码：根 u 发现 low[u]==dfn[u] 时，把栈顶到 u 的所有点弹出来，标记为新的 scc_cnt。因为是 DFS 回溯时从叶子往根弹，所以叶子 SCC 编号小，靠近源的 SCC 编号大。
// 这意味着：从 scc_cnt 往 1 遍历，就是 DAG 的拓扑序。
// vector<int> dp(scc_cnt + 1, 0);

// // sum[x] = SCC x 内所有点的权值和（你代码里的 ans[x]）
// // 按逆拓扑序（scc_cnt → 1）DP
// for (int x = scc_cnt; x >= 1; x--) {
//     dp[x] += sum[x];                          // 自己点权和
//     for (int y : dag[x])
//         ckmx(dp[y], dp[x]);                   // 推给邻居
// }
// 或者等价地，正拓扑序拉式 DP：
// vector<int> dp = sum;    // 初始化为各自的 sum
// for (int x = scc_cnt; x >= 1; x--) {
//     for (int y : dag[x])
//         ckmx(dp[y], dp[x] + sum[y]);
// }

// cout << ranges::max(dp);
// 完整改动点（你现有代码上改 3 处）
// ① 读图时存边：edges.push_back({u, v});
// ② tarjan 之后建 dag + 去重：
// vector<vector<int>> dag(scc_cnt + 1);
// for (auto [u, v] : edges) {
//     int x = scc[u], y = scc[v];
//     if (x != y) dag[x].push_back(y);
// }
// // 去重：每个点的邻接表 sort + unique
// for (int i = 1; i <= scc_cnt; i++) {
//     sort(dag[i].begin(), dag[i].end());
//     dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
// }
// ③ DP 替掉 cout << ranges::max(ans)：
// vector<int> dp = ans;   // ans 是你原来算的每个 SCC 的 sum
// for (int x = scc_cnt; x >= 1; x--)
//     for (int y : dag[x])
//         ckmx(dp[y], dp[x] + ans[y]);

// cout << ranges::max(dp);
// }

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