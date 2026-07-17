// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;

int val[6][6] = {
  {0, 0, 0, 0, 0, 0},
  {0, 5, -1, -2, -1, -3},
  {0, -1, 5, -3, -2, -4},
  {0, -2, -3, 5, -2, -2},
  {0, -1, -2, -2, 5, -1},
  {0, -3, -4, -2, -1, 0} 
};

void solve() { 

  auto c = [&](char temp) -> int{
    if (temp == 'A') return 1;
    if (temp == 'C') return 2;
    if (temp == 'G') return 3;
    if (temp == 'T') return 4;
  };    

  int n, m; 

  cin >> n ;vector<int> v1(n + 1);
  for(int i = 1; i <= n; i ++) {
    char temp; cin >> temp;
    v1[i] = c(temp);
  }

  cin >> m; vector<int> v2(m + 1);
  for(int i = 1; i <= m; i ++) {
    char temp; cin >> temp;
    v2[i] = c(temp);
  }

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN)); dp[0][0] = 0;
  // 对齐 当一个序列没有别的长度了的时候 另一个剩下的只能去对齐空格
  for(int i = 1; i <= m; i ++) {
    dp[0][i] = dp[0][i - 1] + val[v2[i]][5];
  }
  // 对齐 当一个序列没有别的长度了的时候 另一个剩下的只能去对齐空格
  for(int i = 1; i <= n; i ++) {
    dp[i][0] = dp[i - 1][0] + val[v1[i]][5];
  }


  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      int &res = dp[i][j];
      // v1[i] --> v2[j]
      res = max(res, dp[i - 1][j - 1] + val[v1[i]][v2[j]]); 
      // v2[j] -> _
      res = max(res, dp[i - 1][j] + val[v1[i]][5]); 
      // v1[i] --> _
      res = max(res, dp[i][j - 1] + val[5][v2[j]]); 
    }
  }

  cout << dp[n][m] << endl; 
}

/*
首先是固定 序列1 的 l 部分 和 序列2 的 r 部分对齐
这个我还真的想到了
但是后面的处理我没有想到
就是只处理一下每个序列的最后一位是怎么对齐的然后这样长度就缩短了
就可以缩短长度然后分治了

因为可以观察到 一个范围内部的字符 只能和字符或者空格对齐
而空格只能和字符对齐

下次知道了 可以尝试在区间内剥离出来一个元素进行分析 然后这样就可以缩小区间了

本质上就是区间之间的转移
然后有很多种转移的方式
比如回文 就是左边减少一个或者右边减少一个 或者同时收缩
比如合并果子 就很像分治的思想 每次都是合并两个区间 所以一定是两个更小的区间合并过来
我就枚举所有的小区间

还有这个  我们发现每个元素只有三种情况 然后我们还要做缩小取件的动作
就很容易想到处理区间的最后一位 然后缩小区间了

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
