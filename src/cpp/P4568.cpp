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
  int n, m, k; cin >> n >> m >> k;
  int s, t; cin >> s >> t;

  // cerr << n << ' ' << m << ' ' << k << ' ' << s << ' ' << t << '\n' ; 
  vector<vector<array<int, 2>>>  adj(n + 1);
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  } 
  
  vector<vector<int>> dis(k + 1, vector<int>(n + 1, LLONG_MAX / 2));
  auto cmp = [&](const array<int, 3> &a, const array<int, 3> &b) {
    return a[1] > b[1];
  };
  
  priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> pq(cmp);
  pq.push({s, 0, k}); dis[k][s] = 0;
  while(!pq.empty()) {
    auto [u, d, f] = pq.top(); pq.pop();
    if (d > dis[f][u]) continue;
    for(const auto &[v, w] : adj[u]) {
      if (d + w < dis[f][v]) {
        dis[f][v] = d + w;
        pq.push({v, d + w, f});
      }
      if (f > 0 && d < dis[f - 1][v]) {
        dis[f - 1][v] = d;
        pq.push({v, d, f - 1});
      }
    }
  }

  assert(dis[0][t] != LLONG_MAX);


  int ans = INT_MAX;
  for(int i = 0; i <= k; i ++) ans = min(ans, dis[i][t]);
  cout << ans << endl; 
  // cout << dis[0][t] << endl; 
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

