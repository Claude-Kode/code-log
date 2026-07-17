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
  int n; cin >>n ;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<int> d(n + 1);
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int l, k; cin >> l >> k;
    adj[k].push_back(l); d[l]++;
  }

  vector<vector<int>> dp(n + 1, vector<int>(2, -1));

  std::function <int(int, int)> dfs = [&](int u, int c) -> int {
    int &res = dp[u][c];
    if (adj[u].empty()) return res = (c == 1 ? vec[u] : 0);
    if (res != -1) return res; 
    
    int temp = 0;
    for(const auto &v : adj[u]) {
      if (c) temp += dfs(v, 0);
      else temp += max(dfs(v, 1), dfs(v, 0));
    }
    
    return res = (c ? vec[u] + temp : temp);
  };

  int ans = 0;
  for(int i = 1; i <= n; i ++) if (!d[i]) ans += max(dfs(i, 0), dfs(i, 1));

  std::cout << ans << endl; 
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
