// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  string t = "SCNUCPC";
  int cnt = 0;
  for(int i = 0; i < n - 6; i ++) {
    if (cnt == k) break;
    if (s[i] == '?' || s[i] == t[0]) {
      // cout << i << '\n';
      bool f = true;
      for(int j = i; j <= i + 6; j ++) {
        if (s[j] == '?') continue;
        if (s[j] != t[j - i]) f = false;
      }
      if (!f) continue;
      for(int j = i; j <= i + 6; j ++) {
        s[j] = t[j - i];
      } 
      cnt ++;
    }
  }

  if (cnt == k) {
    for(auto &c : s) if (c == '?') c = 'A';
    cout << "Yes" << "\n" << s << '\n';
  } else {cout << "No" << "\n";}
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