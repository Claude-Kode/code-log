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

  string a = " ", b = " ", temp; cin >> a >> b;
  int as = a.size(), bs = b.size();
  vector<vector<int>> memo(a.size() + 1, vector<int>(b.size() + 1, INT_MAX));

  std::function<int(int, int)> dfs = [&](int p1, int p2) -> int {

    if(p1 == as) return bs - p2;
    if(p2 == bs) return as - p1;
    if(memo[p1][p2] != INT_MAX) return memo[p1][p2];

    int rem1 = as - p1, rem2 = bs - p2;
    // 不改 a
    if (a[p1] == b[p2]) memo[p1][p2] = min(memo[p1][p2], dfs(p1 + 1, p2 + 1));
    // delete
    memo[p1][p2] = min(memo[p1][p2], 1 + dfs(p1 + 1, p2));
    // insert
    memo[p1][p2] = min(memo[p1][p2], 1 + dfs(p1, p2 + 1));
    // modify
    memo[p1][p2] = min(memo[p1][p2], 1 + dfs(p1 + 1, p2 + 1));
    // return
    return memo[p1][p2];
  }; 

  cout << dfs(0, 0) << endl;

}

/*
我的想法还是 就是固定一个前缀 我们保证前缀相等 然后缩小范围

对每一个状态维护一个相同的前缀
还是记忆化搜索 但是对后缀的第一位有 9 种模式
1. 删 插 改
2. 删 插 改
一共有九种组合 

每次都操作后缀下一个节点 
然后维护两个变量 
两个字符串除掉相同的前缀之后还分别剩下多少长度
如果一个人的长度为 0 了 返回的代价是另一个人的长度即可

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
