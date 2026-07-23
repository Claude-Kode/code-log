// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {  
  int n; cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  if (n == 1) {
    cout << "0" << "\n";
    return;
  }

  vector<int> fa(n + 1);
  int A = 0, B = 0, diam = -1;

  auto dfs = [&](this auto&& dfs, int u, int f, int d) -> void {
    if (d > diam) diam = d, B = u;
    for (auto v : g[u]) if (v != f)
      fa[v] = u, dfs(v, u, d + 1);
  };

  diam = -1; dfs(1, 0, 0);  
  A = B;
  diam = -1; dfs(A, 0, 0);

  
} 
    
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
} 