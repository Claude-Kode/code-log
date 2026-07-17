// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

const int MAXN = 1000005;
struct Info {
  int ls = -1, rs = -1;
  int val = 0;
  Info() = default;
};

vector<Info> seg(MAXN * 25);

int cnt = 0;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    std::cin >> vec[i];
  }

  auto build = [&](auto &&sef, int l, int r) -> int {
    int p = ++cnt;
    if (l == r) {
      seg[p].val = vec[l];
      return p;
    } else {
      int m = (l + r) >> 1;
      seg[p].ls = sef(sef, l, m);
      seg[p].rs = sef(sef, m + 1, r);
      return p;
    }
  };

  auto modify = [&](auto && sef, int pre, int l, int r, int pos, int v) -> int {
    int p = ++cnt;
    seg[p] = seg[pre];
    if (l == r) {
      seg[p].val = v;
      return p;
    } else {
      int m = (l + r) >> 1;
      if (pos <= m)
        seg[p].ls = sef(sef, seg[pre].ls, l, m, pos, v);
      else
        seg[p].rs = sef(sef, seg[pre].rs, m + 1, r, pos, v);
      return p;
    }
  };

  auto ask = [&](auto && sef, int p, int l, int r, int pos) -> int {
    if (l == r) {
      return seg[p].val;
    } else {
      int m = (l + r) >> 1;
      if (pos <= m)
        return sef(sef, seg[p].ls, l, m, pos);
      else
        return sef(sef, seg[p].rs, m + 1, r, pos);
    }
  };

  std::vector<int> root(m + 1);
  root[0] = build(build, 1, n);
  for (int i = 1 ; i <= m; i ++) {
    int v, op;
    std::cin >> v >> op;
    if (op == 1) {
      int p, c;
      std::cin >> p >> c;
      root[i] = modify(modify, root[v], 1, n, p, c);
    }

    if (op == 2) {
      int p;
      std::cin >> p;
      root[i] = root[v];
      std::cout << ask(ask, root[v], 1, n, p) << "\n";
    }
  }
}

/*树是二维结构  主席树相当于三维, 新加的一维相当于是时间维度*/

int32_t main() {
  std::vector<int> v;
  cout << v.max_size() << "\n";

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

// @Author : GoryK 
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct Infor {
  int sum = 0;
  int tag = 0;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  vector<Infor> seg(n << 2 | 1);  

  auto apply = [&](int p, int l, int r, int v) -> void {
    seg[p].sum += v;
    seg[p].tag += v;
  };

  auto push = [&](int p, int l, int r) -> void {
    int m = (l + r) / 2;
    apply(p << 1, l, m, seg[p].tag);
    apply(p << 1 | 1, m + 1, r, seg[p].tag);
    seg[p].tag = 0;
  };

  auto pull = [&](int p) -> void {
    seg[p].sum = seg[p << 1].sum + seg[p << 1 | 1].sum;
  };

  auto build = [&](auto && sef, int p, int l, int r) -> void {
    if (l == r) {
      seg[p].sum = vec[l];
    } else {
      int m = (l + r) / 2;
      sef(sef, p << 1, l, m);
      sef(sef, p << 1 | 1, m + 1, r);
      pull(p);
    }
  };

  auto set = [&](auto && sef, int p, int l, int r, int L, int R, int v) -> void {
    if (L <= l && r <= R) {
      apply(p, l, r, v);
    } else {
      push(p, l, r);
      int m = (l + r) / 2;
      if (L <= m) 
        sef(sef, p << 1, l, m, L, R, v);
      else if (m <= R) 
        sef(sef, p << 1 | 1, m + 1, r, L, R, v);
      pull(p);
    }

  };

  auto ask = [&](auto && sef, int p, int l, int r, int L, int R) -> int {
    if (L <= l && r <= R) {
      return seg[p].sum;
    } else {
      push(p, l, r);
      int m = (l + r) / 2, res = 0;
      if (L <= m) 
        res += sef(sef, p << 1, l, m, L, R);
      else if (m <= R) 
        res += sef(sef, p << 1 | 1, m + 1, r, L, R);
      return res;
    }
  };

  build(build, 1, 1, n);
  for (int i = 1; i <= m; i ++) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      set(set, 1, 1, n, l, r, x);     
    }

    if (op == 2) {
      int l, r;
      cin >> l >> r;
      cout << ask(ask, 1, 1, n, l, r) << "\n";
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