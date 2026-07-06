// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;


void solve() { 

  int n; cin >> n ;
  vector<vector<int>> adj(n + 1); 
  for (int i = 1; i <= n - 1; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);    
    adj[v].push_back(u);    
  }
  
  vector<int> vis(n + 1), fa(n + 1); 
  vector<vector<int>> dep(n + 1);
  std::function <void(int,int, int)> dfs = [&](int u, int father, int depth) -> void{
    if (vis[u]) return;
    vis[u] = 1; dep[depth].push_back(u);fa[u] = father;
    for(const auto &v : adj[u]) dfs(v, u, depth + 1);
  };

  dfs(1, 0, 0);
  int ans = 0;
  for(int i = 0 ; i <= n ; i ++ ) {
    int same_fa = 1; set<int> fas;
    for(const auto &v : dep[i]) fas.insert(fa[v]);
    ans = max(ans, (int)dep[i].size() + !(fas.size() > 1));
  } 

  cout << ans << endl; 

}

/*  std::function <int, (int, int)> dfs = [&](int u, int dep) -> int{
    
  };

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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}
