// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;



void solve() { 

  int n , m ; cin >> n >> m ;
  vector<int> vec(n + 1), ind(n + 1);
  for(int i =1 ; i <= n ; i ++ ) cin >> vec[i];

  vector<vector<int>> adj(n + 1);
  for(int i = 1 ; i <= m ; i ++ ) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v); 
  }

  queue<int> q;
  while (!q.empty()){
    int u = q.front(); q.pop();
    for(const auto &v : adj[u]) q.push(v);
  }

  vector<int> vis(n + 1), dp(n + 1);
  function<int(int)> dfs = [&](int u) -> int {
    // 为什么不能记忆化搜索 
    if (dp[u]) return dp[u];
    if (adj[u].empty()) return dp[u] = vec[u];
    for(const auto &v : adj[u]) {
      dp[u] = max (dp[u], vec[u] + dfs(v));
    }
    return dp[u];
  };

  for(int i = 1; i <= n; i ++) if (!ind[i]) dfs(i);

  cout << *max_element(dp.begin() + 1, dp.end()) << endl; 

}

/*
这个题额本质上就是寻找最长的链呗
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
