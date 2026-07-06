// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 998244353; 
const int N = 2e5 + 10;

void solve() { 
  string s; cin >> s;
  int n = s.size();
  s = " " + s;
  unordered_map<char, int> ump;
  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    int temp = (ans - ump[s[i]] + 1 + mod) % mod;
    (ans += temp) % mod;
    (ump[s[i]] += temp) %= mod;
  }

  cout << ans % mod << endl; 
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}