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

int getId(int x, vector<int>& vec){
  return lower_bound(vec.begin() + 1, vec.end() , x) - vec.begin();
}

string bit(int x) {
  return bitset<32>(x).to_string() ;
  // str.substr(64 - __lg(n) - 1);
}

void solve() { 

  int n ; cin >> n ; 
  vector<vector<int>> vec(n + 1, vector<int>(n + 1, 1));
  for(int i = 1; i <= n ; i ++ ) vec[i][1] = (i + 1);
  for(int j = 2; j <= n ; j ++ ) vec[1][j] = (j + n); 

  vec[1][1] = 1; vec[n][n] = 2;

  cout << "Yes" << endl; 
  for(int i = 1 ; i <= n ; i++) {
    for(int j = 1; j <= n ; j++) {
      cout << vec[i][j] << ' ';
    } cout << endl;
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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0 ;
}
