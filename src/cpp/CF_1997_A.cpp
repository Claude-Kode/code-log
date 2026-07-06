// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 

  string s; cin >> s;
  int id = -1, n = s.size();
  for(int i = 1 ; i < n ; i ++ ) {
    if (s[i] == s[i - 1]) {
      id = i; break ; 
    }
  }

  // if (id == -1) cout << 0 << endl; 

  if (id == -1) {
    cout << s ;
    if (s.back() == 'a') cout << 'z';
    else cout << 'a' ;
    cout << endl; 
  } else {
    for(int i = 0; i < id ; i ++) cout << s[i];
    if ( s[id] == 'a') cout << 'z' ;
    else cout << 'a';
    for(int i = id ; i < n ; i ++ ) cout << s[i];
    cout << endl; 
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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}
