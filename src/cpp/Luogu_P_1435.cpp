// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;



void solve() { 

  string str = " ", temp; cin >> temp; str += temp; 
  int n = str.size() - 1;

  vector<vector<int>> memo(n + 1, vector<int>(n + 1, INT_MAX));
  std::function <int(int , int)> dfs = [&](int lp , int rp) ->  int {
    if (lp >= rp) return memo[lp][rp] = 0;
    if (memo[lp][rp] != INT_MAX) return memo[lp][rp];

    int &res = memo[lp][rp];
    int l = lp + 1, r = rp - 1;
    if (str[lp] == str[rp]) res = min(res, dfs(l, r));
    else res = min(dfs(l, rp), dfs(lp, r)) + 1;
    
    return memo[lp][rp] = res;
  };

  // for(int i = 1; i <= n; i ++) {
  //   for(int j = 1; j <= n; j ++) {
  //     cout << memo[i][j] << ' ';
  //   }cout << endl; 
  // }

  cout << dfs(1, n) << endl;
}

/*
第一念头就是缩小问题规模

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
