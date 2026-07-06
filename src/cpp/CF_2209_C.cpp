// @Author : GoryK
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

int q(int a , int b) {
  cout << "? " << a << ' ' << b << endl ; cout.flush() ; 
  int ans ; cin >> ans ; return ans ;
} 

void put_ans(int a) {
  cout << "! " << a << endl ; cout.flush() ;
} 

void solve() { 

  int n ; cin >> n ;
  for ( int x = 2 ; x <= 2 * n - 2 ; x += 2 ) if ( q(x , x + 1) )  { put_ans(x) ; return ; }
  if ( q(1 , 2) ) { put_ans(1) ; return ; }
  if ( q(1 , 3) ) { put_ans(1) ; return ; }
  put_ans(2 * n) ; 

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

  int tt ; cin >> tt ;
  while(tt --) solve() ;
  
  return 0 ;
}


