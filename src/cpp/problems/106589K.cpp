// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {
  int n; cin >> n;
  vector<int> vec(n + 1); 
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  auto v = vec;
  vector<int> stk(1, n), ans(n + 1, 0);
  ans[n] = vec[n] * vec[n];
  for (int i = n - 1; i > 0; i --) {
    while (stk.size() and vec[stk.back()] + stk.back() < vec[i] + i) {
      stk.pop_back();
    }

    // cout << "1: " << i << ' ' << (stk.size() ? stk.back() : 0) << "\n";
    int dis = (stk.size() ? (stk.back() - i) : vec[i]);
    dis = min(dis, vec[i]);
    // dbug(dis);  
    ans[i] = ans[stk.size() ? stk.back() : 0] + (vec[i] + vec[i] - dis) * dis;
    stk.push_back(i);
  }

  for (int i = 1; i <= n; i ++) {
    cout << ans[i] << "\n";
  }
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}