// @Author : GoryK  
#include <bits/stdc++.h>
// using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int long long 
#define endl " \n"

using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static constexpr int mod = 1e9 + 7; 
static constexpr int N = 2e5 + 10;

void solve() { 
  int n, q; cin >> n >> q;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  vector<vector<array<int, 2>>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  while(q -- ) {
    int u, x; cin >> u >> x;

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