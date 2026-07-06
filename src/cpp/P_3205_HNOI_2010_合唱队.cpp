// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 19650827; 
const int N = 2e5 + 10;



void solve() { 

  int n; cin >> n; vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++ ) {
    cin >> vec[i];
  }
  vector<vector<vector<int>>> dp(n + 1, 
    vector<vector<int>>(n + 1,
      vector<int>(2, -1)));

  function <int(int, int, int)> dfs = [&](int l, int r, int d) -> int {
    int &res = dp[l][r][d];
    if (l == r && d == 0) return res = 1;
    if (l == r && d == 1) return res = 0;
    if (res != -1) return res;

    // 0 from left , 1 from right
    res = 0;
    if (d == 0) {
      if (vec[l] < vec[l + 1]) (res += dfs(l + 1, r, 0)) %= mod;
      if (vec[l] < vec[r]) (res += dfs(l + 1, r, 1)) %= mod;
    } else {
      if (vec[r] > vec[r - 1]) (res += dfs(l, r - 1, 1)) %= mod;
      if (vec[r] > vec[l]) (res += dfs(l, r - 1, 0)) %= mod;
    }
    return res;
  };

  cout << (dfs(1, n, 0) + dfs(1, n, 1)) % mod << endl; 
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
