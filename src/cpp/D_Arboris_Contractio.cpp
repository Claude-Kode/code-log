// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;
const int inf = INT_MAX;

void solve() { 
  int n; cin >> n;
  vector<int> g(n + 1);
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    g[u] ++, g[v] ++;
  }

  

  int cnt = count(g.begin(), g.end(), 1LL);
  int ans = INT_MAX;
  for(int i = 1; i <= n; i ++) {
    int m = 0;
    for(const auto &v : adj[i]) m += (g[v] == 1);
    ans = min(ans, cnt - m);
  }

  cout << (n <= 3 ? 0 : ans) << endl;
}

/*
这个题我不会推断那个最坏情况下 操作数量是多少 泽哥我不会推断
*/  

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}