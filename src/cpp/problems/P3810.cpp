// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct tri {
  int a, b, c;
  int ans = 0, cnt = 1;
  bool operator<(const tri& oth) const {
    if (a != oth.a) return a < oth.a;
    if (b != oth.b) return b < oth.b;
    if (c != oth.c) return c < oth.c;
  }

  bool operator==(const tri& oth) const {
    return a == oth.a && b == oth.b && c == oth.c;
  }
};

class FenwickTree {
 public:
  int n;
  std::vector<int> tree;

 public:
  FenwickTree(int _n = 1) : n(_n) { tree.assign(n + 1, 0); }
  static int lowbit(int i) { return i & -i; }

  void update(int p, int v) {  // 不能 update(0, ?) 会死循环
    if (p <= 0) return;
    for (int i = p; i <= n; i += lowbit(i)) {
      tree[i] += v;
    }
  }

  int query(int p) {
    if (p <= 0) return 0;
    int res = 0;
    for (int i = p; i > 0; i -= lowbit(i)) {
      res += tree[i];
    }
    return res;
  }
};

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<tri> raw(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> raw[i].a >> raw[i].b >> raw[i].c;
  }

  std::sort(raw.begin() + 1, raw.end());
  std::vector<tri> vec(1); vec.push_back(raw[1]);
  for (int i = 2; i <= n; i ++) {
    if (vec.back() == raw[i]) vec.back().cnt ++;
    else vec.push_back(raw[i]);
  }

  // cout << "RAW: \n";
  // for (int i = 1; i <= n; i ++) {
  //   cout << raw[i].a << raw[i].b << raw[i].c << "\n";
  // }

  int m = vec.size() - 1;
  std::vector<tri> tmp(m + 1);
  FenwickTree bit(k + 1);

  // cout << "VEC: \n";
  // for (int i = 1; i <= m; i ++) {
  //   cout << raw[i].a << raw[i].b << raw[i].c << "\n";
  // }

  auto cdq = [&](auto && self, int l, int r) -> void {
    if (l >= r) return;
    int mid = (l + r) / 2;
    self(self, l, mid);
    self(self, mid + 1, r);

    int i = l, j = mid + 1, p = l;
    while (i <= mid && j <= r) {
      if (vec[i].b <= vec[j].b) {
        bit.update(vec[i].c, vec[i].cnt);
        tmp[p ++] = vec[i ++];
      } else {
        vec[j].ans += bit.query(vec[j].c);
        tmp[p ++] = vec[j ++];
      }
    }

    while (i <= mid) {
      bit.update(vec[i].c, vec[i].cnt);
      tmp[p ++] = vec[i ++];
    }

    while (j <= r) {
      vec[j].ans += bit.query(vec[j].c);
      tmp[p ++] = vec[j ++];
    }

    for (int t = l; t <= mid; t ++) {
      bit.update(vec[t].c, -vec[t].cnt);
    }

    for (int t = l; t <= r; t ++) {
      vec[t] = tmp[t];
    }

  };

  cdq(cdq, 1, m);

  std::vector<int> ans(n);
  for (int i = 1; i <= m; i ++) {
    int v = vec[i].ans + vec[i].cnt - 1;
    ans[v] += vec[i].cnt;
  }

  for (int i = 0; i < n; i ++) {
    std::cout << ans[i] << "\n";
  }
}

/*
如果是 cdq 解决 k 维偏序问题 我们是第一维用排序 中间归并 最后一维用 BIT
*/

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
