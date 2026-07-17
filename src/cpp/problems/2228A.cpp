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
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
    if (vec[i] == 0) cnt0 ++;
    if (vec[i] == 1) cnt1 ++;
    if (vec[i] == 2) cnt2 ++;
  }

  int mn = min(cnt1, cnt2);
  int ans = cnt0 + mn;
  if (cnt1 > mn) {
    ans += (cnt1 - mn) / 3;
  } else {
    ans += (cnt2 - mn) * 2 / 6;
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