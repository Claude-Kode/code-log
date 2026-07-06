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
  vector<int> vec(n + 1);
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }


}

/*

我还想感觉会存在一种 贪心策略就是 每一个 d(u, v) 的代价不会超过 2 

哦题目说的是每次选择叶子节点的两个 然后匹配

在树中 每条边都是一个割边
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