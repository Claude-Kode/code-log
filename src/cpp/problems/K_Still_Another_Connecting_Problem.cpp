#pragma GCC optimize("Ofast,fast-math")
#pragma GCCtarget("avx,avx2")
// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

// #define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, q; cin >> n >> q;
  // cout << n << ' ' << q << '\n';
  vector<int> p(n + 1);
  vector<vector<int>> s(n + 1);
  for(int i = 2; i <= n; i ++) {
    cin >> p[i];
    s[p[i]].push_back(i);
  }

  vector<int> d(n + 1);
  auto dfs = [&](this auto && dfs, int u) -> void {
    d[u] = d[p[u]] + 1;
    if (s[u].empty()) return;
    for(const auto &v : s[u]) dfs(v);
  };
  dfs(1);

  // int cnt = 0;
  // auto DFS = [&](this auto && DFS, int u, map<int, int>& ump) -> void {
  //   if (ump[u]) {
  //     // dbug(u);
  //     cnt ++;
  //   }
  //   if (s[u].empty() || !ump[u]) return;
  //   for(const auto &v : s[u]) if(ump[v]) {
  //     DFS(v,  ump);
  //   }
  // };

  while(q --) {
    int m; cin >> m;
    map<int, int> ump;
    vector<int> vec(m + 1);
    for(int i = 1; i <= m; i ++) {
      cin >> vec[i];
      ump[vec[i]] ++;
    }

    // int mn = INT_MAX, node = 0;
    // for(int i = 1; i <= m; i ++) {
    //   if (mn > d[vec[i]]) {
    //     mn = d[vec[i]];
    //     node = vec[i];
    //   }
    // }
    // sort(vec.begin() + 1, vec.end(), [&](const auto &a, const auto &b) {
    //   return d[a] < d[b]; 
    // });
    // dbug(vec[1]);
    // dbug(vec);
    // cnt = 0, DFS(node,  ump);

    int cnt = 0;
    for(int i = 1; i <= m; i ++) {
      cnt += ump[p[vec[i]]] > 0;
    }
    cout << (cnt == m - 1? "Yes" : "No") << '\n';
  }
  
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}