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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> pre1(n + 1), pre2(n + 1);
  for (int i = 0; i < n; i++) {
    pre1[i + 1] = pre1[i] + (a[i] == 1 ? 1 : -1);
    pre2[i + 1] = pre2[i] + (a[i] == 3 ? -1 : 1);
  }

  int mn = INT_MAX;
  for (int i = 1; i < n; i++) {
    if (pre2[i] - mn >= 0) {
      cout << "YES" << "\n";
      return;
    }
    if (pre1[i] >= 0) {
      mn = min(mn, pre2[i]);
    }
  }

  cout << "NO" << "\n"  ;
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
