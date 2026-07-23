// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {
  int b2, b1, a2, a1;
  cin >> b2 >> b1 >> a2 >> a1;

  auto chk = [&](int t) -> bool {
    int rem = t - (t & 1);
    // a  
    if (t - min(rem, a2 * 2) > a1) return false;
    // b
    if (t - min(rem, b2 * 2) > b1) return false;
    return true;
  };

  // 阴和阳分别是多少
  int l = 0, r = 1e9, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (chk(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }

  cout << ans * 2 << "\n";
} 
    
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
} 