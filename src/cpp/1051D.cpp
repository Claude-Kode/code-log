// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 998'244'353; 
const int N = 2e5 + 10;

void solve() { 
  int n, k; cin >> n >> k;
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(4, 0)));
  
  if(k >= 1) {
    dp[1][1][1] = 1;  
    dp[1][1][2] = 1; 
  }
  if(k >= 2) {
    dp[1][2][0] = 1; 
    dp[1][2][3] = 1; 
  }
  
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= k; j++) {  
      dp[i][j][0] = (dp[i-1][j][0] + 
                    (j >= 1 ? dp[i - 1][j - 1][1] : 0) + 
                    (j >= 1 ? dp[i - 1][j - 1][2] : 0) + 
                    (j >= 2 ? dp[i - 1][j - 2][3] : 0)) % mod;
      dp[i][j][1] = (dp[i - 1][j][0] + 
                    dp[i - 1][j][1] + 
                    (j >= 1 ? dp[i - 1][j - 1][2] : 0) + 
                    dp[i - 1][j][3]) % mod;
      dp[i][j][2] = (dp[i - 1][j][0] + 
                    (j >= 1 ? dp[i - 1][j - 1][1] : 0) + 
                    dp[i - 1][j][2] + 
                    dp[i - 1][j][3]) % mod;
      dp[i][j][3] = ((j >= 2 ? dp[i - 1][j - 2][0] : 0) + 
                    (j >= 1 ? dp[i - 1][j - 1][1] : 0) + 
                    (j >= 1 ? dp[i - 1][j - 1][2] : 0) + 
                    dp[i - 1][j][3]) % mod;
    }
  }
    
  int ans = 0;
  for(int s = 0; s < 4; s ++) {
    ans = (ans + dp[n][k][s]) % mod;
  }
  cout << ans << endl; 
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

