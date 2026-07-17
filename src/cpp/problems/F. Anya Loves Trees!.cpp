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
  for (int i = 2; i <= n; i ++) {
    int f; cin >> f;
    g[f].push_back(i);
  }

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  bool f = true;
  auto dfs = [&](auto&& sef, int u) -> array<int, 3> {
    if (g[u].empty()) {
      return {a[u], a[u], 1};
    }

    vector<array<int, 2>> vec;
    int mn = INT_MAX, mx = INT_MIN, sz = 0;
    for (auto &v : g[u]) {
      auto [_mn, _mx, _sz] = sef(sef, v);
      mn = min(mn, _mn);
      mx = max(mx, _mx);
      sz += _sz;
      vec.push_back({_mn, _mx});
    }

    int cnt = 0;
    for (int i = 1; i < vec.size(); i ++) {
      cnt += (vec[i][0] - 1 !=  vec[i - 1][1]);
    }

    if (cnt > 1 or sz != mx - mn + 1) {
      f = false;
    }

    return {mn, mx, sz};
  };

  dfs(dfs, 1);
  cout << (f ? "YES" : "NO") << "\n";
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