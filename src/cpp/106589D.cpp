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
  int n, m;
  cin >> n >> m;
  if (m > n || m < 0) {
    cout << "NO" << "\n";
    return; 
  } else {
    cout << "YES" << "\n";
  }

  vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
  for (int c = m - 1; c > 0; c --) {
    int i = m - c;
    for (int j = 1; j <= c; j ++) ans[i][j] = 1;
  }

  if (m == 0) {
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= n; j ++) {
        ans[i][j] = 1;
      }
    }
  }

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n; j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
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