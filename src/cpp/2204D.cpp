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
  for(int i = 1; i <= m; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0; queue<int> q;
  vector<int> color(n + 1, -1), vis(n + 1);
  for(int i = 1; i <= n ; i++) if (!vis[i]) {
    int c0 = 0, c1 = 0; bool f = true;
    color[i] = 1; q.push(i); 
    while(!q.empty()) {
      int u = q.front(); q.pop();
      vis[u] = 1;
      color[u] ? c1 ++ : c0 ++;
      for(const auto &v : adj[u]) {
        if (color[v] == -1) {
          color[v] = 1 ^ color[u];
          q.push(v);
        } else if (color[v] == color[u]) {
          f = false;
        }
      }
    }
    ans += f * max(c0, c1);
  }
  
  cout << ans << endl; 
}
/*
一个森林
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
