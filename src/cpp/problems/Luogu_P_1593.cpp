// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 9901; 
const int maxn = 2e5 + 1;

int fp(int x, int p, int mod) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

int inv (int x , int mod) { 
  return fp(x, mod - 2, mod) ; 
}

vector<int> prime(int n) {
  vector<int> vis(maxn , 0) , pr ; 
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
  return pr ; 
}

map<int, int> prime_factor(int a, vector<int>& pr) {
  map<int, int> factors;
  for (const auto &x : pr) if(a % x == 0) {
    while (a % x == 0) factors[x] ++, a /= x;
    if (a < x) break;
  }
  if (a > 1) factors[a]++;
  return factors;
}

void solve() { 

  int a, b; cin >> a >> b;
  auto pr = prime(1e4 + 1);
  auto mp = prime_factor(a, pr);
  
  int res = 1;
  for (auto &[v, p] : mp) { 
    p *= b; 
    if(v % mod == 1) {
      res = res * (p + 1) % mod % mod;
    } else {
      int num = (fp(v, p + 1, mod) - 1 + mod) % mod , den = inv((v + mod - 1) % mod, mod);
      res = res * num * den % mod;
    }
  }

  cout << res << endl; 

}

/*
分解质因数基本都是一个重要的手段了
通过搞出质因数的个数 可以通过等比数列搞出他的所有因子 而且还是没有重复的搞出来 
重点是没有重复
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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}
