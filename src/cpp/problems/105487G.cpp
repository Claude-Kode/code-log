// // // @Author : GoryK
// // #include <bits/stdc++.h>
// // using namespace std;

// // #define int int64_t

// // #ifdef LOCAL
// // #include "__DEBUG_TOOL.h"
// // #else
// // #define dbug(...)
// // #endif

// // // REGISTER_REFLECT()

// // void solve() {
// //   int n, k;
// //   cin >> n >> k;

// //   vector<int> a(n + 2, 0), b(64, -1), c(64, 0); ;
// //   for (int i = 1; i < n; i++) {
// //     cin >> a[i];
// //   }

// //   bool f = 1;
// //   const int g = 1;

// //   for (int i = 1; i < n; i++) {
// //     if (a[i] == a[i + 1]) continue;
// //     for (int j = 60; j >= 0; j--) {
// //       if (((g << j) & a[i]) == ((g << j) & a[i + 1])) {
// //         continue;
// //       }
// //       if (a[i] & (g << j)) {
// //         if (b[j] == -1)
// //           b[j] = 1;
// //         else if (b[j] == 0)
// //           f = 0;
// //       } else {
// //         if (b[j] == -1)
// //           b[j] = 0;
// //         else if (b[j] == 1)
// //           f = 0;
// //       }
// //       break;
// //     }
// //   }

// //   c[0] = 1;
// //   if (b[0] == -1) {
// //     c[0] = 2;
// //   }

// //   for (int i = 1; i <= 61; i++) {
// //     if (b[i] == -1)
// //       c[i] = c[i - 1] * 2;
// //     else
// //       c[i] = c[i - 1];
// //   }

// //   int sum = 0;
// //   for (int i = 0; i <= 61; i++) {
// //     if (b[i] == 1) {
// //       sum += (g << i);
// //     }
// //   }

// //   if (sum > k) {
// //     f = 0;
// //   }

// //   int ans = 0;
// //   for (int i = 61; i >= 0; i--) {
// //     if (b[i] == -1) {
// //       if (sum + (g << i) <= k) {
// //         if (i > 0)
// //           ans += c[i - 1];
// //         else
// //           ans += 1;
// //         sum += (g << i);
// //       }
// //     }
// //   }

// //   ans++;

// //   if (f == 0) {
// //     ans = 0;
// //   }
// //   cout << ans << "\n";
// // }

// // int32_t main() {
// //   std::ios::sync_with_stdio(false);
// //   std::cin.tie(nullptr);
// //   std::cout.tie(nullptr);

// //   int tt = 1, _ = 0;
// //   std::cin >> tt;
// //   while (tt-- && ++_)
// //     // std::cout << "TEST CASE : " << _ << endl,
// //     solve();

// //   return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll dp[64];  // 记忆化数组，只用于 is_tight = false 时
// ll k;
// ll fixed_mask, fixed_val;

// ll dfs(int pos, bool is_tight) {
//   if (pos < 0) return 1;
//   if (!is_tight && dp[pos] != -1) return dp[pos];

//   ll res = 0;
//   int limit = is_tight ? ((k >> pos) & 1) : 1;

//   if ((fixed_mask >> pos) & 1) {
//     int req = (fixed_val >> pos) & 1;
//     if (req <= limit) res += dfs(pos - 1, is_tight && (req == limit));
//   } else {
//     for (int bit = 0; bit <= limit; ++bit) {
//       res += dfs(pos - 1, is_tight && (bit == limit));
//     }
//   }

//   if (!is_tight) dp[pos] = res;
//   return res;
// }

// void solve() {
//   int T;
//   cin >> T;
//   while (T--) {
//     int n;
//     cin >> n >> k;
//     vector<ll> a(n);
//     for (auto& x : a) cin >> x;

//     fixed_mask = fixed_val = 0;
//     bool ok = true;

//     for (int i = 0; i + 1 < n; ++i) {
//       ll x = a[i], y = a[i + 1];
//       if (x == y) continue;
//       ll diff = x ^ y;
//       int pos = 63 - __builtin_clzll(diff);  // 最高不同位
//       int bit_x = (x >> pos) & 1;
//       int req = (bit_x == 0) ? 0 : 1;  // 要求 x_pos = req

//       if ((fixed_mask >> pos) & 1) {
//         if (((fixed_val >> pos) & 1) != req) {
//           ok = false;
//           break;
//         }
//       } else {
//         fixed_mask |= (1ULL << pos);
//         if (req) fixed_val |= (1ULL << pos);
//       }
//     }

//     if (!ok) {
//       cout << 0 << '\n';
//       continue;
//     }

//     memset(dp, -1, sizeof(dp));
//     cout << dfs(61, true) << '\n';  // 从 61 位开始，足够覆盖 1e18
//   }
// }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   solve();
//   return 0;
// }

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

  auto dfs = [&](this auto&& dfs, int pos, bool tight, const vector<array<int, 2>>& seg) -> int {
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
