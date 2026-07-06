// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;

int F, V;
vector<int> ans;
vector<vector<int>> dp, vec;

int dfs(int f, int v){
  if (f > F) return 0;
  if (dp[f][v] != INT_MIN) return dp[f][v];
  for(int i = v + 1; i <= V; i ++) {
    dp[f][v] = max(dp[f][v], dfs(f + 1, i) + vec[f][i]);
  }
  return dp[f][v];
}


void solve() { 
  cin >> F >> V;
  dp.assign(F + 10, vector<int>(V + 10, INT_MIN));
  vec.assign(F + 10, vector<int>(V + 10, 0));
  for(int i = 1 ; i <= F; i ++) for(int j = 1; j <= V; j ++) cin >> vec[i][j];
  int mx = dfs(1, 0); 

  cout << mx << endl;
  for(const auto &a : ans) cout << a << ' ';
}
/*

*/

int_fast32_t main() {
  
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

