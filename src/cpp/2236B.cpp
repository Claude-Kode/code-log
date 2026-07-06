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
  string s; cin >> s;
  s = " " + s;
  vector<int> cnt1(k), cnt2(k);
  for (int i = 1; i <= n; i ++) {
    cnt1[i % k] ++;
    cnt2[i % k] += (s[i] == '1');
  }

  for (int i = 0; i < k; i ++) {
    if (cnt1[i] < 2 and cnt2[i]) {
      cout << "NO" << "\n";
      return; 
    }

    if (cnt2[i] & 1) {
      cout << "NO" << "\n";
      return;
    }
  }

  cout << "YES" << "\n";
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