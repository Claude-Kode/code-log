// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int sim [6][6] = {

  {0, 0, 0, 0, 0, 0},
  {0, 5, -1, -2, -1, -3},
  {0, -1, 5, -3, -2, -4},
  {0, -2, -3, 5, -2, -2},
  {0, -1, -2, -2, 5, -1},
  {0, -3, -4, -2, -1, 0} 
};

int to_id(char temp) {
  if(temp == 'A') return 1;
  if(temp == 'C') return 2;
  if(temp == 'G') return 3;
  if(temp == 'T') return 4;
}

// class debug {
//   static void print ()
// };

void solve() { 

  int n, m; string s1 = " ", s2 = " ", temp; 
  cin >> n >> temp; s1 += temp; vector<int> v1(n + 1);
  for(int i = 1; i <= n; i ++) v1[i] = to_id(s1[i]), cout << v1[i] << ' ';
  cin >> m >> temp; s2 += temp; vector<int> v2(m + 1); cout << '\n';
  for(int i = 1; i <= m; i ++) v2[i] = to_id(s2[i]), cout << v2[i] << ' ';
  cout << '\n';

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
  dp[0][0] = 0;
  for(int i = 1; i <= n; i ++) {
    dp[i][0] = dp[i - 1][0] + sim[v1[i]][5]; 
  }

  for(int i = 1; i <= m; i ++) {
    dp[0][i] = dp[0][i] + sim[v2[i]][5]; 
  }

  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      // v1[i], v2[j]
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + sim[v1[i]][v2[j]]);
      // v1[i], -
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + sim[v1[i]][5]);
      // _, v2[j]
      dp[i][j] = max(dp[i][j], dp[i][j - 1] + sim[5][v2[j]]);
    }
  }

  cout << dp[n][m] << endl; 
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
