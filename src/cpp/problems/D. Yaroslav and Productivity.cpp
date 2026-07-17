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
  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  map<int, int> mp;
  for (int i = 1; i <= m; i ++) {
    cin >> b[i];
    mp[b[i]] = 1;
  }

  auto pre = a;
  for (int i = 1; i <= n; i ++) {
    pre[i] += pre[i - 1];
  }

  vector<array<int, 2>> dp(n + 1, {0, 0});
  int lst = 0;
  for (int i = 1; i <= n; i ++) {
    // mn, mx
    dp[i][0] = INT_MAX; dp[i][1] = INT_MIN;
    dp[i][0] = dp[i - 1][0] + a[i];
    dp[i][1] = dp[i - 1][1] + a[i];
    if (!mp[i]) {
    } else {
      int sum = pre[i] - pre[lst];
      dp[i][0] = min({dp[i][0], sum + dp[lst][0], - sum - dp[lst][1], sum + dp[lst][1], - sum - dp[lst][0]});
      dp[i][1] = max({dp[i][1], sum + dp[lst][1], - sum - dp[lst][0], sum + dp[lst][0], - sum - dp[lst][1]});
      lst = i;
    }  
  } 

  // dbug(dp);

  cout << dp[n][1] << "\n";
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}