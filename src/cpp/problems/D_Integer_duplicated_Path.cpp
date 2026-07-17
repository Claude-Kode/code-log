// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;


    
void solve() { 

  int n; cin >> n ;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) cin >> vec[i];

  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> ans(n + 1, 0), vis(n + 1, 0); map<int, int> mp;
  function <void(int, int)> dfs1 = [&](int fa, int u) -> void {
    if (vis[u]) return; vis[u] = 1;
    if (mp[vec[u]] || ans[fa]) ans[u] = 1;
    mp[vec[u]] ++;
    for(const auto &v : adj[u])  dfs1(u, v);
    mp[vec[u]] --;
  };  

  dfs1(1, 1);  
  for(int i = 1 ; i <= n; i ++) {
    if (ans[i]) cout << "Yes" << endl; 
    else cout << "No" << endl; 
  }
}

/*
某条路径的异或和如果是 0 那么这条路上的所有节点都是相等的
这个是错误的 
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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}