// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int get_fa(int i, int k) {
  return (i + k - 2) / k;
}

int get_dep(int i, int k) {
  return ceil(log(i * (k - 1) + 1) / log(k));
}

int n; 
vector<int> dep;
vector<vector<int>> adj, fa;

void dfs(int u, int f) {
  dep[u] = dep[f] + 1; fa[0][u] = f;
  for(const auto &v : adj[u]) if (v != f) dfs(v, u);
}

void init() {
  for(int i = 1; i <= __lg(n); i ++) {
    for(int j = 1 ; j <= n; j ++) {
      fa[i][j] = fa[i - 1][fa[i - 1][j]];
    }
  }
}

int lca (int u, int v) {
  if (u < v) swap(u, v);
  for(int i = __lg(n); i >= 0; i --) {
    if (dep[fa[i][u]] >= dep[v]) u = fa[i][u];
  }
  if (u == v) return u;
  for(int i = __lg(n); i >= 0; i --) {
    if (fa[i][u] != fa[i][v]) {
      u = fa[i][u];
      v = fa[i][v];
    }
  }
  return fa[0][u];
}

void solve() { 
  int n, k, q; cin >> n >> k >> q;
  fa.assign(__lg(n) + 1, vector<int>(n + 1));
  adj.assign(n + 1, {});
  dep.assign(n + 1, 0);

  for(int i = 1; i <= k; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 

  dfs(1, 0); init();

  while (q --) {
    int u, v; cin >> u >> v; 
    if (u < v) swap(u, v);
    if (k == 1) {cout << abs(u - v) << endl; continue; }
    int ans = abs(get_dep(u, k) - get_dep(v, k));

    for(int i = 1; i <= ans; i ++) u = get_fa(u, k);

    while (u != v) {
      u = get_fa(u, k);
      v = get_fa(v, k);
      ans += 2;
    }
    cout << ans << endl; 
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