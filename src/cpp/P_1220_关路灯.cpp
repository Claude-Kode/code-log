// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'
#define INT_MAX LLONG_MAX / 2

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;


void solve() { 

  int n, s; cin >> n >> s;
  vector<int> dis(n + 1), w(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> dis[i] >> w[i];
    w[i] += w[i - 1];
  } 

  vector<vector<vector<int>>> dp(n + 1, 
  vector<vector<int>> (n + 1, 
  vector<int>(2 , INT_MAX)));
  dp[s][s][0] = dp[s][s][1] = 0;

  for(int len = 2; len <= n; len ++) {
    for(int l = 1; l <= n - len + 1; l ++) {int r = l + len - 1;
      dp[l][r][1] = min({
        dp[l][r][1], 
        dp[l][r - 1][0] + (dis[r] - dis[l]) * (w[n] - w[r - 1] + w[l - 1]),
        dp[l][r - 1][1] + (dis[r] - dis[r - 1]) * (w[n] - w[r - 1] + w[l - 1])
      });
      dp[l][r][0] = min({
        dp[l][r][0],
        dp[l + 1][r][0] + (dis[l + 1] - dis[l]) * (w[n] - w[r] + w[l]),
        dp[l + 1][r][1] + (dis[r] - dis[l]) * (w[n] - w[r] + w[l])
      });
    }
  }

  // std::function <int(int, int, int)> dfs = [&](int l, int r, int d) -> int {
  //   int &res = dp[l][r][d];
  //   if (l == r) return res = (l == s ? 0 : INT_MAX - 1);
  //   if (res != INT_MAX) return INT_MAX; 

  //   if (d == 1) {
  //     res = min({res, 
  //       dfs(l, r - 1, 0) + (dis[r] - dis[l]) * (w[n] - w[r - 1] + w[l - 1]),
  //       dfs(l, r - 1, 1) + (dis[r] - dis[r - 1]) * (w[n] - w[r - 1] + w[l - 1])
  //     });
  //   } 
  //   else {
  //     res = min({res,
  //       dfs(l + 1, r, 0) + (dis[l + 1] - dis[l]) * (w[n] - w[r] + w[l]),
  //       dfs(l + 1, r, 1) + (dis[r] - dis[l]) * (w[n] - w[r] + w[l])
  //     });
  //   }

  //   // cout << l << ' ' << r << ' ' << res << endl; 
  //   return res;
  // };

  std::cout << min(dp[1][n][1], dp[1][n][0]) << endl; 
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}