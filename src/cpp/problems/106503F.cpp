// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n + 1), b(m + 1);
  unordered_map<int, int> ump1, ump2;
  for(int i = 1; i <= n; i ++) {
    cin >> a[i];
    ump1[a[i]] = 1;
  }
  for(int i = 1; i <= m; i ++) {
    cin >> b[i];
    ump2[b[i]] = 1;
  }

  // for(const auto &[k, v] : ump1) {
  //   if (ump2.count(k)) continue;
  //   else cout << "No" << "\n";
  //   return;
  // }

  // cout << "Yes" << "\n";  

  cout << (ranges::max(a) == ranges::max(b) ? "Yes" : "No") << "\n";

  // 列出现的元素行都要满足
  // 第二, 最大值不能不一样
  
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, C = 0; 
  cin >> tt;
  while (tt-- && ++C)
    // cout << "TEST CASE : " << C << endl,
    solve();

  return 0;
}