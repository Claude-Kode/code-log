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
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1);
  map<int, int> mp;
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i ++) {
    cin >> b[i];
    mp[b[i]] ++;
  }

  auto v = a;
  sort(v.begin() + 1, v.end());
  for (int i = 1; i <= n; i ++) {
    if (v[i] > b[i]) {
      cout << -1 << "\n";
      return;  
    }
  }

  for (int i = 1; i <= n; i ++) {
    auto it = mp.lower_bound(a[i]);
    a[i] = it -> first;
    if (--it->second == 0) {
      mp.erase(it);
    } 
  }

  int ans = 0;
  for( int i = 1; i < n; i ++) {
    for (int j = i + 1; j <= n; j ++) {
      ans += a[j] < a[i];
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
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
} 