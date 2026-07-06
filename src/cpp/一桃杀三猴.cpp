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
  auto check = [&](int x, int v) -> bool {
    for(int i = 1; i <= x; i ++) {
      v -= 1; 
      if (v % x) {return false;}
      (v /= x) *= (x - 1);
    }
    return true;
  };
  for(int i = 1; i <= 9; i ++) {
    for(int ans = 10; ans <= 1e9; ans ++) {
      if (check(i, ans)) {
        cout << ans << ", ";
        break;
      }
    }

    // int ans = (i * i  - 1) * i + 1;
    // cout << "q: " << i << endl;
    // cout << check(i, ans) << endl;
  }
  // vector<int> ans = {10, 11, 25, 253, 3121, 46651, 823537, 16777209, 387420481};
  // cout << ans[n - 1] << endl;
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