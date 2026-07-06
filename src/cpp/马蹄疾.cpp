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

  int n, t, s; cin >> n >> t >> s;
  // cout << (1 << t) << endl; 
  if (n * ((1 << t) - 1) >= s) cout << "Yes" << endl; 
  else cout << "No" << endl; 

} 

/*
眼睛瞎了没看见小于号
43min
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