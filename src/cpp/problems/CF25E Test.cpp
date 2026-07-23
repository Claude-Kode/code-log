// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define sz(x) (int)(x.size())

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#else
#define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {
  string a, b, c;
  cin >> a >> b >> c;
  vector<string> S = {a, b, c};

  auto border = [&](string& p) -> vector<int> {
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
  };

  auto kmp = [&](string& s, string& p) -> int {
    auto nxt = border(p);
    int j = 0, n = (int)s.size(), m = (int)p.size();
    auto res = vector<int>(n);
    for (int i = 0; i < n; i++) {
      while (j and s[i] != p[j]) {
        j = nxt[j - 1];
      }
      j += (s[i] == p[j]);
      if (j == m) return -1;
    }

    return j;
  };

  auto merge_str = [&](string& a, string& b) -> string {
    int ov = kmp(a, b);
    if (ov == -1) return a;
    return a + b.substr(ov);
  };

  auto cal = [&]() {
    string x = S[0], y = S[1], z = S[2];
    int res = INT_MAX;
    // int xy = kmp(x, y);
    // int yz = kmp(y, z);
    // int xz = kmp(x, z);

    string xy = merge_str(x, y);
    string xyz = merge_str(xy, z);

    return sz(xyz);
  };

  int ans = INT_MAX;
  ranges::sort(S);
  int t = 0;
  do {
    // cout << "t: " << ++t << "\n";
    int res = cal();
    // dbug(res);
    ans = min(res, ans);
  } while (next_permutation(S.begin(), S.end()));

  cout << ans << "\n";
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
