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
//   int n; cin >> n;
//   vector<int> vec(n + 1);
//   for (int i = 1; i <= n; i ++) {
//     cin >> vec[i];
//   }

//   vector<int> ans(n + 1);
//   ans[1] = vec[1];
//   int rem = 0;
//   for (int i = 2; i <= n; i ++) {
//     if (vec[i] >= ans[i - 1]) {
//       ans[i] = ans[i - 1];
//       rem += vec[i] - ans[i - 1];
//     } else if (vec[i] + rem >= ans[i - 1]) {
//       rem -= ans[i - 1] - vec[i];
//       ans[i] = ans[i - 1];
//     } else {  
//       int l = vec[i], r = ans[i - 1], res = l;
//       while (l <= r) {
//         int mid = (l + r) >> 1;
//         if (vec[i] + rem + (i - 1) * (ans[i - 1] - mid) >= mid) {
//           // cout << "mid: " << mid << ' ' << "std: " << vec[i] + rem + (i - 1) * (ans[i - 1] - mid) << " \n";
//           l = mid + 1;
//           res = mid;
//         } else {  
//           r = mid - 1;
//         }
//       }
//       dbug(l);
//       dbug(r);
//       dbug(res);
//       rem += (i - 1) * (ans[i - 1] - res) - (res - vec[i]);
//       ans[i] = res;   
//     }
//   }

//   for (int i = 1; i <= n; i ++) {
//     cout << ans[i] << " \n"[i == n];
//   }
// } 

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
  
//   int tt = 1, _ = 0;
//   std::cin >> tt;
//   while (tt-- && ++_)
//     // std::cout << "TEST CASE : " << _ << endl,
//     solve();

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

void solve() {
  int n; cin >> n;
  vector<int> vec(n + 1);
  int s = 0, ans = INT_MAX;
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
    s += vec[i];
    ans = min(ans, s / i);
    cout << ans << " \n"[i == n];
  }
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