// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int a, b; 
  std::cin >> a >> b;
  if (__gcd(a, b) > 1) {
    std::cout << 0 << '\n';
  } else if (std::gcd(a + 1, b) > 1 || std::__gcd(a, b + 1) > 1){
    std::cout << 1 << "\n";
  } else {
    std::cout << 2 << "\n";
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