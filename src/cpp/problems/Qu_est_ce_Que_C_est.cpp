// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 998244353; 
const int N = 2e5 + 10;

int n, m; 
int to(int c) {return c + m + 1;}

void solve() { 
  cin >> n >> m;
  vector<vector<int>> dp(n + 1, vector<int>(2 * m + 2, 0)),  pre(n + 1, vector<int>(2 * m + 2, 0));


  for(int i = 0 ; i <= to(m); i ++) dp[1][i] = 1;
  for(int i = 2; i <= n; i ++) {
    for(int j = -m; j <= m; j ++) {
      int a = to(min(m, m - j)), b = to(max(0LL, j - m) - 1);
      int jj = to(j);
      int plus = pre[i - 1][a] - pre[i - 1][b];
      dp[i][jj] = (dp[i][jj]  % mod + plus % mod) % mod;
      pre[i][jj] = pre[i][jj - 1]+ dp[i][jj];
    }
  }

  int ans = 0;
  for(int j = 0; j <= m; j ++) ans = (ans + dp[n][j]) % mod;

  cout << ans << endl;
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}