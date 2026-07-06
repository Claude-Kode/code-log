// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n, m, Q;
int to(char c) {return (c == '(' ? 1 : -1);}

void solve() { 
  cin >> n >> m >> Q;
  vector<vector<array<int, 2>>> adj(n + 1);
  for(int i = 1; i <= m; i ++) {
    int u, v; char c; cin >> u >> v >> c;
    adj[u].push_back({v, to(c)});
    adj[v].push_back({u, to(c)});
  }

  vector<int> res(Q + 1, INT_MAX);
  vector<array<int ,2>> que(1, {0, 0});
  for(int i = 1; i <= Q; i ++) {
    int u, v; cin >> u >> v;
    que.push_back({u, v});
  }
  
  for(int s = 1; s <= n; s ++) {
    vector<vector<int>> dis(n + 1, vector<int>(n * 2 + 1, INT_MAX));
    dis[s][0] = 0;
    queue<array<int, 2>> q; q.push({s, 0});
    while(!q.empty()) {
      auto [u, w] = q.front(); q.pop();
      for(const auto& [v, ww] : adj[u]) {
        int nw = w + ww;
        if (nw >= 0 && nw <= n * 2 && dis[u][w] + 1 < dis[v][nw]) {
          dis[v][nw] = dis[u][w] + 1;
          q.push({v, nw});
        }
      }
    }

    for(int i = 1; i <= Q; i ++) if (que[i][0] == s) res[i] = dis[que[i][1]][0];
  }

  for(int i = 1; i <= Q; i ++) cout << (res[i] == INT_MAX ? -1 : res[i]) << endl;
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