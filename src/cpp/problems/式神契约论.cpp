// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

vector<int> d(N + 1, 1); d[1] = 0;

void solve() { 



}

/*

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

  for(int i = 1 ; i )

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}

// 预处理所有可能的放置方式
for (每个物品i) {
    for (方向d: 2个方向) {
        当前尺寸 = (a,b) 或 (b,a)
        for (左上角位置x: 0..3-长) {
            for (左上角位置y: 0..3-宽) {
                计算占用的mask
                记录mask对应的价值
            }
        }
    }
}

// 分组背包DP
dp[0] = 0;
for (每个物品i) {
    for (mask: 511..0) {  // 逆序
        for (该物品的所有放置方式mask_sub) {
            if ((mask & mask_sub) == mask_sub) {  // 可以放置
                dp[mask] = max(dp[mask], dp[mask ^ mask_sub] + val);
            }
        }
    }
}