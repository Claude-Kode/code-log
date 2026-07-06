#pragma GCC optimize("Ofast,fast-math")
#pragma GCCtarget("avx,avx2")
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
  int n, q; cin >> n >> q;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  auto check = [&](int t, int x) -> bool {
    int m = 0;
    for(int i = 1; i <= n; i ++) {
      if (a[i] > a[t]) m += a[i] - a[t];
    }
    return m <= x;
  };

  while(q --) {
    int x; cin >> x;
    int l = 1, r = n, ans = l;
    while(l <= r) {
      int mid = (l + r) / 2;
      if (check(mid, x)) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    cout << ans << endl;
  }
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