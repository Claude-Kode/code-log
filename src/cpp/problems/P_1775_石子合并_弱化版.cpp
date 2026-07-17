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
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i]; vec[i] += vec[i - 1];
  } 

  vector<vector<int>> memo(n + 1, vector<int>(n + 1, INT_MAX));

  function <int(int, int)> dfs = [&](int l, int r) -> int{
    int &res = memo[l][r];
    if (l >= r) return res = 0;
    if (memo[l][r] < INT_MAX) return memo[l][r];

    for(int i = l; i < r; i ++) {
      res = min(res, dfs(l, i) + dfs(i + 1, r) + vec[r] - vec[l - 1]);
      // cout << res << endl; 
    } 
    return res;
  };

  cout << dfs(1, n) << endl; 
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
