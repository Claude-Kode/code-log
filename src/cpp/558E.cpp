// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

using arr = array<int, 26>;

arr operator+(const arr& a, const arr& b) {
  arr res = {};
  for (int i = 0; i < 26; i ++) res[i] = a[i] + b[i];
  return res;
}

arr operator-(const arr& a, const arr& b) {
  arr res = {};
  for (int i = 0; i < 26; i ++) res[i] = a[i] - b[i];
  return res;
}

void solve() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  s = " " + s;

  vector<int> tagged(n << 2 | 1, 0),
              tag(n << 2 | 1, -1);
  vector<arr> seg(n << 2 | 1, arr{});

  auto pull = [&](int p) -> void { 
    seg[p] = seg[p * 2] + seg[p * 2 + 1]; 
  };

  auto apply = [&](int p, int c, int len) -> void {
    seg[p] = arr{};
    seg[p][c] = len;
    tag[p] = c;
    tagged[p] = 1;
  };

  auto push = [&](int p, int l, int r) -> void {
    if (!tagged[p]) return;
    int mid = (l + r) >> 1;
    apply(p * 2, tag[p], mid - l + 1);
    apply(p * 2 + 1, tag[p], r - mid);
    tag[p] = -1;
    tagged[p] = 0;
  };

  auto build = [&](auto&& sef, int p, int l, int r) -> void {
    if (l == r) {
      seg[p][s[l] - 'a'] ++;
    } else {
      int m = (l + r) / 2;
      sef(sef, p * 2, l, m);
      sef(sef, p * 2 + 1, m + 1, r);
      pull(p);
    }
  };

  auto set = [&](auto && sef, int p, int l, int r, int L, int R, int c) -> void {
    if (L <= l && r <= R ) {
      apply(p, c, r - l + 1);
    } else {
      push(p, l, r);
      int m = (l + r) / 2;
      if (L <= m) sef(sef, p * 2, l, m, L, R, c);
      if (R > m)  sef(sef, p * 2 + 1, m + 1, r, L, R, c);
      pull(p);
    }
  };

  auto ask = [&](auto&& sef, int p, int l, int r, int L, int R) -> arr {
    if (L <= l && r <= R) {
      return seg[p];
    } else {
      push(p, l, r);
      int m = (l + r) / 2; arr res = {};
      if (L <= m) res = res + sef(sef, p * 2, l, m, L, R);
      if (m < R)  res = res + sef(sef, p * 2 + 1, m + 1, r, L, R);
      return res;
    }
  };

  auto work = [&](int L, int R, int f) -> void {
    auto a = ask(ask, 1, 1, n, L, R);
    int l = L, r = L;
    // cerr << "infor: " << L << ' ' << R << "\n";
    if (f) {
      for (int i = 0; i < 26; i ++) {
        if (a[i]) {
          r = l + a[i] - 1;
          set(set, 1, 1, n, l, r, i);
          l = r + 1;
        }
      }
    } else {
      for (int i = 25; i >= 0; i --) {
        if (a[i]) {
          r = l + a[i] - 1;
          set(set, 1, 1, n, l, r, i);
          l = r + 1;
        }
      }
    }
  };

  build(build, 1, 1, n);
  for (int i = 1; i <= m; i ++) {
    int l, r, f;
    cin >> l >> r >> f;
    work(l, r, f);
  }

  string ans = "";
  for (int i = 1; i <= n; i ++) {
    auto buc = ask(ask, 1, 1, n, i, i);
    for (int j = 0; j < 26; j ++) {
      if (buc[j]) {
        ans += (j + 'a');
      }
    }
  }

  cout << ans << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}