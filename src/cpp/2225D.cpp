// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 998244353; 
const int N = 2e5 + 10;



// [l, r] === m(mod 4)
void solve() { 
  int n, x; cin >> n >> x;

  auto calc = [&](int l, int r, int m) -> int {
    l --;
    int res1 = (r < m ? 0 : (r - m) / 4 + 1);
    int res2 = (l < m ? 0 : (l - m) / 4 + 1);
    return res1 - res2;
  };

  int l1 = calc(1, x - 1, 1);
  int l0 = calc(1, x - 1, 3);
  int r1 = calc(x, n, 1);
  int r0 = calc(x, n, 3);
  // cout << l0 << " " << r0 << endl; 
  // cout << l1 << " " << r1 << endl; 
  // if (x % 4 == 3) 
  int ans = 0;
  ans = (ans + (l0 % mod) * (r0 % mod) % mod) % mod;
  ans = (ans + (l1 % mod) * (r1 % mod) % mod) % mod;
  ans = (ans + r0 % mod) % mod;
  cout << ans % mod << endl;
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
    // cout << "TEST CASE: " << CNT << endl,
    solve();
  
  return 0;
}