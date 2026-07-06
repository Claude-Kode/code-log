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
  vector<int> vec(n + 1) ; 
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  vector<int> son(n + 1);
  for (int i = 1; i < n; i++) {
    int u , v ; cin >> u >> v;
    son[u] = v ; 
  }

  vector<int> subsum(n + 1) , dep(n + 1) ; dep[1] = 0 ;
  auto dfs = [&](int u) -> int {
    dep[son[u]] = dep[u] + 1 ;
    if ( son[u] == 0 ) return subsum[u] = vec[u] ; 
    else return subsum[u] += vec[u] + dfs(son[u]) ;
  } ; 
  
  dfs(1) ; 
  int sum = accumulate(subsum.begin() + 1 , subsum.end() , 0LL) , ans = INT_MAX ; 
  for ( int i = 1 ; i <= n ; i ++ ) {
    ans = min(ans , sum - (dep[i] - 1) * subsum[i] ) ;
  }

  cout << ans << endl ; 

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


