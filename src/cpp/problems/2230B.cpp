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
//   string s; cin >> s;
//   int ans = count(s.begin(), s.end(), '4');
//   bool f = false;
//   int res1 = 0, res2 = 0;
//   int n = s.size();
//   {
//     bool f = false;
//     for (int i = 0; i < n; i ++) {
//       f |= (s[i] == '1' or s[i] == '3');
//       res1 += (f and s[i] == '2');
//     }
//   }

//   {
//     bool f = false;
//     for (int i = n - 1; i >= 0; i --) {
//       f |= (s[i] == '2');
//       res2 += (f and (s[i] == '1' or s[i] == '3'));
//     }
//   }

//   cout << ans + min(res1, res2) << "\n";
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
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  int ans1 = (n + x + y - 1) / (x + y);
  int ans2 = z + (n - z * x + x + 10 * y - 1) / (x + 10 * y);
  cout << min(ans1, ans2) << "\n";
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