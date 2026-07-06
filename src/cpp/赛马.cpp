// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() {
  int n, ans = 0; cin >> n;
  for (int k = 1; (1LL << k) <= n; k++) {
    int max_l = n / (1LL << k);
    int L = (n + 1) / (1LL << (k + 1));
    int p1 = (1 << k) * (L + 1) * L / 2, p2 = 0;
    if (L < max_l) {
      int len = max_l - L;
      int sum = (L + 1 + max_l) *  len / 2;
      p2 = (n + 1) * len - (1 << k) * sum;
    }
    ans += k * (p1 + p2);
  }

  cout << ans << endl;
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
