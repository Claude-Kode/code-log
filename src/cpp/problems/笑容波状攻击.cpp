// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  std::string s; 
  std::cin >> s;
  int ans = 0;
  int p0 = 0, p1 = 0;
  int n = s.size(); s = " " + s;
  for (int i = 1; i <= n; i ++) {
    if (s[i] == '0') {
      ans += (i - p1) + p1 * 2;
      p0 = i;
    } else {
      ans += p0 * 2;
      p1 = i;
    }
  }

  std::cout << ans << "\n";
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