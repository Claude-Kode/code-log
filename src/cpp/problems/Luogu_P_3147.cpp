// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;
const int N = 262144 + 10;
const int M = 60;  // 40+18=58，取60保险



void solve() { 

  int n, ans = 0; cin >> n;
  vector<vector<int>> dp(M, vector<int>(N));
  for (int j = 1; j <= n; j ++) {
    int x; cin >> x;
    ans = max(ans, x);
    dp[x][j] = j + 1; 
  }
  
  for (int i = 1 ; i < M ; i ++) {
    for (int j = 1 ; j <= n ; j ++) {
      if (!dp[i][j]) {
        if (dp[i - 1][j] && dp[i - 1][dp[i - 1][j]]) {
          dp[i][j] = dp[i-1][dp[i-1][j]] ;
        }
      }
      if (dp[i][j]) ans = max(ans, i); 
    }
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


