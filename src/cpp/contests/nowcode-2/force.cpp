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
  for (int i = 1; i <= 100; i ++) {
    for (int j = i + 1; j <= 100; j ++) {
      bool f = false;
      if(__gcd(i,j)==1)continue;
      for (int k = i+1; k <= j-1; k ++) {
        if (__gcd(k, j) == 1 and __gcd(i, k) == 1) f = true;
      }
      if (!f) {
        cout << i << ' ' << j << ' '  << "\n";
        return;
      }
    }
  }
  // int l, r, n;
  // cin >> l >> r >> n;
  // int ans = r - l + 1;
  // for (int i = l; i <= r; i ++) {
  //   ans += (__gcd(i, n) != 1);
  // }

  // cout << ans << "\n";
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