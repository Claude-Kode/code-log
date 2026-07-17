// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  auto sorted_vec = vec;
  sort(sorted_vec.begin() + 1, sorted_vec.end());
  int m = sorted_vec[(n + 1) / 2];  
  vector<array<int, 3>> pre(n + 1, {0, 0, 0});
  for(int i = 1; i <= n; i ++) {
    pre[i] = pre[i - 1];
    if (vec[i] <  m) pre[i][0] ++;
    if (vec[i] == m) pre[i][1] ++;
    if (vec[i] >  m) pre[i][2] ++;
  } 

  vector<int> dp(n + 1, INT_MIN); dp[0] = 0;
  for(int i = 1; i <= n; i ++) {
    for(int j = 0; j < i; j ++) {
      int len = i - j;
      if (!(len & 1)) continue; 
      int s = pre[i][0] - pre[j][0];
      int e = pre[i][1] - pre[j][1];
      int g = pre[i][2] - pre[j][2];
      bool f = (s + e > g and e + g > s and e > 0);
      if (!f || (dp[j] == 0 && j > 0) ) continue; 
      dp[i] = max(dp[i], dp[j] + 1);
    } 
  }

  cout << dp[n] << endl;
}
/*

我们把数组排序 然后中位数为 1 块, 小于中位数的一块, 大于中位数的一块

中位数会出现在中间那一块的左端点或者右端点

a + b > c && b + c > a 
应该是这样

所以其实我们可以 guess 一下 最后的最多划分 中位数就是整个数组的答案吗
假设存在一个最优解 x, 他不是中位数而且

证明完毕了 对于一个指定的中位数 如何锁定他的最大划分呢

总之初始化为负数就是为了避免那种
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
