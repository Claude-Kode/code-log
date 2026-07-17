// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n; cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  int mx = 0;
  for (int i = 1; i < n ; i ++) {
    mx = max(mx, vec[i] - vec[i + 1]);
  }

  for (int i = 1; i <= n; i ++) {
    if (vec[i] < vec[i - 1]) {
      vec[i] += mx;
    }
  }

  cout << (is_sorted(vec.begin(), vec.end()) ? "YES" : "NO") << "\n";
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