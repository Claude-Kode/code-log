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
  int n, m; cin >> n >> m;
  vector<vector<int>> vec(n + 1, vector<int>(m + 1));
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      cin >> vec[i][j];
    }
  }

  for(int i = 1; i <= n; i ++) {
    ranges::sort(vec[i]);
  }

  cout << accumulate(vec[1].begin(), vec[1].end(), 0LL) << endl;
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