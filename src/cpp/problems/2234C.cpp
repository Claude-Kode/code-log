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

  for (int i = 1; i <= n; i ++) {
    vec.push_back(vec[i]);
    // 每次从较小的一段开始, 一直遍历到第一个下一个比当前赋值大的, 停止
    int l = i, r = i + n - 1;

    // cout << "init: \n";
    // dbug(l, r);

    int cnt = 0, ans = 0;
    while (l < r) {
      int cur = min(vec[l], vec[r]);
      if (vec[l] < vec[r]) {
        do {
          ans += cur;
        } while (++l < r and vec[l] <= cur);
        // while (vec[++l] <= cur) {
        //   ans += cur;
        // }
      } else {
        do {
          ans += cur;
        } while (l < --r and vec[r] <= cur);
      }
      // cout << "cur: \n";
      // dbug(l, r);
    }
    // cout << "\n";
    // cout << "ans: " 
    cout << ans << " \n"[i == n];
  }

} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}