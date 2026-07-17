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

void solve() { 
  int n, m; cin >> n >> m;
  vector<vector<array<int, 2>>> adj(n + 1);
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int k; cin >> k;
  vector<string> s(n + 1);
  for(int i = 1; i <= k; i ++) cin >> s[i];

  vector<vector<int>> v(k + 1);
  for(int i = 1; i <= n; i ++) {
    for(int j = 0; j < k; j ++) {
      if (s[i][j] == 'o') v[j + 1].push_back(i);
    }
  }

  

}

/*

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