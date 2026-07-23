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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<int> vis(n + 1, 0), in(n + 1);
  for (int i = 1; i <= m; i ++) {
    int u, v;
    cin >> u >> v;
    // g[u] u 都是哪些人的前提条件
    g[u].push_back(v);
    in[v] ++;
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; i ++) {
    if (!in[i]) pq.push(i);
  }

  vector<int> ans; bool f = true;

  while (!pq.empty()) {
    int u = pq.top(); pq.pop();
    ans.push_back(u);
    for (auto &v : g[u]) {
      if (!--in[v]) pq.push(v);
    }
  }

  // dbug(g); dbug(ans);

  if (ans.size() < n) {
    cout << "No" << "\n";
    return;
  }

  cout << "Yes" << "\n";
  for (auto& x : ans) {
    cout << x << " ";
  }
  cout << "\n";
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