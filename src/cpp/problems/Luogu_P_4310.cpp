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
  vector<int> dp(64);
  for(int i = 1 ; i <= n ; i ++) {
    int num; cin >> num;
    int mx = 0;
    for(int j = 0 ; j <= 63; j ++) if (num >> j & 1) mx = max(mx, dp[j] + 1);
    for(int j = 0 ; j <= 63; j ++) if (num >> j & 1) dp[j] = max(dp[j], mx);
  }
  
  cout << *max_element(dp.begin(), dp.end()) << endl;
}

/*
就是 dp[i] 代表 在所有子序列中 结尾的数字第 i 位是 1 的序列最大长度 是 dp[i]

一个数 num 他可以接在任何一个 dp[j] 的后面 (num >> j & 1) == 1

然后不断更新这个最大长度 最后再把所有的 j 回滚一边最大长度

这个题如果是暴力去写 
就是假设以这个数为结尾 他的最长的序列是多少

那么他要枚举前面所有的序列的结尾 只要是有共同的 1 就 + 1 然后取最大值
这个过程本质上就是找 前面所有序列结尾的数中 有和自己相同位置的 1 , 然后找那个序列最长的

也即是说 我们只关心 一个数 哪一位是 1 , 他的的序列长度是多少


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
