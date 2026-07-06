// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int n; std::string s; 
  std::cin >> n >> s;
  s = " " + s;
  int a = 0, b = 0, c = 0;
  for (int i = 1; i <= n; i ++) {
    if (s[i] == 'L') a ++;
    else if (s[i] == 'Y') {
      b += a;
    } else if (s[i] == 'U') {
      c += b;
    }
    // cout << "infor : " << a << ' ' << b << ' ' << c << '\n';
  }

  std::cout << c << " \n"; 
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