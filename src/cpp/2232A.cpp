// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

// REGISTER_REFLECT()

void solve() {
  int n; cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  sort(vec.begin() + 1, vec.end());
  int ans = 1000;

  unordered_map<int, int> fir, lst;
  for (int i = 1; i <= n; i ++) {
    lst[vec[i]] = i;
  }

  for (int i = n; i > 0; i --) {
    fir[vec[i]] = i;
  }

  for (auto & [k, v] : fir) {
    ans = min(ans, max(fir[k] - 1, n - lst[k]));
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
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}