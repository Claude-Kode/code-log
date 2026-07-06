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
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> buc(1000, 0);
  int ans = 4;
  buc[a] ++, buc[b] ++, buc[c] ++;
  ans = min(ans, ans - max({buc[a], buc[b], buc[c]}));
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