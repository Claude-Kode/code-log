// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;



void solve() { 

  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i++) cin >> vec[i], vec[i] += vec[i - 1];

  vector<vector<int>> memo(n + 1, vector<int>(n + 1, INT_MAX));
  std::function <int(int, int)> dfs = [&](int l, int r) -> int {
    if (l >= r) return 0;
    if (memo[l][r] != INT_MAX) return memo[l][r];
    
    int &res = memo[l][r], sum = vec[r] - vec[l - 1];
    for(int nr = l; nr < r; nr ++) {
      res = min(res, dfs(l, nr) + dfs(nr + 1, r) + sum);
    } 
    return res;
  };

  // std::function <int(int, int)> dfs = [&](int l, int r) -> int {
  //   if (l == r) return vec[l];
  //   if (memo[l][r] != INT_MAX) return memo[l][r];
    
  //   int nl = l + 1, nr = r - 1 , &res = memo[l][r];
  //   res = min(vec[l] + dfs(nl, r), dfs(l, nr) + vec[r]);
  //   return res;
  // };
 
  cout << dfs(1, n) << endl; 
}

/*
这个题跟昨天的倍增算法有点像
对于每个数都枚举他合并到哪里
感觉线性 dp 有点像固定了一个端点的区间 dp
这个合并石子应该是最典型的区间 dp 了
求解一个区间 然后分离这个区间 分别去求小区间的代价然后分别合并
小区间是用美剧的方式来求解的
感觉没有什么固定的套路 主要还是思维 问题上的转换

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
