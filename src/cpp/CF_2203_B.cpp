// @Autr : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

// Functions : 

int fp( int x , int p , int mod) {
  int res = 1 , base = x ; 
  while ( p ) {
    if ( p & 1 ) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

int lcm(int a , int b) { 
  return a / gcd(a , b) * b ; 
} 

int inv (int x , int mod) { 
  return fp(x , mod - 2 , mod) ; 
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

void dedup(vector<int>& vec ) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}

void solve() { 

  string num ;  cin >> num ; 

  vector<int> digs ;
  for ( const auto &c : num ) if ( c - '0' ) {
    digs.push_back(c - '0') ; 
  }

  int sum = accumulate(digs.begin() , digs.end() , 0LL) ; 
  if ( sum <= 9 ) {
    cout << 0 << endl ; return ; 
  } 

  if ( digs[0] > 1 ) digs[0] -- ; 

  sort(digs.begin() , digs.end() , greater<int>()) ; 

  int temp = 0 ;
  for ( int i = 0 ; i < digs.size() ; i ++ ) {
    temp += digs[i] ; 
    if (sum - temp <= 9) { cout << i + 1 << endl ; return ; }
  } 

}

/*
我的策略就是直接把一开始的数字变成个位数

应该算的是每一位的贡献 是贡献 算的他妈是贡献
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

  int tt ; cin >> tt ;
  while(tt --) solve() ;
  
  system("pause") ;

  return 0 ;
}

