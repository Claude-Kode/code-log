// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 998244353; 
const int N = 1e6 + 10;



void solve() { 

	int n; cin >> n;
	// cout << dp[n] << endl; 

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

	vector<int> dp(N + 1); dp[1] = 1; dp[2] = 2; dp[3] = 4; dp[4] = 6;
	for(int i = 5; i <= N; i ++) {
		if (i & 1) dp[i] = dp[i - 3] + dp[3];
		else dp[i] = dp[2] + dp[i - 2];
		dp[i] %= mod;
	}
	
	for(int i = 1; i <= 10; i ++) cout << dp[i] << ' ' ;
	cout << endl;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}


