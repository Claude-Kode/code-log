// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;



void solve() { 

  int n; cin >> n; map<int, bool> mp;
  // cout << n << ' ' ;
  // function <bool(int)> dfs = [&](int n) -> bool {
  //   bool &res = mp[n];
  //   if (n == 9) return res = true;
  //   if (mp.count(n)) return res;

  //   int lb = n % 10; n /= 10;
  //   if (lb == 0 || lb == 2 || lb == 4 || lb == 5 || lb == 8) {
  //     return false ;
  //   } else {
  //     for(int i = 1 ; i <= 9; i ++) {
  //       int num = i * lb; 
  //       if (num % 10 == 9 && dfs(n + num / 10)) return res = true;
  //     }
  //   }
  //   return res = false; 
  // };

  int lb = n % 10;
  if (lb == 0 || lb == 2 || lb == 4 || lb == 5 || lb == 8) {
    cout << "NO" << endl; }
  else cout << "YES" << endl; 

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
