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
  int n;
  cin >> n;
  vector<int> ans(4 * n);

  iota(ans.begin(), ans.begin() + n + 1, 1LL);
  for (int i = 0; i < n; i ++) ans[n + i] = i + 1;
  for (int i = 0; i < n; i ++) ans[2 * n + i] = (i + 1) % n + 1;  
  for (int i = 0; i < n; i ++) ans[3 * n + i] = i + 1;

  for (int i = 0; i < 4 * n; i ++) {
    cout << ans[i] << " \n"[i == 4 * n - 1];
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

