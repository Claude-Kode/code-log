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
vector<int> dep, mx;
vector<vector<int>> adj, fa;

void dfs(int u, int f) {
  fa[0][u] = f; mx[u] = max(u, f);
  dep[u] = dep[f] + 1;
  for(const int &v : adj[u]) if (v != f) dfs(v, u);
}

void init(){
  for(int i = 1; i <= __lg(n); i ++) {
    for(int j = 1; j <= n; j ++) {
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
  adj.assign(n + 1, {}); dep.assign(n + 1, 0); mx.assign(n + 1, 0);
  fa.assign(__lg(n) + 1, vector<int>(n + 1, 0));
  for(int i = 2; i <= n; i ++) {
    int f; cin >> f; 
    adj[f].push_back(i);
    
  }

  // for(int i = 1; i <= n; i ++) {
  //   cout << "i: " << i << endl; 
  //   for(auto &v : adj[i]) cout << v << ' ';
  //   cout << endl;  
  // }

  dfs(1, 0); init();

  // for(int i = 1; i <= n ;i ++) {
  //   cout << "i: " << i << endl; 
  //   for(const auto &v : adj[i]) cout << v << ' ';
  //   cout << endl; 
  // }



  int q; cin >> q;
  while (q --) {
    int m, u; cin >> m >> u; 
    for(int i = 2; i <= m; i ++) {
      int v; cin >> v; 
      u = lca(u, v);
    }
    cout << mx[u] << endl; 
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