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

void solve() { 

  int n ; cin >> n ; 
  string str ; cin >> str ; 
  int cnt1 = 0  ; vector<int> i0 , i1 ; 
  for (int i = 0 ; i < n; i ++) {
    cnt1 += (str[i] == '1') ; 
    if ( str[i] == '0' ) i0.push_back(i + 1) ; 
    else i1.push_back(i + 1) ; 
  }

  int cnt0 = n - cnt1 ; 
  if ( cnt1 == 0 ) { cout << 0 << endl ; return ; }

  if ( !(cnt1 & 1) ) {
    cout << i1.size() << endl ; 
    for (const auto &a : i1) cout << a << ' ' ; 
    cout << endl ; 
  } else if ( cnt0 & 1 ) {
    cout << i0.size() << endl ;  
    for (const auto &a : i0) cout << a << ' ' ; 
    cout << endl ; 
  } else {
    cout << -1 << endl ; 
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


