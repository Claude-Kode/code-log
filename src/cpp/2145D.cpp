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
  int n; cin >> n;
  vector<int> vec(n + 1);
  iota(vec.begin() + 1, vec.end(), 1LL);
  shuffle(vec.begin() + 1, vec.end(), rng);
  dbug(vec);
  int ans = 0;
  for(int i = 1; i < n; i ++) {
    for(int j = i + 1; j <= n; j ++) {
      if (vec[i] > vec[j]) cout << i << ' ' << (n - j + 1) << "\n",
      ans += (i * (n - j + 1));
    }
  }

  cout << ans << endl; 
}

/*
我想的思路全部都是 毫无根据的
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