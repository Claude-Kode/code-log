// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;


    
void solve() {

  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) cin >> vec[i];

  // odd : 设当前遍历到第 i 为 , 前 i - 1的一个选好左端点的最优解是啥
  // even 就是提前挑好右端点
  // 这样我们每次就相当于是都选择一个右端点 所以我们维护一个右端点就好了
  int even = INT_MIN, odd = INT_MIN, ans = 0;
  for(int i = 1; i <= n; i ++) {
    int cand = vec[i] & 1 ? odd + vec[i] : even + vec[i];

    if (vec[i] & 1) {
      odd = max(odd, ans + vec[i]);
    } else {
      even = max(even, ans + vec[i]);
    }

    ans = max(ans, cand);
  }

  cout << ans << endl; 
}


/*

1. 为什么这道题我一想到 dp 
2. 线芯 dp 和 区间 dp 有什么本质的区别呢
3. 我能理解的动态规划就是一个状态转移 

可以抽象成选择一条链 每一条链的长度要 >= 2

问题是可以变成很小的规模 而且解法都是一模一样的
线性 dp 的本质是不断扩展
而区间 dp 偏向于 分治 还有合并

我的关键是状态转移搞错了
如果这个状态要是选 应该从奇偶性相同的状态转移过来

而且我对状态的理解有问题 
dp[i][1] 是以 i 为结尾 , 而且 i一定被涂红的最好状态
而不是考虑 1 -> i 所有的最好的状态 

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