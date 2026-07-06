// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#else
#define dbug(...)
#endif

// REGISTER_REFLECT()

int gb(int num, int pos) { return (num >> pos) & 1; }

string bit(int x) {
  return bitset<10>(x).to_string();  //.substr(10 - __lg(x) - 1);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<array<int, 2>> seg = {{1, n}};

  auto dfs = [&](this auto&& dfs, int pos, bool tight,
                 const vector<array<int, 2>>& seg) -> int {
    if (pos < 0) {
      return 1;
    }

    int k_bit = (k >> pos) & 1;
    int lim = tight ? (k >> pos) & 1 : 1;
    /*
    2. 那为什么不能直接算低位所有组合？
    问题出在区间内部。
    当前位你发现所有区间内元素这一位全相同（all_same = true），区间不分裂，nxt
    和 seg 完全一样。 但是，这仅仅代表这一位没有产生新的约束。
    低位可能仍然存在某个区间内元素出现不同的位，从而在未来某一位分裂，并产生强制
    xb 必须为 0 或 1 的要求。 如果你这时直接返回
    2^{pos+1}，就相当于假设剩余低位所有组合都合法，忽略了低位可能隐藏的非法分支。*/

    bool all_same = true;
    for (auto [L, R] : seg) {
      int base = (a[L] >> pos) & 1;
      for (int i = L + 1; i <= R; i++) {
        if (gb(a[i], pos) != base) {
          all_same = false;
          break;
        }
      }
      if (!all_same) break;
    }

    if (all_same) {
      if (!tight) {
        return 2 * dfs(pos - 1, false, seg);
      } else {
        int k_bit = (k >> pos) & 1;
        if (k_bit == 1) {
          return dfs(pos - 1, false, seg) + dfs(pos - 1, true, seg);
        } else {
          return dfs(pos - 1, true, seg);
        }
      }
    }

    // if (all_same) {
    //   if (!tight) {
    //     return 1LL << (pos + 1);
    //   } else {
    //     return (k & ((1LL << (pos + 1)) - 1)) + 1;
    //   }
    // }

    int res = 0;
    for (int xb = 0; xb <= lim; xb++) {
      bool f = true;
      vector<array<int, 2>> nxt;
      for (const auto [L, R] : seg) {
        int i = L;
        while (i <= R) {
          int j = i, cur_bit = gb(a[i], pos);
          while (j + 1 <= R and gb(a[j + 1], pos) == cur_bit) {
            j++;
          }

          int prev_bit = gb(a[i - 1], pos);
          if (i > L and (cur_bit ^ xb) < (prev_bit ^ xb)) {
            f = false;
            break;
          }

          if (j - i) {
            nxt.push_back({i, j});
          }

          i = j + 1;
        }
      }

      if (!f) continue;
      res += dfs(pos - 1, tight and xb == k_bit, nxt);
    }

    return res;
  };

  // for (int i = 1; i <= n; i++) {
  //   cout << bit(a[i]) << "\n";
  // }

  cout << dfs(60, 1, seg) << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}