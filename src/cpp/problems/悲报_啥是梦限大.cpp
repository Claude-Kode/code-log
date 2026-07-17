#pragma GCC optimize("Ofast, fast-math")
#pragma GCCtarget("avx, avx2")
// #pragma GCC optimize("O3,unroll-loops")
// @Author : GoryK
#include <bits/stdc++.h>

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int n, mx = 0; 
  std::cin >> n;
  std::vector<int> vec(n + 1), buc(n + 1, 0), ans(n + 1, 0);
  for (int i = 1; i <= n; i ++) {
    std::cin >> vec[i];
    for (int j = vec[i]; j <= mx; j ++) {
      ans[j  - vec[i]] += buc[j];
    }
    buc[vec[i]] ++;
    mx = std::max(mx, vec[i]);
  }

  for (int i = 0; i <= n; i ++) {
    std::cout << ans[i] << " \n"[i == n];
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
