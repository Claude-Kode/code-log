// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 4e5;

void solve() { 
	int n; cin >> n; 
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> b[i];
	}

	// dp[i] : a == i , max_b = dp[i]
	vector<int> dp(2 * maxn + 1, INT_MIN); dp[maxn] = 0;
	for(int i = 1 ; i <= n ; i ++) {
		if (a[i] > 0) {
			for(int j = 2 * maxn ; j >= a[i] ; j --) if(dp[j - a[i]] != INT_MIN){
				dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
			}
		} else {
			for(int j = 0 ; j <= 2 * maxn + a[i]; j ++) if(dp[j - a[i]] != INT_MIN) {
				dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
			}
		}
	}

	int ans = 0 ;
	for(int i = maxn ; i <= 2 * maxn; i ++) if (dp[i] >= 0) {
		 ans = max(ans, dp[i] + i - maxn);
	}

	cout << ans << endl; 
}

/*

想到可以以值域为参数构建状态或许 ? 
但是如何处理负数的出现呢
最后求的值是 最大的值 所以值应该是状态的结果表示

我觉得这个和更像是一个限制条件

或者来说 这个可能已经就有了后效性 
并不能每一步都要 智商或者情商都是 > 0 的 这个是处理这道题的难点
一般来说 dp 的属性都是作为下标 然后通过数组进行访问
但是数组没有负数索引怎么办 干脆可以开两倍的正数

这个应该属于 01 背包的变种题目

研究一下什么是后效性呢 这个题是不是有后效性呢
或者说这个限制是不断变化的

或者说我们对于一个负数来说 我们可以增大基底即可

对于每个数我们都有选择或者不选择 
可以很容易的想到 当我们固定智商总和的时候选择最大的情商总和就可以了
而且这道题有一个特点 也就是智商总和可能是负数
和普通的 dp 不一样 , 在一开始想的时候我是想直接递推的
但是那样是不完全的 , 我们可以注意到 在 n 的最优解并不一定是从 n-1 的最优解推出来的
有可能是 n-1 的某个解推出来的 而这个解是有可能不符合 suma >= 0 和 sumb >= 0的
所以对于每次选择 suma < 0 和 sumb < 0 我们都应该存一下
所以想到给下标增加一个基底即可 这个很好想

下次碰到这种多层限制的题 有可能先考虑一下 把一个限制给量化 固定住 然后再算另一个之类的


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

