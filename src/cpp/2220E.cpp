// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

struct node {
  int u, dg, rd;
  bool operator<(const node& other) const {
    if (dg * other.rd != other.dg * rd) return dg * other.rd > other.dg * rd;
    else return dg < other.dg;
  }
};

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> color(n + 1);
  for (int i = 1; i <= n; i ++) color[i] = s[i - 1] - '0';
  
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<int> d(n + 1), red(n + 1);
  for (int i = 1; i <= n; i ++) d[i] = adj[i].size();
  for (int u = 1; u <= n; u ++) {
    for (const auto &v : adj[u]) if (color[v] == 1) red[u] ++;
  }

  priority_queue<node> pq;
  vector<int> vis(n + 1);
  for (int u = 1; u <= n; u ++) if (!color[u]&& red[u]) {
    pq.push({u, d[u], red[u]});
  }
  double ans = 0; int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += color[i];
  while (!pq.empty() && cnt < n) {
    auto [u, dg, rd] = pq.top(); pq.pop();
    if (vis[u] || color[u] == 1) continue;
    if (red[u] == 0) continue;
    ans += 1.0 * dg / red[u];
    color[u] = 1, vis[u] = 1, cnt ++;
    for (const auto &v : adj[u]) {
      if (!vis[v] && color[v] == 0) {
        red[v] ++; pq.push({v, d[v], red[v]});
      }
    }
  }

  cout << ans << endl;
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

  cout << fixed << setprecision(20);

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}

