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
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  unordered_map<int, int> ump;
  unordered_map<int, vector<int>> val;
  // ump[i] 从 i 往前面数 vec[i] 个和他相等的数 的位置
  for(int i = 1; i <= n; i ++) {
    val[vec[i]].push_back(i);
    int m = val[vec[i]].size();
    // cout << m << endl;
    if (m - vec[i] + 1 > 0) ump[i] = val[vec[i]][m - vec[i]];
  }

  // dbug(vec);
  // for(int i = 1; i <= n; i ++) {
  //   cout << "POS: " << i << ' ' << " VAL: " << vec[i] << ' ' << " PRE: " << ump[i] << '\n';
  // }
  
  vector<int> dp(n + 1);
  for(int i = 1; i <= n; i ++) {
    int j = ump[i];
    if (j > 0) dp[i] = vec[i] + dp[j - 1];
    dp[i] = max(dp[i], dp[i - 1]);
  }

  cout << dp[n] << '\n';
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