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

void solve() {
  int n, C; cin >> n >> C;
  vector<array<int, 3>> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
  } 

  vector<int> dp(C + 1);

  // 要用 old 来保证每次 + cnt * v 的 cnt 的大小一定在 c 以内
  // 维护 old_t + (j - t) / w * r, 
  // 变换成 old_t + (j - r) / w * v - (t - r) / w * v
  // 然后对于当前的每一个 j 来说, (j - r) / w * v 是一个常数
  // 维护 old_t - (t - r) / w * v 的单调队列即可
  // 注意更新的时候别忘了用 old 更新
  // 公式变形 + 常数分析

  for (int i = 1; i <= n; i ++) {
    auto [v, w, c] = vec[i];
    auto old = dp;
    for (int r = 0; r < w; r ++) {
      auto dq = deque<int>();
      for (int j = r; j <= C; j += w) {
        while (dq.size() and dq.front() < j - c * w) {
          dq.pop_front();
        }

        int base = old[j] - (j - r) / w * v;
        while (dq.size() and base >= old[dq.back()] - ((dq.back() - r) / w * v)) {
          dq.pop_back();
        }
        dq.push_back(j);

        int t = dq.front(), cnt = (j - t) / w; 
        dp[j] = max(dp[j], old[t] + cnt * v); 
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= C; i ++) {
    ans = max(ans, dp[i]);
  }

  cout << ans << "\n";
}   

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}
 
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
//   int n, C; cin >> n >> C;
//   vector<array<int, 3>> vec(n + 1);
//   for (int i = 1; i <= n; i ++) {
//     cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
//   } 

//   vector<int> dp(C + 1);
//   for (int i = 1; i <= n; i ++) {
//     auto [v, w, c] = vec[i];
//     int s = 1;
//     while (c) {
//       int ww = s * w, vv = s * v;
//       for (int j = C - ww; j >= 0; j --) {
//         int jj = j + ww;
//         dp[jj] = max(dp[jj], dp[j] + vv);
//       }
//       c -= s;
//       s = min(s << 1, c);
//     }
//   }

//   int ans = 0;
//   for (int i = 1; i <= C; i ++) {
//     ans = max(ans, dp[i]);
//   }

//   cout << ans << "\n";
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