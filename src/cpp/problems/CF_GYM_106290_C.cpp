// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

vector<int> pr; 

void prime(int n) {
  vector<int> vis(maxn , 0); 
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
  // return pr ; 
}
void solve() { 

  int a, b; cin >> a >> b;

  int ca = 0, cb = 0;
  for(const auto &x : pr) {
    // if (x > a) break; 
    while (a % x == 0) ca ++ , a /= x;
  }

  for(const auto &x : pr) if (b % x == 0) {
    // if (x > b) break; 
    while (b % x == 0) cb ++ , b /= x;
  } 

  // if ()
  // cout << ca << ' ' << cb << endl ;
  if (a != 1) ca ++ ;
  if (b != 1) cb ++ ;

  if (ca ^ cb) cout << "Yes" << endl; 
  else cout << "No" << endl; 

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

  prime(2e5 + 1);

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}
