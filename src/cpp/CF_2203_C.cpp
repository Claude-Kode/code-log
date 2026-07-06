// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
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

string bit(int x) {
  return bitset<32>(x).to_string() ;
}

void solve() { 

  int s , m ; cin >> s >> m; 
  
  auto check = [&](int test) -> bool {
    int f = 0;
    for (int i = 62; i >= 0; i--) {
      f >>= 1;
      f += (s >> i & 1);
      f -= (m >> i & 1) * min(test, f);
    }  
    return f == 0;
  };

  int l = 0 , r = LLONG_MAX, ans = -1; 
  while ( l <= r ) {
    int mid = (l + r) / 2;
    if ( check(mid) ) r = mid - 1 , ans = mid ;
    else l = mid + 1;
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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) {
    // cout << "TEST CASE : " << CNT << endl;
    solve();
  }
  
  return 0 ;
}
