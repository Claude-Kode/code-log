// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

// #define int int64_t

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#else
#define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> nxt(n, 0);

  {
    int j = 0;
    for (int i = 1; i < n; i++) {
      while (j and s[i] != s[j]) {
        j = nxt[j - 1];
      }
      j += (s[i] == s[j]);
      nxt[i] = j;
    }
  }

  vector<vector<int>> jump(__lg(n) + 1, vector<int>(n, 0));
  for (int i = 1; i < n; i++) {
    jump[0][i] = nxt[i - 1];
  }

  for (int i = 1; i <= __lg(n); i++) {
    for (int j = 0; j < n; j++) {
      jump[i][j] = jump[i - 1][jump[i - 1][j]];
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!nxt[i]) continue;
    int sho = nxt[i];
    for (int idx = __lg(n); idx >= 0; idx--) {
      if (jump[idx][sho]) {
        sho = jump[idx][sho];
      }
    }

    ans += i - sho + 1;
  }

  cout << ans << "\n";
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

// nxt = [0, 0, 1, 2, 3, 4, 5, 6]
// jump =
// [[0, 0, 0, 1, 2, 3, 4, 5],
// [0, 0, 0, 0, 0, 1, 2, 3],
// [0, 0, 0, 0, 0, 0, 0, 0],
// [0, 0, 0, 0, 0, 0, 0, 0]]

#include <string>
#include <vector>

// 假设已经通过 KMP 得到 nxt 数组（长度 n，0-indexed）
// nxt[i] 表示前缀 s[0..i] 的最长 border 长度

std::vector<int> get_shortest_border(const std::vector<int>& nxt) {
  int n = nxt.size();
  std::vector<int> short_border(n, 0);  // 结果：每个前缀的最短非零 border 长度
  std::vector<int> shortest_len(n + 1, 0);  // 辅助：长度为 x 的字符串，其最短非零 border 长度

  // DP 计算 shortest_len[x]（x 从 1 到 n）
  // 在失配树中，节点 x 的父节点是 nxt[x-1]，求深度为 1 的祖先
  for (int x = 1; x <= n; x ++) {
    int p = nxt[x - 1];  // 最长 border 长度
    if (p == 0)
      shortest_len[x] = x;  // 父节点是 0，自己就是最短非零 border
    else
      shortest_len[x] = shortest_len[p];  // 继承父节点的最短 border
  }

  // 对于每个前缀 i，若存在 border，查 shortest_len 表
  for (int i = 0; i < n; i ++) {
    int border = nxt[i];
    if (border != 0) short_border[i] = shortest_len[border];
    // 若 border == 0，short_border[i] 保持为 0（无 border）
  }

  return short_border;  // short_border[i] 即 s[0..i] 的最短非零 border 长度
}