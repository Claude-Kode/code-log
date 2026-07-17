// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

auto cmp = [](const array<int, 2>& a, const array<int, 2>& b) {return a[1] > b[1];};

int dijkstra (int s, int t, vector<vector<array<int, 2>>>& adj, vector<int>& vis, vector<int>& dis) {
  priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> pq(cmp); 
  pq.push({s, 0}); dis[s] = 0;
  while (!pq.empty()) {
    auto [u, w] = pq.top(); pq.pop();
    // cout << u << endl; 
    if (u == t) return w;
    if (vis[u]) continue; vis[u] = 1;
    for(const auto &[v, ww] : adj[u]) if (dis[v] > max(w, ww)) {
       dis[v] = max(w, ww), pq.push({v, dis[v]});
    }
  }

  // for(const auto &v : dis) cout << v << ' ' ;
  // cout << endl; 
  // for(int i = 1; i <= 3; i ++) cout << dis[i] << ' ';
  // cout << endl; 

  return -1; 
}

void solve() { 
  int n, m, s, t; cin >> n >> m >> s >> t;
  vector<vector<array<int, 2>>> adj(n + 1);
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> vis(n + 1, 0), dis(n + 1, INT_MAX);
  cout << dijkstra(s, t, adj, vis, dis);
  // cout << dijkstra(s, t, adj, vis, dis) << endl; 
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