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

auto h = [](int num) -> int{
  int res = 0;
  while(num) {
    int d = num % 10;
    if (d == 0 || d == 6 || d == 9) res ++;
    else if (d == 8) res += 2;
    num /= 10;
  }
  return res;
};

void solve() { 
  int n; cin >> n;
  int ans = 0;
  // log{10}\{1e18} == 18 
  for(int i = n; i <= (n + 40); i ++) {
    if (i - h(i) == n) ans ++;
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