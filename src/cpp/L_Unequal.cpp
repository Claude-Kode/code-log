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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() { 
  int n, p; cin >> n >> p;
  if (n >= 3 * p) {cout << -1 << endl; return;}
  vector<int> ans(n + 1);
  auto check = [&](const auto &a) -> {
    
  };
  iota(ans.begin(), ans.end(), 0);
  shuffle(ans.begin() + 1, ans.end(), rng);
  for(int i = 1; i <= n; i ++) cout << ans[i] << " \n"[i == n];
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