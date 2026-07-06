// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> vec(n + 1);
  int ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> vec[i];
    sum += vec[i];
    if (sum > m)
      ans += m, sum -= m;
    else
      ans += sum, sum = 0;
  }

  std::cout << sum << "\n";
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