// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 

  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  unordered_map<int, unordered_map<int, int>> ump;
  for(int i = 1; i <= m; i ++) {
    int u, v; cin >> u >> v;
    // if (ump[u][v]) continue; 
    adj[u].push_back(v);
    // ump[u][v] = 1;
  }

  vector<int> dis(n + 1, INT_MAX);
  vector<int> inque(n + 1, 0);
  queue<int> q; q.push(1); dis[1] = 1;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    inque[u] = 0;
    for(int v : adj[u]) if (dis[v] > max(dis[u], v)) {
      dis[v] = max(dis[u], v);
      if (!inque[v]) {
        q.push(v); inque[v] = 1;
      }
    }
  }

  for(int i = 1; i <= n; i ++) if (dis[i] != INT_MAX) {
    cout << dis[i] << ' '; 
  } else cout << -1 << ' ';

  cout << endl; 
}

/*
56 min
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