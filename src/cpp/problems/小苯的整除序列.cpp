// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() {
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) cin >> vec[i];
  
  vector<int> dp(n + 10, 0);  

  for(int i = 1; i <= n; i ++) {
    vector<int> fac; int lim = sqrt(vec[i]);
    for(int j = 1; j <= lim; j ++) {
      if(vec[i] % j == 0) {
        if(j <= n + 1) fac.push_back(j);
        int a = vec[i] / j; 
        if(a != j && a <= n) fac.push_back(a);
      }
    }
    
    sort(fac.begin(), fac.end(), greater<int>());
    
    for(const int &len : fac) {
      if(len > 1) {
        dp[len] = max(dp[len], dp[len - 1] + 1);
      } else {
        dp[1] = max(dp[1], 1LL);
      }
    }
  }
  
  int ans = 0;
  for(int i = 1; i <= n + 1; i ++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}