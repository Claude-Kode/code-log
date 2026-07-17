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

using arr = array<int, 32>;

int lowbit(int i) {
  return i & -i;
} 

void solve() {
  int n; cin >> n;
  vector<int> vec(n + 1);
  map<int, int> mp;
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
    vec[i] = vec[i] & -vec[i];
    mp[vec[i]] ++;
  }

  dbug(vec);

  int ans = 0, small = mp.begin() -> first;
  dbug(small);
  for (const auto& [k, v] : mp) {
    ans += k * (v - 1);
    if (k == small) continue;
    ans += (k | small); 
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