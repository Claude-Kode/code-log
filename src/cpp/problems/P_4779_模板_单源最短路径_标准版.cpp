// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

struct edge {
  int v; int w;
  bool operator< (edge other) const {
    return w > other.w;
  }
};
    
void solve() { 

  int n, m, s; cin >> n >> m >> s;
  vector<vector<edge>> adj(n + 1);
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  vector<int> vis(n + 1), dis(n + 1, INT_MAX); 
  priority_queue<edge> pq; pq.push({s, 0}); dis[s] = 0;
  while (!pq.empty()) {
    auto [u, w] = pq.top(); pq.pop();
    if (vis[u]) continue; vis[u] = 1;
    for(const auto &[v, ww] : adj[u]) if (dis[v] > w + ww) {
       dis[v] = w + ww, pq.push({v, dis[v]});
    }
  }

  for(int i = 1 ; i <= n ; i++ ) {
    cout << dis[i] << ' ';
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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}

