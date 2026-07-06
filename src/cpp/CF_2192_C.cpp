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

  int n , h , k ; cin >> n >> h >> k ; 
  vector<int> vec(n + 1) ; 
  for (int i = 1 ; i <= n ; i++) {
    cin >> vec[i];
  }

  int sum = accumulate(vec.begin() + 1 , vec.end() , 0LL) ; 
  int ans = h / sum * (k + n) ;
  
  // cout << ans << endl ; cout << sum << endl ; 

  if ( !(h % sum)) {
    cout << ans - k << endl ;
    return ;
  }

  vector<int> sufmx(n + 1); int mx = 0;
  for ( int i = n ; i > 0 ; i -- ) {
    mx = max(mx , vec[i]) , sufmx[i] = mx ; 
  }

  int mn = INT_MAX , pre = 0 ; 
  for ( int i = 1 ; i <= n - 1 ; i ++ ) {
    mn = min(mn , vec[i]) ; pre += vec[i] ; ans ++ ; 
    int temp = max(pre , pre - mn + sufmx[i + 1] ) ; 
    if ( temp >= h % sum ) {
      cout << ans << endl ; return ; 
    }
  }

  // cout << endl ;
  cout << ans + 1 << endl ; 

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


