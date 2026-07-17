// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s; s = " " + s;
  vector<int> ans(n + 2, 0);
  for(int i = 1; i <= n; i ++) if (s[i] == '1') ans[i + 1] = 1;

  vector<int> num;
  for(int i = 2; i <= 100; i ++) if (__gcd(i, k) == 1) num.push_back(i);

  int m = num.size(), a = 0, b = 0;
  for(int i = 0; i < m - 1; i ++) {
    for(int j = i + 1; j < m; j ++) {
      if (__gcd(num[i], num[j]) == 1) {
        a = num[i], b = num[j]; break;
      }
    }
  }
  
  int p = 0, cnt = 0; assert(a && b);
  for(int i = 1; i <= n + 1; i ++) {
    if (ans[i]) continue;
    ans[i] = (cnt++ & 1 ? a : b);
  }

  for(int i = 1; i <= n + 1; i ++) {
    cout << ans[i] << " \n"[i == n + 1];
  }  
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