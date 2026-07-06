// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 

  int n ; cin >> n ; 
  vector<int> a(n + 1) , b(n + 1) ; 
  for ( int i = 1 ; i <= n ; i ++ ) {
    cin >> a[i] ; 
  }

  for ( int i = 1 ; i <= n ; i ++ ) {
    cin >> b[i] ; 
  }

  int o = 0 , t = 0 ; 
  int p = 0 , s = 0 ; 
  for ( int i = 1 ; i <= n ; i ++ ) {
    if ( a[i] == 1 && (b[i] == 0 || b[i] == -1) ) o ++ ;
    else if ( (a[i] == 0 || a[i] == -1) && b[i] == 1 ) t ++ ; 
    else if ( a[i] == b[i] && b[i] == 1  ) p ++ ; 
    else if ( a[i] == b[i] && b[i] == -1 ) s ++ ; 
  }

  int res = (o + t + p - s) ; 
  if ( min(o , t) + p + s >= max(o , t) ) {
    if ( res >= 0 ) cout << res / 2 << endl ;
    else cout << (res - 1) / 2 << endl ; 
  } else {
    cout << min(o , t) + p << endl ; 
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

  int tt ; cin >> tt ;
  while(tt --) solve() ;
  
  return 0 ;
}

// Functions : 

int fp( int x , int p , int mod) {
  int res = 1 , base = x ; 
  while ( p ) {
    if ( p & 1 ) (res *= base) %= mod ; 
    (base *= base) %= mod ; 
    p >>= 1 ;
  }
  return res ; 
}

int lcm(int a , int b) { return a / gcd(a , b) * b  ; } 

int inv (int x , int mod) { return fp(x , mod - 2 , mod ) ; }

void dedup(vector<int>& vec ) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}
