#include <bits/stdc++.h>
using namespace std;


template<typename Infor, typename Tag> 
class SegmentTree {
 public:
  int n;
  vector<Infor> seg = {};
  vector<Tag> tag = {};

  SegmentTree(int _n) : n(_n) { 
    init();
  }

  SegmentTree(const vector<int>& a) : n(a.size() - 1){
    init();
    build(1, 1, n, a);
  }

  void init() {
    seg.assign(4 * n + 1, Infor());
    tag.assign(4 * n + 1, Tag());
  }

  void build(int p, int l, int r, const vector<int>& a) {
    if (l == r) {
      apply(p, l, r, Tag{a[l]});
    } else {
      int m = (l + r) >> 1;
      build(p << 1, l, m, a);
      build(p << 1 | 1, m + 1, r, a);
      pull(p);
    }
  }

  void apply(int p, int l, int r, Tag v) {
    seg[p].sum += (r - l + 1) * v;
    seg[p].mx += v;
    tag[p] += v;
  }

  void push(int p, int l, int r) {
    if (tag[p] == Tag()) return;
    int m = (l + r) >> 1;
    apply(p << 1, l, m, tag[p]);
    apply(p << 1 | 1, m + 1, r, tag[p]);
    tag[p] = Tag();
  }

  void pull(int p) {
    seg[p].sum = seg[p << 1].sum + seg[p << 1 | 1].sum;
    seg[p].mx = max(seg[p << 1].mx, seg[p << 1 | 1].mx);
  }

  void add(int p, int l, int r, int L, int R, int v) {
    if (L <= l and r <= R) {
      apply(p, l, r, Tag{v});
    } else {
      push(p, l, r);
      int m = (l + r) >> 1;
      if (L <= m) add(p << 1, l, m, L, R, v);
      if (R > m) add(p << 1 | 1, m + 1, r, L, R, v);
      pull(p);
    }
  }

  Infor ask(int p, int l, int r, int L, int R) {
    if (L <= l and r <= R) {
      return seg[p];
    } else {
      push(p, l, r);
      int m = (l + r) >> 1; Infor res;
      if (L <= m) res += ask(p << 1, l, m, L, R);
      if (R > m)  res += ask(p << 1 | 1, m + 1, r, L, R);
      return res;
    }
  }

 public:
  void add(int l, int r, int v) { 
    add(1, 1, n, l, r, v); 
  }

  Infor ask(int l, int r) { 
    return ask(1, 1, n, l, r); 
  }
};

struct Infor{
  int sum = 0;
  int mx = 0;
  // 可以重载一个 信息之间的加号
  Infor& operator+=(const Infor &other) {
    sum += other.sum;
    mx = max(mx, other.mx);
    return *this;
  }
};

int main() {
  int n, m; cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }
  SegmentTree<Infor, int> seg(vec);
  for (int i = 1; i <= m; i ++) {
    int op; cin >> op;
    if (op == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      seg.add(l, r, x);
    }

    if (op == 2) {
      int l, r;
      cin >> l >> r;
      cout << seg.ask(l, r).sum << "\n";
    }
  }
  return 0;
}