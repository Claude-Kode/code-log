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
  vector<array<int, 2>> adj(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> adj[i][0] >> adj[i][1];
  }

  vector<int> dp(n + 1, 0);
  auto dfs = [&](this auto&& dfs, int u) -> int {
    int l = adj[u][0], r = adj[u][1];
    if (l) dp[u] = (dp[u] + 2 + dfs(l)) % mod;
    if (r) dp[u] = (dp[u] + 2 + dfs(r)) % mod;
    return dp[u];
  };

  dfs(1);

  queue<int> q; q.push(1);
  while (!q.empty()){
    int t = q.front(); q.pop();
    int l = adj[t][0], r = adj[t][1];
    if (l) (dp[l] += dp[t] + 1) %= mod, q.push(l); 
    if (r) (dp[r] += dp[t] + 1) %= mod, q.push(r); 
  }

  for(int i = 1; i <= n; i ++) {
    cout << (dp[i] + 1) % mod << ' ';
  }
  cout << endl; 
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