// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, m; cin >> n >>m ;
  vector<vector<int>> vec(n + 1, vector<int>(m + 1));
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      cin >> vec[i][j];
    }  
  }

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
  for(int i = 0; i <= m; i ++) dp[0][i] = 0;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++){
      dp[i][j] = max(dp[i - 1][j - 1] + vec[i][j], dp[i][j - 1]);
    }
  }

  // for(int i = 1; i <= n;  i++ ) {
  //   for(int j = 1; j <= m; j ++) {
  //     cout << dp[i][j] << ' ';
  //   }cout << endl; 
  // }

  cout << dp[n][m] << endl; 
  stack<int> ans; int lst = m;
  for(int i = n; i > 0; i --) {
    for(int j = lst; j > 0; j --) if (dp[i][j] - vec[i][j] == dp[i - 1][j - 1]) {
      // cout << j << endl;
      ans.push(j); lst = j - 1; break; 
    }
  }

  while(!ans.empty()) cout << ans.top() << ' ' , ans.pop();
  cout << endl; 
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