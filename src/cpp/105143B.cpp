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

const int B = 60;

// 从另一个方面来想, 就是构造 n 个数字, 每个都是答案的子集
// 维护和等于 sum 即可
// 相当于是把 sum 分块 每个 x 都是或起来的子集
// 然后就相当于转化成拼块问题 ?
void solve() {
  int n, S = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    S += x;
  }

  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int b = (1 << i);
    if (S > (b - 1) * n) {
      for (int j = 1; j <= n; j++) {
        if (S < b) break;
        S -= b;
      }
      ans += (1 << i);
    }
  }

  cout << ans << "\n";
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