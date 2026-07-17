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
  int n, k;
  cin >> n >> k;

  vector<int> vec(n + 2, 0);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<int> lens;
  {
    int cur = 1;
    for (int i = 1; i <= n; i ++) {
      if (vec[i] != vec[i + 1]) {
        lens.push_back(cur);
        cur = 1;
      } else {
        cur ++;
      }
    }
  }

  sort(lens.begin(), lens.end());
  
  int m = (int)lens.size(),
      d = 0, 
      ans = 0, 
      i = 0;

  while (i < m) {
    int len = n - d - (lens[i] - 1) * (m - i);
    if (len <= k and (k - len) % (m - i) == 0)
      ans ++;
 
    int j = i;
    while (j < m and lens[j + 1] == lens[i])
      j ++;
    d += (j - i) * lens[i];
    i = j;
  }
 
  cout << ans << "\n";
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