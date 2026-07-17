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
  int n; cin >> n;
  int m = sqrt(n);
  if (m * m != n) {cout << "NO" << endl; return; }
  string s1 = to_string(n);
  string s2 = to_string(m);

  // cout << n << ' ' << m << endl; 

  string temp1 = s1; 
  reverse(temp1.begin(), temp1.end());
  string temp2 = s2;
  reverse(temp2.begin(), temp2.end());

  if (temp2 == s2 && temp1 == s1) cout << "YES" << endl; 
  else cout << "NO" << endl;
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

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}