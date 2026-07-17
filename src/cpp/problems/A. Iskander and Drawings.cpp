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
  string s; cin >> s;
  // cout << s << "\n";
  int ans = 0;
  for (int i = 1; i <= n; i ++) {
    string temp = "";
    for (int j = 1; j <= i; j ++) {
      temp += '#';
    }
    if (s.find(temp) != string::npos) {
      ans = (i + 1) / 2;
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
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}