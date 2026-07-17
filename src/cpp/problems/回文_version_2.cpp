// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  string s; cin >> s;
  int n = s.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    if (s[l] == s[r]) l ++, r --;
    else if (s[l] == 'n' && s[r] == 'm' && s[l + 1] == 'n') {
      l += 2, r --;
    } else if (s[l] == 'm' && s[r] == 'n' && s[r - 1] == 'n') {
      r -= 2, l ++;
    } else {
      cout << "NO" << endl;
      return; 
    }
  }

  cout << "YES" << endl; 
}
/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}