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
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  sort(vec.begin() + 1, vec.end(), greater<int>()); 

  vector<set<int>> st(n + 1);
  auto temp = vec;
  do {
    st[1].insert(temp[1]);
    if (temp[1] & 1) temp[1] ++;
    else temp[1] >>= 1;
  } while (temp[1] > 1);

  for (int i = 2; i <= n; i ++) {
    do {
      if (st[i - 1].count(temp[i])) {
        st[i].insert(temp[i]);
      }
      if (temp[i] & 1) temp[i] ++;
      else temp[i] >>= 1;
    } while (temp[i] > 1);
  }

  // for (int i = 1; i <= n; i ++) {
  //   for (const auto &res : st[i]) {
  //     cout << res << " ";
  //   }
  //   cout << "\n";
  // }

  int res = *max_element(st[n].begin(), st[n].end()),
      ans1 = INT_MAX;
  st[n].insert(1);
  for (const auto &res : st[n]) {  
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
      int temp = vec[i];
      while (temp != res) {
        ans ++;
        if (temp & 1) temp ++;
        else temp >>= 1;
      }
    }
    ans1 = min(ans1, ans);
  }
  // cout << "res: " << res << "\n";
  cout << ans1 << "\n";
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
