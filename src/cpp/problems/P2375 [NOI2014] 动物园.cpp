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

int mod = 1e9 + 7;

vector<int> border(const string& p) {
  int m = p.size();
  vector<int> nxt(m, 0);
  for (int i = 1, j = 0; i < m; i++) {
    while (j and p[i] != p[j]) {
      j = nxt[j - 1];
    }
    if (p[i] == p[j]) {
      j++;
    }
    nxt[i] = j;
  }
  return nxt;
}

void solve() {
  string s;
  cin >> s;
  auto nxt = border(s);
  // dbug(nxt);
  nxt.insert(nxt.begin(), 0LL);
  // dbug(nxt);

  int n = (int)s.size(), lg = __lg(n);
  vector<vector<int>> jump(lg + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    jump[0][i] = nxt[i];
  }

  for (int e = 1; e <= lg; e++) {
    for (int i = 1; i <= n; i++) {
      jump[e][i] = jump[e - 1][jump[e - 1][i]];
    }
  }

  auto cal = [&](int x, int i) -> int {
    // 跳到 > x 的最小值的步数
    int p = i, cnt = 0;
    for (int e = lg; e >= 0; e--) {
      if (jump[e][p] > x) {
        p = jump[e][p];
        cnt += (1 << e);
      }
    }
    return cnt;
  };

  // dbug(nxt);
  // dbug(jump);

  /*
    nxt = [0, 1, 2, 3, 4]

    jump = [
    [0, 1, 2, 3, 4, 0], 
    [0, 1, 2, 3, 4, 0], 
    [0, 1, 2, 3, 4, 0]]
  */

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans * (cal(0LL, i) - cal(i / 2, i) + 1) % mod;
  }

  cout << ans << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}