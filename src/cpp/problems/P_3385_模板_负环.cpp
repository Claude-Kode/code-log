// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void bellman_ford(int n){
  vector<vector<int>> adj(n + 1);
  vector<int> inque(n + 1);
  vector<int dis(n + 1, INT_MAX);
  
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    for(const auto )
  }

}
    
void solve() { 

  int n; cin > n; 
  vector<vector<int>> adj(n + 1);
  for(int i = 1 ; i < n ; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }

  

}

/*

bellman-ford : 对于每一个点 我们尝试所有的边 
对于当前尝试的边 我们假设存在一条路径经过这条边 看看这条路经能不能更新这个点的距离
这 tm 不就是纯暴力嘛

for 每个点v:
  for 每种可能的走法:
    看看能不能更新距离

相当于一个 dp 就是
dp[k - 1][v] 表示从起点到 v 经过最多 k - 1条路径的权值最少是多少

dp[k][v] = min(
  dp[k-1][v],                          # 不走新边
  min_{所有边(u,v)} (dp[k-1][u] + w)   # 走一条新边
)

对于 dp[k][v] = min(dp[1... k-1][v] + w);
 
总结的来说
如果 k - 1 轮没有对 第k轮产生更新 那么一定就不会在更新了 可以直接 break
如果 更新轮数超过了 n - 1轮 那么就出问题了 这个其实很好理解
一个图最远的两个点也就 n - 1 条边 如果出现了 n 条边还更短 就说明有负环了 
因为你想增加边数 如果是无向图还好说 直接反复横跳 这个就相当于环
如果是有向图 必须有环

同时你想 , 你走了环 边的数量增加了 但是代价减少了 说明这个环一周下来的权值是小于 0 的

spfa 就是加了一个贪心 只有这个节点的距离被更新了 他的邻居才会有可能被更新

bellman-ford 就是暴力循环 n - 1次 然后就百分百能更新出来 好几把扯淡啊这个
我懂了 这个可以从两个方面来考虑 一个是菊花图 一个是链状图

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