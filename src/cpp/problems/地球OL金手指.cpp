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
  int n, k, t; cin >> n >> k >> t;

  // 买 k 瓶 得到 k + 1 瓶
  int std = (k / 2) * (t + 1) + (k % 2) * t;

  if (std <= 0 && n >= std || t <= 1 && n >= 2) {cout << -1 << endl; return;} 

  function<int(int)> calc = [&](int m) -> int {
    int ans = 0;
    if (m >= std + 1) {
      ans = n / (std + 1) * (k + 2);
      n %= (std + 1);
      ans +=  calc(n);
    } else if (m == std) {
      return k + 1;
    } else if (m == t + 1) {
      return 2;
    } else if (m  == t) {
      return 1;
    } else return 0;
  };

  // 买 k + 2 瓶水要多少钱

  cout << calc(n) << endl;
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