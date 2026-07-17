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
  for(int i = 1; i <= n; i++) cin >> vec[i]; 
  for(int i = 1; i <= n; i++) vec.push_back(vec[i]);
  for(int i = 1; i <= 2 * n; i++) vec[i] += vec[i - 1];

  vector<vector<int>> dp1(2 * n + 1, vector<int>(2 * n + 1));
  function <int(int, int)> dfs1 = [&](int l, int r) -> int {
    int &res = dp1[l][r];
    if (l >= r) return 0;
    if (res) return res;

    for(int i = l; i < r; i ++) 
      res = max(res, dfs1(l, i) + dfs1(i + 1, r) + vec[r] - vec[l - 1]);
    
    return res;
  };

  vector<vector<int>> dp2(2 * n + 1, vector<int>(2 * n + 1, INT_MAX));
  function <int(int, int)> dfs2 = [&](int l, int r) -> int {
    int &res = dp2[l][r];
    if (l >= r) return 0;
    if (res != INT_MAX) return res;

    for(int i = l; i < r; i ++) 
      res = min(res, dfs2(l, i) + dfs2(i + 1, r) + vec[r] - vec[l - 1]);
    
    return res;
  };

  int ans1 = INT_MIN, ans2 = INT_MAX;
  for(int i = 1; i <= n; i ++) {
    ans1 = max(ans1, dfs1(i, i + n - 1));
    ans2 = min(ans2, dfs2(i, i + n - 1));
    // cerr << i << ' ' << i + n - 1 << endl; 
  }

  cout << ans2 << endl << ans1 << endl; 
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
