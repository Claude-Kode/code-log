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

using arr = array<int, 26>;

void solve() {
  string s; cin >> s;
  int n = s.size();
  string odd = "", even = "";
  s  = " " + s;
  for (int i = 1; i <= n; i ++) {
    if (i & 1) odd += s[i];
    else even += s[i];
  }

  // dbug(odd, even);

  if (n & 1) {
    int o = (n + 1) / 2, e = n - o;
    {
      arr temp = {};
      for (const auto & c : even) {
        temp[c - 'a'] ++;
      }
      int cnt = 0;
      for (const auto &a : temp) {
        cnt += (a & 1);
      }
      if (cnt != (e & 1)) {
        cout << "NO" << "\n";
        return;
      }
    }

    {
      int cnt = 0;
      arr temp = {};
      for (const auto & c : odd) {
        temp[c - 'a'] ++;
      }

      for (const auto &a : temp) {
        cnt += (a & 1);
      }

      if (cnt != (o & 1)) {
        cout << "NO" << "\n";
        return;
      }
    }
  } else {
    // 每个奇数位置都和偶数位置对应啊
    arr temp1 = {}, temp2 = {};
    for (const auto &c : odd) temp1[c - 'a'] ++;
    for (const auto &c : even) temp2[c - 'a'] ++;
    bool f = false;
    for (const auto &a : temp1) {
      f |= (a & 1);
    }
    for (const auto &a : temp2) {
      f |= (a & 1);
    }
    if (temp1 != temp2 and f) {
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