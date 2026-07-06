// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n; cin >> n;
  vector<string> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    // cout << vec[i] << " \n"[i == n];
    for(char &c : vec[i]) {
      ans -= ('9' - c);
      c = '9';
    }
    ans += stoi(vec[i]);
  }

  cout << ans << endl;  
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}