// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;



void solve() { 

  int hh1, mm1, hh2, mm2, n; char c; 
  cin >> hh1  >> c >> mm1 >> hh2 >> c >> mm2 >> n;

  // cout << hh1 << mm1 << hh2 << mm2 << n << endl; 

  int m = (hh2 - hh1) * 60 + mm2 - mm1;
  vector<int> dp(m + 1, 0);
  for(int i = 1 ; i <= n ; i ++ ) {
    int w , v , c ; cin >> w >> v >> c;
    if (c == 0) c = (m + w - 1) / w;
    for(int j = 1 ; j <= c ; j ++ ) 
      for(int k = m ; k >= w ; k -- ) 
        dp[k] = max(dp[k], dp[k - w] + v); 
  }

  cout << dp[m];

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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}
