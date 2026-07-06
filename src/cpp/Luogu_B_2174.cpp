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

  int n , m ; cin >> n >> m ;
  vector<int> w(n + 1) , v(n + 1) ;
  for ( int i = 1 ; i <= n ; i ++ ) {
    cin >> w[i] >> v[i] ; 
  }

  vector<int> dp(m + 1) ; 
  for (int i = 1 ; i <= n ; i++ ) {
    for (int j = w[i] ; j <= m ; j ++ ) {
      dp[j] = max(dp[j - w[i]] + v[i] , dp[j]) ;
    }
  }

  cout << *max_element(dp.begin() , dp.end()) << endl ; 

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

  int tt ;cin >> tt ;
  while ( tt -- ) {
    int n; cin >> n ;
    string str ; cin >> str ;
    for( auto &c : str) 
    int start = 0 ; 
  
  }

  // cout << fixed << setprecision(6) ;
  solve() ;
  
  return 0 ;
}
