// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  std::string s; 
  std::cin >> s;
  int n = s.size(); s = " " + s;
  int cnt_r = 0, cnt_b = 0, ans = 0;
  // std::vector<std::array<int, 2>> infor;
  for (int i = 1; i <= n; i ++) {
    if (s[i] == 'R') {
      if (cnt_b > 0) cnt_b --, cnt_r ++;
      else cnt_r ++;
    } else if (s[i] == 'B') {
      if (cnt_r > 0) cnt_r --, cnt_b ++;
      else cnt_b ++;
    } else {
      // infor.push_back({cnt_b, cnt_r});
      // swap(cnt_b, cnt_r);
      cnt_b = 0, cnt_r = 0;
    }

    ans = std::max(ans, cnt_b + cnt_r);
  }

  std::cout << ans << "\n";
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