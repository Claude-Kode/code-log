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
  for(int i = 1; i <= n; i ++) cin >> vec[i];

  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }

  vector<int> dp(n + 1);
  function <int(int)> dfs = [&](int u) -> int {
    int &res = dp[u];
    if (adj[u].empty()) return 0;
    if (res) return res; 

    for(const auto &v : adj[u]) {
      int temp = dfs(v); 
      // cout << v << ' ' << temp << endl; 
      if (vec[v] == vec[u]) res += temp + 1;
    }

    return res;
  };

  dfs(1);
  cout << accumulate(dp.begin() + 1, dp.end(), 0LL) << endl; 
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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}