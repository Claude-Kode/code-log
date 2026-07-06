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
    cin >> vec[i];
  }

  vector<vector<int>> adj(n + 1);
  for(int i = 1 ; i < n ; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> dp(n + 1, INT_MIN);
  std::function <int(int, int)> dfs = [&](int fa, int u) -> int {
    int &res = dp[u];
    if (adj[u][0] == fa) return res = vec[u];
    if (res != INT_MIN) return res;
    
    for(const auto &v : adj[u]) if (v != fa) res = max(res, dfs(u, v));
    return res ;
  };

  dfs(1, 1);
  for(const auto &a : dp) cout << a << ' ';
  cout << endl; 
  cout << *max_element(dp.begin() + 1, dp.end()) << endl; 
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