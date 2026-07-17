// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  vector<string> s = {
    "*****...******...***...**...**....**",
    "**......**.......****..**...**....**",
    "*****...**.......**.**.**...**....**",
    "...**...**.......**..****...**....**",
    "*****...******...**...***...********"
  };
  int k; cin >> k;
  for(int i = 0; i < 5; i ++ ) {
    for(int tim = 1; tim <= k; tim ++) {
      for(const char &c : s[i]) {
        for(int j = 1; j <= k; j ++) cout <<c;
      }
      cout << '\n';
    }
  }
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
