// @Author : GoryK
#include <bits/stdc++.h>

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int n, m; std::cin >> n >> m;
  if (std::min(n, m) >= 4) 
    std::cout << n * m - 8 << '\n';
  else if (std::min(n, m) == 1) 
    std::cout << 0 << '\n';
  else 
    std::cout << n * m - 2 * std::min(n, m) << '\n';
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);  
  std::cout.tie(nullptr);

  int tt = 1, C = 0; 
  std::cin >> tt;
  while (tt-- && ++C)
    // std::cout << "TEST CASE : " << C << endl,
    solve();

  return 0;
}