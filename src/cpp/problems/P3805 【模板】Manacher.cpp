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

vector<int> manacher(string& s) {
  string t = "#";
  for (char& ch : s) {
    t += ch;
    t += '#'; 
  }

  int n = t.size();
  vector<int> d(n);
  int r = 0, c = 0;
  for (int i = 0; i < n; i++) {
    d[i] = (i < r) ? min(d[2 * c - i], r - i) : 1LL;
    while (i - d[i] >= 0 and i + d[i] < n and t[i - d[i]] == t[i + d[i]]) 
      d[i] ++;
    if (i + d[i] > r) {
      c = i, r = i + d[i];
    } 
  }

  return d;
}

void solve() {
  string s;
  cin >> s;
  cout << ranges::max(manacher(s)) - 1 << "\n";
  // 0-based 偶数索引位置为'#'
  // 填充之后 长度 len 会 
  // len => len * 2 + 1

  
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

