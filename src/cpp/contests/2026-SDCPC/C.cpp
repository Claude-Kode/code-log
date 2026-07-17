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
  using pii = pair<int, int>;
  vector<pii> a(n + 1); int lim = 0;
  for (int i = 1; i <= n; i ++) {
    auto &[l, r] = a[i];
    cin >> l >> r;
    lim = max({lim, l, r});
  }

  // 三分就是每次挑两个端点进行分析
  // 如果要求最大的, 就每次舍弃更小的那一侧
  // 求最小就舍弃另外一侧
  // 原因不是点数不够, 而是问题本身变难了。单峰函数优美的地方在于: 
  // 函数只有一个"折返点", 所以你只需要判断当前处于折返点的左侧还是右侧 —— 两个点的相对大小就够了。
  auto f = [&](int x) -> int {
    int res = 0;
    for (int i = 1; i <= n; i ++) {
      auto [l, r] = a[i];
      if (l <= x and x <= r)
        continue;
      res += min(abs(l - x) * abs(l - x), abs(r - x) * abs(r - x));
    }

    return res;
  };

  int l = 0, r = lim, ans = l;
  while (l <= r) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    if (f(m1) > f(m2)) {
      l = m1 + 1, ans = m2;
    } else {
      r = m2 - 1, ans = m1;
    }
  }

  cout << f(ans) << "\n";
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}