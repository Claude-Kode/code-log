// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int lcm(int a , int b) { 
  return a / __gcd(a , b) * b ; 
} 

void solve() { 

  int n; cin >> n;
  if (n == 2) {cout << 1 << endl;  return ;}
  // if (!(n & 1)) cout << (n / 2 - 1) * (n / 2 + 1) ;
  // else cout << (n / 2) * (n / 2 + 1);
  // cout << endl ;
  // for(int n = 1; n <= 1000; n ++) {
  //   int l = 1, r = 1, ans = 0;
  //   for(int i = 1; i < n; i ++) if (ans < lcm(i, n - i)){
  //     l = i, r = n - i, ans = lcm(i, n - i);
  //   }



  //   // if (!(ll * rr == ans && ll == l && rr == r)) {
  //   //   cout << "NO" << endl; 
  //   //   cout << "N: " << n << endl; 
  //   //   cout << l << ' ' << r << ' ' << ans << endl; 
  //   //   cout << ll << ' ' << rr << ' ' << ll * rr << endl; 
  //   // }

  //   // cout << "n: " << n << endl << n / 2 << ' ' << l << ' ' << r << endl << endl;
  // }

  int ll = 1, rr = 1;
  if (!(n & 1)) ll = n / 2 - 1, rr = n / 2 + 1;
  else ll = n / 2, rr = n / 2 + 1;

  while (__gcd(ll, rr) > 1) ll -- , rr ++ ;

  cout << ll * rr << endl; 

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
