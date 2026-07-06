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
  int n; cin >> n;
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> cnt(n + 1, 0), mx(n + 1);
  auto dfs = [&](this auto && dfs, int u, int f) -> void {
    if (adj[u].size() <= 1) cnt[u] = 1;
    for(const int &v : adj[u]) if (v != f) {
      dfs(v, u); cnt[u] += cnt[v];
    }
  }; 

  dfs(1, 0);

  vector<int> con(n + 1, 0); con[1] = (cnt[1] & 1 ? 1 : -1);
  auto dfs1 = [&](this auto && dfs1, int u, int f) -> void {
    for(const int &v : adj[u]) if (v != f) {
      con[v] = con[u] + (cnt[v] & 1 ? 1 : -1);
      dfs1(v, u);
    }
  };

  dfs1(1, 1);

  int ans = 0; 
  for(int i = 1; i <= n; i ++) if (cnt[i] & 1) ans ++;

  if (cnt[1] & 1) {
    int mx = 0; 
    for(int i = 1; i <= n; i ++) if (adj[i].size() == 1) mx = max(mx, con[i]);
    cout << ans - mx << endl;
  } else cout << ans << endl;

}

/*
对于一个

状态 :没配对的儿子 + 这个儿子对于自己的深度

如果一个树的叶子是奇数 那么这个剩下的奇数的叶子会顺着他这个爹 向上寻找可以配对的节点
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