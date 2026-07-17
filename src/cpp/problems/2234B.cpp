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
  string s = to_string(n);
  string ss = s;
  reverse(s.begin(), s.end());
  if (ss == s) {
    cout << n << ' ' << 0 << "\n";
    return;
  }

  {
    int res = n % 12;
    // dbug(res);
    string s = to_string(res);
    string ss = s;
    reverse(s.begin(), s.end());
    if (ss == s) {
      cout << res << ' ' << n - res << "\n";
      return;
    } else if (n >= 22) {
      cout << 22 << ' ' << n - 22 << "\n";
      return;
    }
  }

  cout << -1 << "\n";
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