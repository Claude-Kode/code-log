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

  int n; cin >> n;
  vector<int> vec(2 * n + 1);
  unordered_map<int, unordered_map<int, int>> op;
  // + -> 1, - --> 2, * --> 3
  string ops;
  for(int i = 1; i <= n ; i ++) {
    char temp; cin >> temp; ops += temp;
    cin >> vec[i]; vec[i + n] = vec[i];
  }

  auto to = [&](char c) {
    if (c == 't') return 1;
    if (c == 'x') return 2;
  };

  for(int i = 0; i < n; i++) {
    op[i][(i + 1) % n] = to(ops[i % n]);
  }

  vector<vector<vector<int>>> dp(2 * n + 1,
  vector<vector<int>> (2 * n + 1, 
  vector<int>(2, 0)));

  for(int i = 1; i <= 2 * n; i ++) {
    for(int j = 1; j <= 2 * n; j ++) {
      dp[i][j][1] = INT_MIN;
      dp[i][j][0] = INT_MAX;
    }
  }

  for(int i = 1; i <= 2 * n ; i ++) dp[i][i][1] = vec[i], dp[i][i][0] = vec[i];

  for(int s = 1; s <= n; s ++) {
    for(int len = 2; len <= n; len ++) {
      for(int l = s; l <= s + n - len + 1; l ++) { int r = l + len - 1;
        for(int k = l; k < r; k ++) {
          int f = k % n, t = (k + 1) % n;
          if (op[f][t] == 1) 
            dp[l][r][1] = max(dp[l][r][1], dp[l][k][1] + dp[k + 1][r][1]),
            dp[l][r][0] = min(dp[l][r][0], dp[l][k][0] + dp[k + 1][r][0]);
          if (op[f][t] == 2) 
            dp[l][r][1] = max({dp[l][r][1], dp[l][k][1] * dp[k + 1][r][1], dp[l][k][0] * dp[k + 1][r][0]}),
            dp[l][r][0] = min({dp[l][r][0], dp[l][k][1] * dp[k + 1][r][0], dp[l][k][0] * dp[k + 1][r][1]});
        }
      }
    }
  }

  vector<int> ans; int res = 0;
  for(int i = 1; i <= n; i ++) res = max(res, dp[i][i + n - 1][1]);
  cout << res << endl; 
  for(int i = 1; i <= n; i ++) if (dp[i][i + n - 1][1] == res) cout << i << ' ';
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