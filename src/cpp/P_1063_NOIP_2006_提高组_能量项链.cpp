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
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i]; vec[i + n] = vec[i];
  }
  
  vector<vector<int>> dp(2 * n + 1, vector<int>(2 * n + 1));
  function <int(int, int)> dfs = [&](int l, int r) -> int {
    int &res = dp[l][r];
    // cout << l << ' ' << r << endl; 
    if (l >= r) return 0;
    if (res) return res;
    for(int i = l; i < r; i ++) {
      res = max(res, vec[l] * vec[i + 1] * vec[r + 1] + dfs(l, i) + dfs(i + 1, r));
    }
    return res;
  };

  int ans = INT_MIN; 
  for(int i = 1; i <= n; i++) {
    ans = max(ans, dfs(i, i + n - 1));
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