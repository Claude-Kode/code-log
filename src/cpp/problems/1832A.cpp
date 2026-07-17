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

  unordered_map<char,int> ump;
  string s; cin >> s; int n = s.size();
  if (n == 1) {
    cout << "NO" << endl; 
    return; 
  }
  for(const char c : s) ump[c] ++;
  int cnt = 0;
  for(auto [k, v] : ump) cnt += (v >= 2);
  if (cnt >= 2) cout << "YES" << endl; 
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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}