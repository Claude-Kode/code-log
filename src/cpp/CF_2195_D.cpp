// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

	int n; cin >> n;
	vector<int> vec(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> vec[i];
	}

	int sum = (vec[1] + vec[n]) / (n - 1);
	// cout << sum << endl; 
	int pre = 0; 
	vector<int> ans(n + 1);
	for (int i = 1 ; i < n; i ++ ) {
		int diff = vec[i + 1] - vec[i];
		int res = (diff + sum - 2 * pre) / 2;
		cout << res << ' ' ;
		ans[i] = res;
		pre += res;
	}	

	int m = 0 ;
	for(int i = 1 ; i <= n ; i ++ ) m += (i - 1) * ans[i];

	cout << (vec[1] - m) / (n - 1) << endl; 

}

signed main() {
	std::ios::sync_with_stdio(false) ;
	std::cin.tie(nullptr) ;
	std::cout.tie(nullptr) ;

	#ifdef GK
		freopen("INPUT.txt", "r", stdin) ;
		freopen("OUTPUT.txt", "w", stdout) ;
	#endif

	int tt ; cin >> tt ;
	while(tt --) solve() ;

	return 0;
}