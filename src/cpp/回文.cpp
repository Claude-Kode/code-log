// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int n;
  std::string s; 
  std::cin >> n >> s;
  s = " " + s;
  int l = 1, r = n;
  bool used = false;
  while (l <= r) {
    if (s[l] == s[r]) {
      l ++, r --;
    } else {
      if (used) {
        std::cout << "No" << "\n"; 
        return;
      }
      used = true;
      if (s[r] == s[l + 1]) l ++;
      else if (s[l] == s[r - 1]) r --;
      else {
        std::cout << "No" << "\n"; 
        return;
      }
    }
  }

  std::cout << "Yes" << "\n";
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