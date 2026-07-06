// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 
 
  int n ; cin >> n ; 
  vector<vector<int>> vec(n + 1) ; set<int, greater<int>> s ; 
  for ( int i = 1 ; i <= n ; i ++ ) {
    int sz , temp ; cin >> sz ; 
    for ( int j = 1 ; j <= sz ; j ++ ) {
      cin >> temp ; 
      s.insert( temp ) ; 
      vec[i].push_back( temp ) ;
    }
    reverse(vec[i].begin() , vec[i].end()) ;
  }

  for (int i = 1 ; i <= n ; i ++) {
    vector<int> temp ; unordered_map<int, int> ump ; 
    for (auto &a : vec[i]) if ( !ump[a] ) {
      temp.push_back( a ) , ump[a] ++ ;  
    }
    vec[i] = temp ; 
  }

  vector<vector<int>> ans ; unordered_map<int, int> vis ; 
  for ( int i = 1 ; i <= n ; i ++ ) {
    auto vv = min_element(vec.begin() + 1 , vec.end()) ; 
    vector<int> &v = *vv ; 
    // if ( v[0] == INT_MAX ) cout << "NMBD" << endl ; 
    ans.push_back( v ) ;
    for ( const auto& a : v ) vis[a] ++ ; 
    v.assign(1 , INT_MAX) ; 
    for ( int j = 1 ; j <= n ; j ++ ) if ( vec[j][0] != INT_MAX ) {
      vector<int> temp ; 
      for ( auto &a : vec[j] ) if ( !vis[a] ) temp.push_back( a ) ; 
      vec[j] = temp ; 
    }
  }

  for ( const auto & row : ans ) {
    for ( const auto &x : row ) {
      cout << x << ' ' ; 
    }
  } 

  cout << endl ; 

}

/*
最后的结果一定是一个排列 , 这个有啥用吗 或许是
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

int lcm(int a , int b) { return a / gcd(a , b) * b ; } 

int inv (int x , int mod) { return fp(x , mod - 2 , mod) ; }

void dedup(vector<int>& vec ) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}
