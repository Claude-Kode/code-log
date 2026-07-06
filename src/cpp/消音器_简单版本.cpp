// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int n, m; 
  std::cin >> n >> m;
  // std::string s; 
  // std::cin >> s;
  // s = " " + s;
  for (int i = 1; i <= n; i ++) {
    for (int j = 0; j < m; j ++) {
      cout << j;
    } 
  }
  cout << "\n";
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