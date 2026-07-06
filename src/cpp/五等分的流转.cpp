// @Author : Gorau
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#else
#define dbug(...)
#endif

// REGISTER_REFLECT()

using arr = array<int, 5>;

arr operator+(const auto &a, const auto &b) {
  arr res;
  for (int i = 0; i < 5; i ++) {
    res[i] = a[i] + b[i];
  }
  return res;
}

arr& operator+=(arr& a, const auto &b) {
  for (int i = 0; i < 5; i ++) {
    a[i] += b[i];
  }
  return a;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  vector<arr> seg(n << 2 | 1, {0, 0, 0, 0, 0});
  vector<int> tag(n << 2 | 1, 0);

  auto apply = [&](int p, int plus) -> void {
    arr res;
    for (int i = 0; i < 5; i ++) {
      res[(i + plus) % 5] = seg[p][i];
    }
    seg[p] = res;
    tag[p] += plus;
  };

  auto pull = [&](int p) -> void {
    seg[p] = seg[p << 1] + seg[p << 1 | 1];
  };

  auto push = [&](int p) -> void {
    apply(p << 1, tag[p]);
    apply(p << 1 | 1, tag[p]);
    tag[p] = 0;
  };

  auto build = [&](auto&& sef, int p, int l, int r) -> void {
    if (l == r) {
      seg[p][vec[l]] ++;
    } else {
      int m = (l + r) / 2;
      sef(sef, p << 1, l, m);
      sef(sef, p << 1 | 1, m + 1, r);
      pull(p);
    }
  };  

  auto mod = [&](auto && sef, int p, int l, int r, int L, int R) -> void {
    if (L <= l and r <= R) {
      apply(p, 1);
    } else {
      push(p);
      int m = (l + r) / 2;
      if (L <= m) sef(sef, p << 1, l, m, L, R);
      if (m < R)  sef(sef, p << 1 | 1, m + 1, r, L, R);
      pull(p);
    }
  }; 

  auto ask = [&](auto && sef, int p, int l, int r, int L, int R) -> arr {
    if (L <= l and r <= R) {
      return seg[p];
    } else {
      push(p);
      int m = (l + r) / 2;
      arr res = {};
      if (L <= m) res += sef(sef, p << 1, l, m, L, R);
      if (m < R)  res += sef(sef, p << 1 | 1, m + 1, r, L, R);
      return res;
    }
  };

  build(build, 1, 1, n);

  for (int i = 1; i <= q; i ++) {
    int p, l, r;
    cin >> p >> l >> r;
    if (p == 1) {
      mod(mod, 1, 1, n, l, r);
    } else {
      auto res = ask(ask, 1, 1, n, l, r);
      for (int i = 0; i < 5; i ++) {
        cout << res[i] << " \n"[i == 4];
      }
    } 
  }

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