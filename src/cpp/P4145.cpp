// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct Infor {
  int sum = 0;
  int mx = 0;
};

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  vector<Infor> seg(n << 2 | 1);
  auto apply = [&](int p, int l, int r, int v) -> void {
    seg[p].sum = (r - l + 1) * v;
    seg[p].mx = v;
  };

  auto pull = [&](int p) -> void {
    seg[p].sum = seg[p << 1].sum + seg[p << 1 | 1].sum;
    seg[p].mx = max(seg[p << 1].mx, seg[p << 1 | 1].mx);
  };

  auto build = [&](auto&& sef, int p, int l, int r) -> void {
    if (l == r) {
      apply(p, l, r, vec[l]);
    } else {
      int m = (l + r) / 2;
      sef(sef, p << 1, l, m);
      sef(sef, p << 1 | 1, m + 1, r);
      pull(p);
    }
  };

  auto set = [&](auto&& sef, int p, int l, int r, int L, int R) -> void {
    if (seg[p].mx == 1) return;
    if (l == r) {
      apply(p, l, r, sqrt(seg[p].sum));
    } else {
      int m = (l + r) / 2, res = 0;
      if (L <= m) sef(sef, p << 1, l, m, L, R);
      if (m < R) sef(sef, p << 1 | 1, m + 1, r, L, R);
      pull(p);
    }
  };

  auto ask = [&](auto&& sef, int p, int l, int r, int L, int R) -> int {
    if (L <= l and r <= R) {
      return seg[p].sum;
    } else {
      int m = (l + r) / 2, res = 0;
      if (L <= m) res += sef(sef, p << 1, l, m, L, R);
      if (m < R) res += sef(sef, p << 1 | 1, m + 1, r, L, R);
      return res;
    }
  };

  build(build, 1, 1, n);
  // cout << ask(ask, 1, 1, n, 1, n) << "\n";
  int m; cin >> m;
  for (int i = 1; i <= m; i ++) {
    int op, l, r;
    cin >> op >> l >> r;
    if (l > r) swap(l, r);
    if (op == 0) {
      set(set, 1, 1, n, l, r);
    }

    if (op == 1) {
      cout << ask(ask, 1, 1, n, l, r) << "\n";
    }
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // int N = 1e12;
  // int cnt = 0;
  // while (N != 1 and ++ cnt) N = sqrt(N);
  // cout << "cnt: " << cnt << "\n";

  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}