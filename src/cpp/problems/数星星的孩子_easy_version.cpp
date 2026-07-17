#ifdef __GNUC__
// #pragma GCC optimize("fast-math") 
#pragma GCC optimize("Ofast, unroll-loops = full")
#pragma GCCtarget("avx, avx2")
#endif
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
  int n; cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  int ans = 0;
  for (int i = 1; i < n; i ++) {
    for (int j = i + 1; j <= n; j ++) {
      int temp = __builtin_popcount(vec[i] ^ vec[j]);
      ans += temp * temp;
    }
  }

  cout << ans << "\n";
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