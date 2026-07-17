// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() {

	int n; cin >> n;
	vector<int> a(n + 1), b(n + 1), pos_b(n + 1);
	map<int, int> mp;
	for(int i = 1; i <= n ;i ++ ) cin >> a[i], mp[a[i]] = i;
	for(int i = 1; i <= n ;i ++ ) cin >> b[i], b[i] = mp[b[i]];

	vector<int> d; d.push_back(b[1]);
	for(int i = 2 ; i <= n ; i ++ ) {
		if (b[i] > d.back()) d.push_back(b[i]);
		else {
			int pos = lower_bound(d.begin(), d.end(), b[i]) - d.begin();
			d[pos] = b[i];
		}
	}

  // dbug(d);
  for(int i = 0; i < d.size(); i ++) cout << d[i] << " \n"[i == d.size() - 1];
	cout << d.size() << endl; 

	// int n; cin >> n;
	// vector<int> a(n + 1), b(n + 1), pos_b(n + 1);
	// for(int i = 1; i <= n ;i ++ ) cin >> a[i];
	// for(int i = 1; i <= n ;i ++ ) cin >> b[i], pos_b[b[i]] = i;

	// if(a == b) {
	// 	cout << n << endl;
	// 	return; 
	// }

	// vector<int> dp(n + 1, 1);
	// for(int i = 1; i <= n; i ++ ) {
	// 	set<int> aa, bb;
	// 	for(int j = 1 ; j < i; j ++) aa.insert(a[j]);
	// 	for(int j = 1 ; j < pos_b[a[i]]; j ++) if(aa.count(b[j])) bb.insert(b[j]);
	// 	for(const auto &c : bb) {
	// 		dp[a[i]] = max(dp[a[i]], dp[c] + 1);
	// 	}
	// }
 
	// cout << *max_element(dp.begin() + 1, dp.end()) << endl; 

}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}

// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std ;

// #define int long long
// #define endl '\n'

// const int mod = 1e9 + 7 ; 
// const int maxn = 2e5 + 10 ;



// /*
// dp 的第一想法就是看 数据量更小的子问题是不是相同的求解方式 然后能不能扩展
// 然后思考怎么定义状态
// 数值是公共子序列长度
// 状态有 以某个元素为结尾? / 以某个位置为结尾 ? 
// 状态应该从当前元素 在两个数字中的前缀并集元素转移而来
// */

// signed main() {
    
// 	std::ios::sync_with_stdio(false) ;
// 	std::cin.tie(nullptr) ;
// 	std::cout.tie(nullptr) ;
	
// 	#ifdef GK
// 		freopen("INPUT.txt", "r", stdin) ;
// 		freopen("OUTPUT.txt", "w", stdout) ;
// 	#endif
	
// 	solve() ;
	
// 	return 0 ;
// }
