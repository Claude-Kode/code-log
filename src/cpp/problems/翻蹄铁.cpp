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
  int n, q; cin >> n >> q;
  string s; cin >> s; s = " " + s;
  vector<int> pre(n + 1), plus(n + 1), minus(n + 1);
  for(int i = 1; i <= n; i ++) {
    pre[i] = pre[i - 1] + (s[i] == '+');
    plus[i] = plus[i - 1] + (s[i] == '+' ? i : 0);
    minus[i] = minus[i - 1] + (s[i] == '-' ? i : 0);
  }

  int ans = 0;
  for(int i = 1; i <= q; i ++) {
    int l, r; cin >> l >> r;
    int cnt = pre[r] - pre[l - 1];
    int p = plus[r] - plus[l + cnt - 1];
    int m = minus[l + cnt - 1] - minus[l - 1];
    ans ^= cnt + 2 * (p - m);
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
