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
  int x, y; cin >> x >> y;
  if (y < 45) cout << 0.0 << endl; 
  else {
    int res =  (6 * x + 4 * y + 9) / 10 ;
    if (res >= 95) cout << 5.0 << endl; 
    else if (res >= 60) cout << 5 - 0.1 * (95 - res) << endl; 
    else cout << 0.0 << endl; 
  }
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

  cout << fixed << setprecision(1);

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}
