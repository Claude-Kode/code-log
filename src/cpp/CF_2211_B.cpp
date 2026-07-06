// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 676767677 ; 
const int maxn = 2e5 + 10 ;

void solve() {
  int x, y; cin >> x >> y;
  int diff = x - y;
  if (diff == 0) {
    cout << 1 << endl;
    for (int i = 0 ; i < x ; i ++) cout << 1 << ' ' ;
    for (int i = 0 ; i < y ; i ++) cout << -1 << ' ' ;
    cout << endl;
  } else {
    int n = abs(diff);
    int d = 0;
    int lim = sqrt(n);
    for (int i = 1; i <= lim; i ++ ) {
      if (n % i == 0) { d ++ ;
        if (i != n / i) d ++ ;
      }
    }
    cout << d % mod << endl ;
    for (int i = 0; i < x; i ++) cout << 1 << ' ' ;
    for (int i = 0; i < y; i ++) cout << -1 << ' ' ;
    cout << endl;
  }
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}
