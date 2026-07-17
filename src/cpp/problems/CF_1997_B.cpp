// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 

  int n; cin >> n;
  string r1, r2; cin >> r1 >> r2;
  
  if (r1 == r2) {
    cout << 0 << endl;
    return ;
  }

  int ans = 0;
  for(int i = 1 ; i  < n - 1; i ++) {
    if (r2[i] == '.' && r2[i - 1] == 'x' && r2[i + 1] == 'x' && r1[i] == '.' && r1[i - 1] == '.' && r1[i + 1] == '.') {
      ans ++;
    }
    if (r1[i] == '.' && r1[i - 1] == 'x' && r1[i + 1] == 'x' && r2[i] == '.' && r2[i - 1] == '.' && r2[i + 1] == '.') {
      ans ++ ;
    }
  }

  cout << ans << endl; 

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
