// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 

  int n ; cin >> n ;

  vector<vector<int>> adj(n + 1) ;
  vector<int> vals(n + 1) , ans(n + 1) , seq(n + 1) ; 
  std::iota(seq.begin() + 1 , seq.end() , 1LL) ; 
  for ( int i = 2 ; i <= n ; i ++ ) {
    // temp 的儿子是 i
    int temp ; cin >> temp ; adj[i].push_back( temp ) ;
  }

  for ( int i = 1 ; i <= n ; i ++ ) cin >> vals[i] ;
  sort(seq.begin() + 1 , seq.end() , [&](int a , int b){
    return vals[a] < vals[b] ; 
  }) ; 

  // for ( int i = 1 ; i <= n ; i ++ ) cout << vals[seq[i]] << ' ' ; 
  // cout << endl ; 

  auto BFS = [&](int i) -> void {
    queue<int> q ; q.push( i ) ; 
    if ( ans[i] == vals[i] ) ans[i] ++ ;  
    while ( !q.empty() ) {
      auto &u = q.front() ; q.pop() ;
      if ( ans[u] == vals[i] ) ans[u] ++ ;  
      for ( auto &v : adj[u] ) {
        q.push( v ) ; 
      }
    }
  } ;   

  for ( int i = 1 ; i <= n ; i ++ ) BFS(seq[i]) ;
  for ( int i = 1 ; i <= n ; i ++ ) cout << ans[i] << ' ' ;
  
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

  solve() ;
  
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
