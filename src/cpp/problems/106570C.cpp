// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #define int int64_t

// #ifdef LOCAL
//   #include "__DEBUG_TOOL.h"
// #else
//   #define dbug(...)
// #endif

// // REGISTER_REFLECT()

// void solve() {
//   int n, m, k;
//   cin >> n >> m >> k;
//   // dbug(n, m, k);
//   vector<unordered_map<int, int>> rev(n + 1);
//   for (int i = 1; i <= n; i ++) {
//     int c; cin >> c;
//     for (int j = 1; j <= c; j ++) {
//       int temp; cin >> temp;
//       // dbug(temp);
//       rev[i][temp] = 1;
//     }
//   }

//   vector<int> vec(m + 1);
//   for (int i = 1; i <= m; i ++) {
//     cin >> vec[i];
//   }

//   // dbug(vec);

//   vector<unordered_map<int, array<int, 2>>> dp(m + 1);

//   for (auto& [i, _] : rev[vec[1]]) {
//     dp[1][i][1] = 1;
//     dp[1][i][0] = 1;
//   }

//   // 如果 rev[j][vec[i]] 且 rev[j][vec[i - 1] 就延续上一个 而且下次能接着用
//   // 如果 !rev[j][vec[i]] 而且 !rev[vec[i]][j] j 可以和 vec[i] 同归于尽
//   // 如果

//   int mn = 1;
//   for (int i = 2; i <= m; i ++) {
//     int cur = vec[i], pre = vec[i - 1];
//     for (auto& [j, _] : rev[cur]) {
//       if (rev[vec[i - 1]][j]) {
//         dp[i][j][1] = dp[i - 1][j][1];
//       } else {
//         dp[i][j][1] = mn + 1;
//       }
//     }

//     for (auto& [j, _] : rev[pre]) {
//       if (!rev[cur][j]) {
//         dp[i][j][0] = dp[i - 1][j][1];
//       }
//       // 战败
//       // if (rev[j][cur]) {
//       //   dp[i][j][1] = mn + 1;
//       // }
//     }

//     for (auto& [k, v] : dp[i]) {
//       if (v[0]) mn = min(mn, v[0]);
//       if (v[1]) mn = min(mn, v[1]);
//     }
//   }

//   int ans = INT_MAX;
//   for (const auto & [k, v] : dp[m]) {
//     if (v[0]) ans = min(ans, v[0]);
//     if (v[1]) ans = min(ans, v[1]);
//   }

//   // dbug(dp);

//   cout << ans << '\n';
// }

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);

//   int tt = 1, _ = 0;
//   // std::cin >> tt;
//   while (tt-- && ++_)
//     // std::cout << "TEST CASE : " << _ << endl,
//     solve();

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  // g[i] 存储所有克制 i 的精灵
  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= n; ++i) {
    int sz;
    cin >> sz;
    g[i].resize(sz);
    for (int j = 0; j < sz; ++j) cin >> g[i][j];
    sort(g[i].begin(), g[i].end());  // 便于二分查找
  }

  vector<int> a(m + 1);
  for (int i = 1; i <= m; ++i) cin >> a[i];

  const int INF = 1e12;
  int empty_cost = 0;             // 空手最小花费
  unordered_map<int, int> alive;  // 存活精灵 -> 最小花费

  for (int i = 1; i <= m; ++i) {
    int B = a[i];
    int next_empty = INF;
    unordered_map<int, int> next_alive;

    // 1. 当前有精灵存活的情况
    for (auto& [X, cost] : alive) {
      // X 是否能赢 B
      if (binary_search(g[B].begin(), g[B].end(), X)) {
        // 获胜，继续存活
        int& nxt = next_alive[X];
        nxt = min(nxt, cost);
      } else {
        // X 不能赢 B，判断 B 是否赢 X
        if (binary_search(g[X].begin(), g[X].end(), B)) {
          // B 克制 X -> 战败，X死，B活
          // 我们可以立即在同一个 B 上从空手状态继续
          // （相当于用 cost 作为新的 empty_cost 来处理当前 B）
          // 这里直接更新 empty_cost，因为还没打赢 B
          empty_cost = min(empty_cost, cost);
        } else {
          // 互不克制 -> 同归于尽，B死
          next_empty = min(next_empty, cost);
        }
      }
    }

    // 2. 从空手状态派出新精灵
    // 同归于尽选项：派 B 自己
    next_empty = min(next_empty, empty_cost + 1);

    // 派出能克制 B 的精灵
    for (int X : g[B]) {
      next_alive[X] = min(next_alive[X], empty_cost + 1);
    }

    // 注意：如果存在战败，empty_cost 已经被更新，
    // 我们需要再次用新的 empty_cost 考虑同归于尽和派出克制者
    // 但刚刚的 next_empty / next_alive 是基于旧的 empty_cost 计算的。
    // 为了简洁，可以循环两次，或者把“从空手派出”这一步放入一个小循环。
    // 因为最多 k≤30，重复一次不影响复杂度。
    // 第二次处理用更新后的 empty_cost：
    next_empty = min(next_empty, empty_cost + 1);
    for (int X : g[B]) {
      next_alive[X] = min(next_alive[X], empty_cost + 1);
    }

    empty_cost = next_empty;
    alive = move(next_alive);
  }

  int ans = empty_cost;
  for (auto& [X, c] : alive) ans = min(ans, c);
  cout << ans << '\n';
}

int32_t main() { 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}