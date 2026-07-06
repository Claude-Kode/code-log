// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (std::min(a, b) > 1) 
    std::cout << "1\n";
  else if (2 * std::min(a, b) < std::max(a, b))
    std::cout << std::min(a, b) * 2 << "\n";
  else
    std::cout << a + b << "\n";
  // std::cout << a + b << "\n";

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