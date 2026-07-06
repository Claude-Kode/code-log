// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 

  string s; cin >> s; int n = s.size();
  for(int i = 0; i < n; i ++) {
    if (s[i] == '?') {
      if (i == 0) s[i] = '0';
      else s[i] = s[i - 1];
    }
  }
 
  cout << s << endl;
}
/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  int tt ; cin >> tt;
  while ( tt-- ) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}