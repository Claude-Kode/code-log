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

	int n, m; cin >> n >> m;
	vector<vector<int>> vec(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> vec[i][j];
		}
		sort(vec[i].begin() + 1, vec[i].end());
	}

	int mn = 0;
	for(int i = 1; i <= n; i ++) {
		auto it = upper_bound(vec[i].begin() + 1, vec[i].end(), mn);
		if (it == vec[i].end()) {
			cout << "NO" << endl; 
		}
		mn = *it;
	}

	cout << "YES" << endl;
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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}