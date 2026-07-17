// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
// #define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n; cin >> n;

  auto check = [&](int t) -> bool {
    cout << "? " << (1 << t) << endl;
    // cout.flush();
    int res; cin >> res;
    return res;
  };

  int l = 0, r = __lg(n) + 1, q = 1, ans = 0;
  while(l <= r && q < 5) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid -= 2;
    else l = mid += 2, ans = mid;
    q ++ ;
  }

  cout << "! " << max(1, (1 << ans)) << endl;
} 

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}