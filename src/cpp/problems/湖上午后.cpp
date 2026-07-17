// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998244353; 
const int maxn = 2e5 + 10 ;

string bit(int x) {
  return bitset<5>(x).to_string() ;
  // str.substr(64 - __lg(n) - 1);
}

int fp(int x, int p, int mod) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

// 存在条件 : x % mod != 0 , x 逆元存在 即 x 不能是 mod 的整数倍
int inv (int x , int mod) { 
  return fp(x , mod - 2 , mod) ; 
}

void solve() { 

  auto q = [&](int x) -> int{
    int n = x; int res = 0 ;
    for (int i = n ; i >= 0 ; i --) {
      int len = __lg(i);
      for(int j = len ;j >= 0  ; j--) {
        if (i >> j & 1) cout << j << ' ' ;
        // cout << j << ' ' ; 
        // res += pow(2,j); 
      } 
      cout << endl; 
    }
    return res ;
  } ;
  cout << q(8) - q(3) << endl; 
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

  // for(int i = 1 ; i <= 16; i ++ ) cout << bit(i) << endl;

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}
