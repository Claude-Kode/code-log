// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

// LCA
int n; 
vector<int> dep;
vector<vector<int>> adj, fa;

void dfs(int u, int f) {
  fa[0][u] = f;
  dep[u] = dep[f] + 1;
  for(const int &v : adj[u]) if (v != f) dfs(v, u);
}

void init(){
  for(int i = 1; i <= __lg(n); i ++) {
    for(int j = 0; j < n; j ++) {
      fa[i][j] = fa[i - 1][fa[i - 1][j]];
    }
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int lim = __lg(n);
  for(int i = lim; i >= 0; i --) if (dep[fa[i][u]] >= dep[v]) {
    u = fa[i][u];
  }
  if (u == v) return u;
  for(int i = lim; i >= 0; i --) if (fa[i][u] != fa[i][v]) {
    u = fa[i][u]; v = fa[i][v];
  }
  return fa[0][u];
}

void solve() { 

  cin >> n;
  adj.assign(n + 1, {});
  fa.assign(__lg(n) + 1, vector<int>(n + 1));
  dep.assign(n + 1, 0);

  for(int i = 1; i < n; i ++) {
    int f; cin >> f;
    adj[f].push_back(i);
  } 

  dfs(0, 0); init();

  vector<int> mx(n); iota(mx.begin(), mx.end(), 0LL);
  auto DFS = [&](this auto&& DFS, int u, int m) -> void {
    mx[u] = max(mx[u], m);
    for(const auto &v : adj[u]) DFS(v, mx[u]);
  };
  DFS(0, 0);


  int m; cin >> m;
  while(m --) {
    int c; cin >> c; c --;
    int f; cin >> f;
    while (c --) {
      int temp;cin >> temp; 
      f = lca(f, temp);
    }
    cout << mx[f] << endl; 
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