// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

#define chmax(a, b) ((a) < (b) && ((a) = (b), true))
#define chmin(a, b) ((a) > (b) && ((a) = (b), true))

constexpr int64_t pow10[20] = {
  1LL,                   // 10^0
  10LL,                  // 10^1
  100LL,                 // 10^2
  1000LL,                // 10^3
  10000LL,               // 10^4
  100000LL,              // 10^5
  1000000LL,             // 10^6
  10000000LL,            // 10^7
  100000000LL,           // 10^8
  1000000000LL,          // 10^9
  10000000000LL,         // 10^10
  100000000000LL,        // 10^11
  1000000000000LL,       // 10^12
  10000000000000LL,      // 10^13
  100000000000000LL,     // 10^14
  1000000000000000LL,    // 10^15
  10000000000000000LL,   // 10^16
  100000000000000000LL,  // 10^17
  1000000000000000000LL, // 10^18
};

const int inf = LLONG_MAX / 10;

void solve() {
  int a, n;
  cin >> a >> n;
  vector<int> nums(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> nums[i];
  }

  if (n == 1 and nums[1] == 0) {
    cout << a << "\n";
    return;
  }

  int ans = LLONG_MAX;
  // >= a, smallest
  {
    map<int, int> mp;
    auto dfs = [&](auto && sef, int x) -> int {
      if (mp.count(x)) return mp[x];
      if (x == 0) return mp[x] = nums[1];
      int res = inf;

      for (int i = 1; i <= n; i ++) {
        if (x <= nums[i]) {
          return mp[x] = nums[i];
        }
      }

      for (int i = 1; i <= n; i ++) {
        int d = nums[i];
        // 这个向上取整保证了, 如果当前的 d 小于 x 的末尾 r, 
        // 就会让 x 去掉末尾后再加 1, d == r 的时候不会进位
        // 而且关键是 能保证 d == r 的时候满足数值上确实就是最小的
        int num = (x - d + 9) / 10;
        int pre = sef(sef, num);
        if (pre == inf) continue;
        chmin(res, pre * 10 + d);
      }
      return mp[x] = res;
    };
    int res = dfs(dfs, a);
    // debug(res);
    // debug(res - a);
    // debug(abs(res - a));
    chmin(ans, labs(res - a));
    if (res < inf) {
      chmin(ans, abs(res - a));
    }
  }
  // 小于他的数是可以选择前导 0 的
  {
    map<int, int> mp;
    auto dfs = [&](auto && sef, int x) -> int {
      if (mp.count(x)) return mp[x];
      if (x == 0) return nums[1] == 0 ? 0 : -inf;
      int res = -inf;
      for (int i = 1; i <= n; i ++) {
        if (x >= nums[i]) {
          chmax(res, nums[i]);
        }
      }

      for (int i = 1; i <= n; i ++) {
        int d = nums[i];
        if (d > x) continue;
        // 当 d > r 的时候, 向下取整会让前缀的最后一位退位
        // 而 d < r 的时候, 向下取整会让前缀的最后一位保持不变
        // 同样的 也可以保证最小的 10 * pre + v 的最大一定是最优解 
        // 甚至可以在保证 10000 这种情况下退化到正确的 9999开头这样的
        int num = (x - d) / 10;
        int pre = sef(sef, num);
        if (pre == -inf) continue;
        chmax(res, pre * 10 + d);
      }
      return mp[x] = res;
    };
    int res = dfs(dfs, a);
    // debug(res);
    // debug(a - res);
    // debug(abs(res - a));
    if (res > -inf) {
      chmin(ans, a - res);
    }
  }

  cout << ans << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cerr << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

/*
X = 10 * Y + d 和 a = 10 * q + r 比较：
如果 d < r，那么为了 X ≥ a，Y 必须至少是 q + 1（进位）。
如果 d > r，那么为了 X ≤ a，Y 必须至多是 q - 1（退位）。
*/
