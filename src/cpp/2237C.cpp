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
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  int pre = 0;
  for (int i = 1; i <= n; i ++) {
    if (vec[i] >= pre) {
      pre = vec[i];
    } else {
      pre += vec[i];
    }
  }

  cout << pre << "\n";
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

//   int mx = 0;
//   for (int i = 1; i <= n; i ++) {
//     cin >> vec[i];
//     mx = max(mx, vec[i]);
//   }

//   auto suf = vec;
//   for (int i = n - 1; i > 0; i --) {
//     suf[i] += suf[i + 1];
//   }
//   suf.push_back(0);

//   vector<int> seq(n + 1);
//   iota(seq.begin(), seq.end(), 0LL);
//   sort(seq.begin() + 1, seq.end(), [&](int& a, int &b) {
//     return vec[seq[a]] < vec[seq[b]];
//   });

//   map<int, int> idx;
//   set<int> s(vec.begin() + 1, vec.end());
//   for (int i = 1; i <= n; i ++) {
    
//   }
//   // dbug(vec);

//   int ans = LLONG_MAX;
//   int back = vec.back(), pre = 0;
//   for (int i = 1; i <= n; i ++) {
//     // if (vec[i] == vec[seq[i]]) continue;
//     int t = vec[i] + suf[i + 1];
//     if (t >= pre - vec[i]) {
//       ans = min(ans, t);
//     }
//     dbug(i, pre, t, ans, " ");
//     pre = max(pre, t);
//   }

//   cout << max(mx, (ans == LLONG_MAX ? -1 : ans)) << "\n";
// } 
// // 就是有人移动到最大的位置以后, 别人不能比他更大就是这样差不多
// // 枚举那个最大, 不行的就那个掉, 在可行的里面取最小值
// // 那要是 n-1 确定了 n-2 又有怎么办

// // 差不多, 但是 checker 要更加严格一些, 就是要检验每个数字到自己的应有位置上是多少
// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
  
//   int tt = 1, _ = 0;
//   std::cin >> tt;
//   while (tt-- && ++_)
//     std::cout << "TEST CASE : " << _ << endl,
//     solve();

//   return 0;
// }