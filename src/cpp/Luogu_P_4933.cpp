// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998244353 ; 
const int maxn = 2e4 + 10 ;

void solve() { 

  int n; cin >> n ; 
  vector<int> vec(n + 1);
  for(int i = 1 ; i <= n ; i ++ ) {
    cin >> vec[i]; 
  }

   
  int ans = n % mod ;
  vector<vector<int>> dp(n + 1 , vector<int>(2 * maxn + 1));
   for(int i = 1; i <= n; i ++) {
    // dp[i][vec[i]] += 1;
    // dp[i][maxn + vec[i]] ++ ;
    // dp[i][maxn - vec[i]] ++ ;
    for(int j = 1 ; j < i; j ++) {
      int diff = maxn + vec[i] - vec[j];
      int cnt = dp[j][diff] + 1;
      // dp[j][diff] 统计的时候没有包括单单一个 j 构成的序列
      // dp[i][val] 其实没有统计长度小于 2 的等差序列
      (dp[i][diff] += dp[j][diff] + 1) %= mod ;
      (ans += cnt) %= mod;
    } 
  }

  // for(int i = 1 ; i <= n ; i ++) {
  //   for(int j = 1 ; j <= maxn ; j ++) {
  //     (ans += dp[i][j]) %= mod;
  //   }
  // }
  

  cout << ans % mod << endl; 

}

/*
我感觉我被题解限制了思路
其实这道题是 O(n 2) 的
对于两个数字，他们组成的等差数列的公差一定是一样的
那么我们不必去枚举公差，直接枚举第 i 个数前面那个数，得到公差进行转移即可
用 f[i][j] 表示以 i 结尾公差为 j 的等差数列个数

vec[i] - vec[j] + c (c 可以是一个比较大的数字)
这样可以区分 vec[i] > vec[j] OR vec[j] > vec[i]/
的情况 而且还能分别统计 diff 保持单调性 真的有点牛逼了 

但是这样的话 单一一个元素的等差序列会有两个公差
maxn + vec[i] OR maxn - vec[i]
所以我们 dp 数组直接不统计

当每次往后面接的时候 我们 + 1 , 算上长度 2 的序列

*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;

  solve() ;
  
  return 0 ;
}