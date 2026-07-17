// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> vec(n + 1, 0); 
  std::vector<int> seg(n << 2 | 1, -1);
  std::vector<int> val(n << 2 | 1, -1);
  std::vector<int> mul(n << 2 | 1, 0);  

  static auto ls = [&](int i) { return i << 1; };
  static auto rs = [&](int i) { return i << 1 | 1; };

  auto apply = [&](int p, int V, int M) -> void {
    if (V != -1) {
      seg[p] = V;
      val[p] = V;
      mul[p] = 0;
    }

    if (M != 0) {
      M = std::min(M, 63LL);
      seg[p] >>= M;
      if (val[p] != -1) {
        val[p] >>= M;
        mul[p] = 0;
      } else {
        mul[p] += M;
      mul[p] = std::min(mul[p], 63LL);
      }
    }
  };

  auto push = [&](int p) -> void {
    apply(ls(p), val[p], mul[p]);
    apply(rs(p), val[p], mul[p]);
    val[p] = -1, mul[p] = 0;
  };

  auto pull = [&](int p) -> void {
    if (seg[ls(p)] != -1 && seg[rs(p)] != -1 && seg[ls(p)] == seg[rs(p)]) {
      seg[p] = seg[ls(p)];
    } else {
      seg[p] = -1;
    }
  };

  auto build = [&](auto&& self, int p, int l, int r) -> void {
    if (l >= r) {
      seg[p] = vec[l];
      return;
    }
    int m = (l + r) / 2;
    self(self, ls(p), l, m);
    self(self, rs(p), m + 1, r);
    pull(p);
  };

  auto assign = [&](auto&& self, int p, int l, int r, int ql, int qr, int v) -> void {
    if (ql <= l && r <= qr) {
      seg[p] = v;
      val[p] = v;
      mul[p] = 0;
      return;
    }
    push(p);
    int m = (l + r) / 2;
    if (ql <= m) self(self, ls(p), l, m, ql, qr, v);
    if (m < qr) self(self, rs(p), m + 1, r, ql, qr, v);
    pull(p);
  };

  auto div = [&](auto&& self, int p, int l, int r, int ql, int qr) -> void {
    if (ql <= l && r <= qr && seg[p] != -1) {
      seg[p] >>= 1;
      if (val[p] != -1)
        val[p] >>= 1;
      else
        mul[p] ++;
      mul[p] = std::min(mul[p], 63LL);
      return;
    }
    push(p);
    int m = (l + r) / 2;
    if (ql <= m) self(self, ls(p), l, m, ql, qr);
    if (m < qr) self(self, rs(p), m + 1, r, ql, qr);
    pull(p);
  };

  auto ask = [&](auto&& self, int p, int l, int r, int pos) -> int {
    if (l <= pos && pos <= r && seg[p] != -1) {
      return seg[p];
    }
    push(p);
    int m = (l + r) / 2;
    if (pos <= m)
      return self(self, ls(p), l, m, pos);
    else 
      return self(self, rs(p), m + 1, r, pos);
  };

  for (int i = 1; i <= n; i++) {
    std::cin >> vec[i];
  }

  build(build, 1, 1, n);

  while (q --) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int l, r;
      std::cin >> l >> r;
      div(div, 1, 1, n, l, r);
    }

    if (op == 2) {
      int l, r, x;
      std::cin >> l >> r >> x;
      assign(assign, 1, 1, n, l, r, x);
    }

    if (op == 3) {
      int p;
      std::cin >> p;
      std::cout << ask(ask, 1, 1, n, p) << "\n";
    }
  }
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