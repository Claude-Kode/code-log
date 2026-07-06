// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

struct edge{int v; int w; };

void solve() { 
  int n, m; cin >> n >> m;
  vector<vector<edge>> adj(n + 1);
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    if (w >= 0) adj[v].push_back({u, w});
  }

  vector<int> inq(n + 1), dis(n + 1,  LLONG_MAX), cnt(n + 1); 
  queue<int> q; q.push(1); dis[1] = 0; cnt[1] = 0;
  while (!q.empty()){
    int u = q.front(); q.pop();
    inq[u] = 0;
    for(const auto &[v, w] : adj[u]) if (dis[u] + w < dis[v]) {
      dis[v] = dis[u] + w;
      cnt[v] = cnt[u] + 1;
      if (cnt[v] >= n) { 
        cout << "YES" << endl;
        return;
      }
      if (!inq[v]) {
        inq[v] = 1;
        q.push(v); 
      }
    }
  }

  cout << "NO" << endl; 
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