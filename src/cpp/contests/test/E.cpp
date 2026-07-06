// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define popcnt __builtin_popcountll

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#else
#define dbug(...)
#endif

// REGISTER_REFLECT()

const int N = (1 << 18) - 1;

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
    vec[i]--;
  }

  vector<int> min_r(N + 1, n + 1), max_l(N + 1, 0);
  for (int l = 1; l <= n; l++) {
    int msk = 1 << vec[l];
    int r = l;
    min_r[msk] = min(min_r[msk], r);
    max_l[msk] = max(max_l[msk], l);
    while (r + 1 <= n and !(msk >> vec[r + 1] & 1)) {
      r++;
      msk |= (1 << vec[r]);
      min_r[msk] = min(min_r[msk], r);
      max_l[msk] = max(max_l[msk], l);
    }
  }

  // 数组大小没有开够
  vector<vector<int>> dp(N + 1, vector<int>(19, 0));
  for (int msk = 1; msk <= N; msk++) {
    if (!max_l[msk]) continue;
    dp[msk][popcnt(msk)] = max_l[msk];
  }

  for (int i = 0; i < 18; i++) {
    for (int msk = 1; msk <= N; msk++) {
      // 这里我们只关心他是不是子集, 所以不用判断他所代表的子串是否存在
      if (msk >> i & 1) continue;
      int sup = msk | (1 << i);
      int cnt = popcnt(sup);
      // 这里错了
      for (int c = 0; c <= 18; c ++) {
        dp[sup][c] = max(dp[sup][c], dp[msk][c]);
      }
    }
  }

  int ans = 1;
  for (int msk = 1; msk <= N; msk++) {
    int comp = msk ^ N;
    for (int c = 17; c >= 0; c--) {
      if (dp[comp][c] <= min_r[msk]) continue;
      ans = max(ans, popcnt(msk) + c);
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