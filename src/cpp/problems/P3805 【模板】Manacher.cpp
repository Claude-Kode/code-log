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

vector<int> manacher(const string& s) {
  int n = s.size();
  // 预处理
  string t = "#";
  for (char c : s) {
    t += c;
    t += '#';
  }

  int m = t.size();
  vector<int> d(m);
  for (int i = 0, c = 0, r = 0; i < m; i++) {
    // 对称过来的初值
    if (i <= r) d[i] = min(d[2 * c - i], r - i);
    // 尝试向外扩展
    while (i - d[i] - 1 >= 0 and i + d[i] + 1 < m and
           t[i - d[i] - 1] == t[i + d[i] + 1])
      d[i]++;
    // 更新最右回文
    if (i + d[i] > r) {
      r = i + d[i];
      c = i;
    }
  }
  return d;
}

void solve() {
  string s;
  cin >> s;
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