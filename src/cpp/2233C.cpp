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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = ' ' + s;

  int rem = n - k;
  vector<int> pre(n + 2), suf(n + 2);
  for (int i = 1; i <= n; i ++) {
    pre[i] = pre[i - 1] + (s[i] == ')');
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + (s[i] == '(');
  }

  int mx = 0, mxi = 0;
  for (int i = 1; i <= n; i ++) {
    if (pre[i] + suf[i] >= mx) {
      mxi = i;
      mx = max(mx, pre[i] + suf[i]);
    }
  }

  vector<int> ans(n + 1);
  ans[mxi] = 1;
  int cnt = rem - 1;

  if (mx >= rem) {
    for (int i = 1; i <= mxi - 1; i ++) {
      if (cnt and (s[i] == ')')) {
        ans[i] = 1; cnt--;
      }
    }
    for (int i = mxi + 1; i <= n; i ++) {
      if (cnt and (s[i] == '(')) {
        ans[i] = 1; cnt--;
      }
    }
  } else {

    for (int i = 1; i <= mxi - 1; i ++) {
      if (cnt and (s[i] == ')')) {
        ans[i] = 1; cnt--;
      }
    }
    for (int i = mxi + 1; i <= n; i ++) {
      if (cnt and (s[i] == '(')) {
        ans[i] = 1; cnt--;
      }
    }
    for (int i = 1; i <= n; i ++) {
      if (cnt and ans[i] == 0) {
        ans[i] = 1; cnt--;
      }
    }
  }

  for (int i = 1; i <= n; i ++) {
    cout << (ans[i] ^ 1);
    if (i == n) cout << "\n";
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