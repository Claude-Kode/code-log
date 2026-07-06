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
  vector<array<int, 2>> vec(m + 1);
  for (int i = 1; i <= m; i ++) {
    cin >> vec[i][0] >> vec[i][1];
  }

  vector<int> dp(n + 1, 0);
  int mx = 0;
  for (int i = 1; i <= m; i ++) {
    for (int j = n - vec[i][0]; j >= 0; j --) {
      // dbug(j);
      // if (dp[j]) {
        dp[j + vec[i][0]] = max(dp[j + vec[i][0]], dp[j] + vec[i][1]);
      // }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i ++) {
    ans = max(ans, dp[i]);
  }

  cout << ans << "\n";
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