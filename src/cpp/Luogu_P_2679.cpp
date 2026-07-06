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

  int n, m, o; cin >> n >> m >> o;
  string a = " ", b = " ", temp; 
  cin >> temp; a += temp; cin  >> temp; b += temp; 
  vector<vector<vector<vector<int>>>> Dp(n + 1, 
    vector<vector<vector<int>>>(m + 1,
      vector<vector<int>>(o + 1, 
        vector<int>(2, 0))));

  for(int i = 0 ; i <= n ; i ++ ) {
    Dp[i][0][0][0] = 1;
  }

  // dp 数组的含义是 对每一段 j 来枚举用多少个 i 来匹配他 , 这个匹配还能用多少 k
  // 所以 j 默认都是配对成功了的

  /*
  dp[i][j][k][0]: 从A的前i个字符中，用k个子串匹配了B的前j个字符，
               且A的第i个字符**没有被选中**的方案数

  dp[i][j][k][1]: 从A的前i个字符中，用k个子串匹配了B的前j个字符，
                且A的第i个字符**被选中**的方案数
  */
  // vector<vector<vector<int>>> K1, K2(n + 1, 
  // vector<vector<int>>(m + 1,
  // vector<int>(2, 0)));

  // dp[j][k][0/1] 表示考虑前i个字符的滚动数组
  vector<vector<vector<int>>> dp(m + 1, 
    vector<vector<int>>(o + 1, 
      vector<int>(2, 0)));
  vector<vector<vector<int>>> ldp(m + 1, 
    vector<vector<int>>(o + 1, vector<int>(2, 0)));

  

  for(int i = 1 ; i <= n ; i ++ ) {
    // 清零dp数组
    dp.assign(m + 1, 
      vector<vector<int>>(o + 1, 
        vector<int>(2, 0)));
    ldp[0][0][0] = 1; 
    for(int j = 1 ; j <= m ; j ++ ) {
      for(int k = 1 ; k <= o ; k ++ ) {
        if (a[i] == b[j]) {
          (dp[j][k][1] += ldp[j - 1][k][1]) %= mod;
          (dp[j][k][1] += ldp[j - 1][k - 1][1]) %= mod;
          (dp[j][k][1] += ldp[j - 1][k - 1][0]) %= mod;
          // 接着完善当前一段 
          // (K1[i][j][1] += K1[i - 1][j - 1][1]) %= mod;
          // 从 k - 1 接着选 但是作为下一个子串
          // (K1[i][j][1] += K2[i - 1][j - 1][1]) %= mod;
          // 或者上一段没选
          // (K1[i][j][1] += K2[i - 1][j - 1][0]) %= mod;
        } else dp[j][k][1] = 0;
        // 如果这一个不选 上一个有可能选或者不选
        // 如果上一个没选 上一对一定是 i-1 和 j 进行匹配
        // 如果上一个选了 那么这一次是接着上一对的 1 选的 也就是 i-1 和 j 配对陈工了了
        // (K1[i][j][0] += K1[i - 1][j][0] + K1[i - 1][j][1]) %= mod;
        // K2 = K1;
        (dp[j][k][0] += ldp[j][k][0] + ldp[j][k][1]) %= mod;
        
      }
    }
    ldp = dp;
  }


  // for(int i = 0 ; i <= n ; i ++ ) {
  //   dp[i][0][0][0] = 1;
  // }

  // for(int i = 1 ; i <= n ; i ++ ) {
  //   for(int j = 1 ; j <= m ; j ++ ) {
  //     for( int k = 1 ; k <= o ; k ++ ) {
  //       if (a[i] == b[j]) {
  //         // 选A[i]的情况
  //         // 1. 延续上一个子串
  //         dp[i][j][k][1] = dp[i - 1][j - 1][k][1];
  //         // 2. 新开一个子串
  //         if (k > 0) {
  //           dp[i][j][k][1] = (dp[i][j][k][1] + dp[i - 1][j - 1][k - 1][0]) % mod;
  //         }
  //       } else {
  //         dp[i][j][k][1] = 0;
  //       }
  //       // 不选A[i]的情况
  //       dp[i][j][k][0] = (dp[i - 1][j][k][0] + dp[i - 1][j][k][1]) % mod;
  //       // if (a[i] == b[j]) {
  //       //   // 如果这一位选 那么他要么是新开一段 要么是接着上一段的选
  //       //   dp[i][j][k][1] = dp[i - 1][j - 1][k][1] + dp[i - 1][j][k - 1][0];
  //       //   // 如果这一位不选 那么他要么是接着上一段没选的不选 要么是上一段选完了 开始下一段不选的了
  //       // } else {
  //       //   dp[i][j][k][1] = 0;
  //       // }
  //       // dp[i][j][k][0] = (dp[i - 1][j][k][0] + dp[i - 1][j][k][1]) % mod;
  //       // // dp[i][j][k][0] = dp[i - 1][j - 1][k][1] + dp[i - 1][j][k][0];
  //       dp[i][j][k][1] %= mod;
  //       dp[i][j][k][0] %= mod;
  //     }
  //   }
  // }

  cout << (dp[m][o][0] + dp[m][o][1]) % mod << endl;
}

/*
for 循环的本质是在扩展问题的范围
但是也有可能说是避免为题的后效性 ? 

我就要不使用滚动数字的版本 可是我还是有点不太明白啊好像 
如果这一位选择拼到第 k 个字符串后面就是
dp[i][j][k][1] += dp[i - 1][j - 1][k][1]
因为如果是 1 的地方必须 a[i] == b[j] 所以一定是两个指针一起跳
如果选择这一对 i 和 j 进行匹配的话 也可以上次没有进行匹配 也就是 i - 1 和 j 匹配失败了 
所以就是 dp[i][j][k][1] += dp[i - 1][j][k - 1][0] 
然后 如果这一位确定不选了
上一次如果是 0 也就是 i - 1 和 j 匹配失败了 也是 
dp[i][j][k][0] += dp[i - 1][j][k][0]
如果上一次是 1 的话 
也还是
dp[i][j][k][0] += dp[i - 1][j][k][1] 
这个就是我的转移思路 如果 a[i] != b[i] 
dp[i][j][k][1] 这一位就不能选 直接等于 0 ?

是这样的 首先写一个 dp 的题的时候 我会看
他能不能缩小问题的范围 比如这道题是球 k 个 我就看是不是能从 k - 1 推过来 ? 或者缩小 a b 的规模 然后一步步往上推 我一开始是想到了一个字符选或者不选 
然后就是设计状态 , 其实就是用一些数字表示一个局面 一个局面可以从另一个局面推导出来 然后我就看这道题的三个属性
这个状态是怎么设计出来的呢 dp[i][j][k]代表什么含义呢 我不是很懂

先看问题是否可以收缩
然后看可以收缩的维度 这个就可以用来表示状态
然后接着看什么会影响状态 然后再加一个维度之类的 之后再进行简化

dp[i][j][k][0]: 从A的前i个字符中，用k个子串匹配了B的前j个字符，
               且A的第i个字符**没有被选中**的方案数

dp[i][j][k][1]: 从A的前i个字符中，用k个子串匹配了B的前j个字符，
               且A的第i个字符**被选中**的方案数

滚动数组优化就是 比如每次都用 k 和 k - 1 更新 k 你就搞成两个降一维数组
遍历方向就是 我现在更新的数据 刚刚在同一个维度上被更新过了 这是不允许的
可以反向遍历优化
这个地方还值得讨论一下

初始化很简单了 你转移方程设计出来了 然后设计一下基底 要设计的合理就可以了
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

