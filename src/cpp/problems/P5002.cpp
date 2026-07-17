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

  int n, r, q; cin >> n >> r >> q;
  vector<vector<int>> adj(n + 1);
  vector<int> val(n + 1, 1);
  for(int i = 1; i < n;i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto dfs = [&](this auto&& dfs, int u, int f) -> int {
    if (adj[u].size() == 1 && u != r) return 1;
    int res1 = 0, res2 = 0;
    for(const auto &v : adj[u]) if (v != f) {
      int temp = dfs(v, u);
      res1 += temp;     
      res2 += temp * temp;  
    }
    val[u] = (res1 * res1 - res2) + 2 * res1 + 1;
    return res1 + 1;
  };

  dfs(r, 0);
  for(int i = 1; i <= q; i ++) {
    int u; cin >> u;
    cout << val[u] << endl; 
  }
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