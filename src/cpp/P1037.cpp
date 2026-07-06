// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

vector<vector<int>> floyd(int n, vector<array<int, 3>>& edges) {
  vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MAX));
  for(int i = 1; i <= n; i ++) f[i][i] = 0;
  for(const auto &[u, v, w] : edges) f[u][v] = min(f[u][v], w);

  for(int k = 1; k <= n; k ++) {
    for(int i = 1; i <= n; i ++) {
      if (f[i][k] == INT_MAX) continue; 
      for(int j = 1; j <= n; j ++) {
        if (f[j][k] == INT_MAX) continue;
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }

  return f;
}

void solve() { 

  int n, k; cin >> n >> k;
  vector<array<int, 3>> edges; vector<int> w(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    edges.push_back({u, v, 1LL});
    edges.push_back({v, u, 1LL});
  }

  for(int i = 1; i <= n; i ++) cin >> w[i];

  auto f = floyd(n, edges);

  int mx = 0, sum = 0;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) if (f[i][j] == 2){
      mx = max(mx, w[i] * w[j]);
      sum += (w[i] * w[j]);
    }
  }

  cout << mx << ' ' << sum << "\n"; 
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