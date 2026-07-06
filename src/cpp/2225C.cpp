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
  string a, b; cin >> a >> b;
  vector<int> dp(n + 1); dp[1] = (a[0] != b[0]);
  for(int i = 2; i <=  n; i ++) {
    dp[i] = min(dp[i - 1] + (a[i - 1] != b[i - 1]), dp[i - 2] + (a[i - 1] != a[i - 2]) + (b[i - 1] != b[i - 2]));
  }

  cout << dp[n] << endl; 
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