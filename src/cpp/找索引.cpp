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
  int n, q; cin >> n >> q;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  while(q --) {
    int x; cin >> x;
    auto it = lower_bound(vec.begin() + 1, vec.end(), x);
    if (it == vec.end() || *it != x) {cout << -1 << endl;}
    else cout << it - vec.begin() << endl;
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