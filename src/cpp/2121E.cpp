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
  string l ,r; cin >> l >> r;
  // cout << l << ' ' << r << endl; 
  int ans = 0, n = l.size(); bool f = false;
  for(int i = 0; i < n; i ++) {
    if (l[i] == r[i]) {
      // cout << "t1" << endl; 
      ans += 2;
    } else if (l[i] < r[i] - 1) {
      break;
    } else if (l[i] == r[i] - 1) {
      ans ++;
      for(int j = i + 1; j < n; j ++) {
        // if (l[j] == r[j]) ans += 2;
        if (r[j] == '0' && l[j] == '9') {
          ans ++;
        } else {
          cout << ans << endl; 
          // cerr << 1 << ' ' ;
          return; 
        }
      }
      // 这一步只能选择比 等于 l[i] 吗
    }
  }
  std::cout << ans << endl; 
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
