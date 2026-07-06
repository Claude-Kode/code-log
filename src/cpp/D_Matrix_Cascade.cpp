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
  vector<vector<int>> vec(n + 2, vector<int>(n + 2, 0));
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
      char c; cin >> c;
      vec[i][j] = c - '0';
    }
  }

  vector<vector<int>> l(n + 2, vector<int>(n + 2, 0));
  vector<vector<int>> r(n + 2, vector<int>(n + 2, 0));
  vector<vector<int>> m(n + 2, vector<int>(n + 2, 0));

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
      m[i][j] ^= (m[i - 1][j] ^ l[i][j] ^ r[i][j]);
      vec[i][j] ^= m[i][j];
      if (vec[i][j]) {
        ans ++;
        l[i + 1][j - 1] ^= 1;
        r[i + 1][j + 1] ^= 1;
        m[i][j] ^= 1;
      }

      if (l[i][j]) l[i + 1][j - 1] ^= 1;
      if (r[i][j]) r[i + 1][j + 1] ^= 1;
    }
  }

  // for(int i = 1; i <= n; i ++) {
  //   for(int j = 1; j <= n; j ++) {
  //     cout << l[i][j] << " \n"[j == n];
  //   }
  // }

  cout << ans << endl;
} 

/*
第一 变化肯定是自顶向下的
第二 我们可以快速算出每一个点变化范围内的  0 和 1 的初始的量
第三 我们实现一个可以快速区间修改的东西 然后模拟整个过程
第四 实在没招了我们看 dp 能不能做
或者说是一个  枚举 + checker
感觉会有一个类似于懒标记的东西 对对好像是这样的

但是这个懒标记不能单纯的就是每一层都是
交叉下传, 这样的话会有问题, 就是懒标记重叠 线段树之所以能懒标记 是因为他所有的自取件是互斥的
那么我们可不可以用数学的思路优化一下呢

那么我们可能一下重复的原因呢 就是

我们说线段树的懒标记其实是一种差分的思想是吗 对 差不多是这样的

这个新思路是这样的 就是我们每次操作相当于是在干啥呢 就是对  

卧槽我好像懂了 
我们可以一开始暴力的处理对角线, 就是从这个点 标记所有经过这个点斜率为 1和 -1 的点
我们可以注意到, 这个过程也是一个差分 !!!


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