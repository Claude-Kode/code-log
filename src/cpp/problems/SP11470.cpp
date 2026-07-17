// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct Infor {
  int ls, rs;
  int sum = 0;
  int tag = 0;
};

int cnt = 0;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  vector<Infor> seg(n * 70 + 1);

  auto clone = [&](int pre) -> int {
    int p = ++cnt;
    seg[p] = seg[pre];
    return p;
  };

  auto apply = [&](int p, int l, int r, int v) -> void {
    seg[p].sum += (r - l + 1) * v;
    seg[p].tag += v;
  };

  auto push = [&](int p, int l, int r) -> void {
    if (seg[p].tag == 0) return;
    int m = (l + r) / 2;
    seg[p].ls = clone(seg[p].ls);
    seg[p].rs = clone(seg[p].rs);
    apply(seg[p].ls, l, m, seg[p].tag);
    apply(seg[p].rs, m + 1, r, seg[p].tag);
    seg[p].tag = 0;
  };

  auto pull = [&](int p) -> void {
    seg[p].sum = seg[seg[p].ls].sum + seg[seg[p].rs].sum;
  };

  auto build = [&](auto&& sef, int l, int r) -> int {
    int p = ++cnt;
    if (l == r) {
      seg[p].sum = vec[l];
    } else {
      int m = (l + r) / 2;
      seg[p].ls = sef(sef, l, m);
      seg[p].rs = sef(sef, m + 1, r);
      pull(p);
    }
    return p;
  };

  auto add = [&](auto&& sef, int pre, int l, int r, int L, int R,
                 int v) -> int {
    int p = clone(pre);
    if (L <= l && r <= R) {
      apply(p, l, r, v);
    } else {
      // 注意这里的 push 有可能会改变 seg[p] 的孩子哦
      // 所以下面传递参数用的是 seg[p].ls 而不是seg[pre].ls
      push(p, l, r);
      int m = (l + r) / 2;
      if (L <= m) seg[p].ls = sef(sef, seg[p].ls, l, m, L, R, v);
      if (m < R) seg[p].rs = sef(sef, seg[p].rs, m + 1, r, L, R, v);
      pull(p);
    }
    return p;
  };

  auto sum = [&](auto&& sef, int p, int l, int r, int L, int R) -> int {
    if (L <= l && r <= R) {
      return seg[p].sum;
    } else {
      push(p, l, r);
      int m = (l + r) / 2, res = 0;
      if (L <= m) res += sef(sef, seg[p].ls, l, m, L, R);
      if (m < R) res += sef(sef, seg[p].rs, m + 1, r, L, R);
      return res;
    }
  };

  vector<int> root(1);
  root[0] = build(build, 1, n);

  for (int i = 1; i <= m; i++) {
    char op;
    cin >> op;
    if (op == 'C') {
      int l, r, x;
      cin >> l >> r >> x;
      root.push_back(add(add, root.back(), 1, n, l, r, x));
    }

    if (op == 'Q') {
      int l, r;
      cin >> l >> r;
      cout << sum(sum, root.back(), 1, n, l, r) << "\n";
    }

    if (op == 'H') {
      int l, r, t;
      cin >> l >> r >> t;
      cout << sum(sum, root[t], 1, n, l, r) << "\n";
    }

    if (op == 'B') {
      int t;
      cin >> t;
      root.push_back(t);
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
