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

int n, k; 

void solve() { 
  cin >> n >> k;
  vector<vector<array<int, 2>>> adj(n + 1);
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
      int w; cin >> w;
      if (i != j) adj[i].push_back({j, w});
    }
  }

  for(int i = 1; i <= n; i ++) {
    for(const auto& [v, w] : adj[i]) {
      cout << i << ' ' << v << ' ' << w << endl; 
    }
  }

  vector<int> v(k + 1);
  for(int i = 1; i <= k; i ++) {
    cin >> v[i];
  }

  auto dis = spfa(1, adj);
  for(int i = 1; i <= n; i ++) {
    cout << i << ' ' << dis[i][0] << ' ' << dis[i][1] << "\n";
  }

  // vector<vector<vector<int>>> dis(n + 1);
  // for(int i = 1; i )
  
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