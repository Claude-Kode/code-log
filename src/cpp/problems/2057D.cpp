#include <bits/stdc++.h>

#define int long long 

template <typename info, typename Tag>
class SegmentTree {
 private:
  int n;
  std::vector<info> seg;
  std::vector<info> vec;
  std::vector<Tag> tag;
  static int ls(int i) { return i << 1; }
  static int rs(int i) { return i << 1 | 1; }

  void pull(int p) { 
    seg[p] = seg[ls(p)] + seg[rs(p)]; 
  }

  // 对节点 p 应用懒标记 t
  void apply(int p, const Tag& t) {
    seg[p] += t;
    tag[p] += t;
  }

  void push(int p) {
    if (!tag[p].empty()) {
      apply(ls(p), tag[p]);
      apply(rs(p), tag[p]);
      tag[p] = Tag();
    }
  }

  void init(std::vector<info> vec) {
    n = vec.size() - 1;
    this -> vec = vec;
    seg.assign(4 * n, info());
    tag.assign(4 * n, Tag());
    build(1, 1, n);
  }

  void build(int p, int l, int r) {
    if (l == r) {
      seg[p] = vec[l];
      return;
    }
    int m = (l + r) / 2;
    build(ls(p), l, m);
    build(rs(p), m + 1, r);
    pull(p);
  };

  void modify(int p, int l, int r, int L, int R, const Tag& t) {
    if (L <= l && r <= R) {
      apply(p, t);
      return;
    }
    push(p);
    int m = (l + r) / 2;
    if (L <= m) modify(ls(p), l, m, L, R, t);
    if (R > r) modify(ls(p), m + 1, r, L, R, t);
    pull(p);
  }

  info ask(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
      return seg[p];
    }
    push(p);
    int m = (l + r) / 2; info res = info();
    if (L <= m) res = res + ask(ls(p), l, m, L, R);
    if (m < R) res = res + ask(rs(p), l, m, L, R);
    return res;
  }

 public:
  SegmentTree() : n(0) {}

  SegmentTree(int _n, info _v = info()) : n(_n) {
    init(std::vector<info>(_n, _v));
  }

  // vec传递的是 1-based 的数组
  SegmentTree(std::vector<info> vec) { 
    init(vec); 
  }

  void rangeAdd (int l, int r, int v) {
    Tag t(v, 0, false);
    modify(1, 1, n, l, r, t);
  }

  void set (int p, int v) {
    Tag t(0, v, true); 
    modify(1, 1, n, p, p, t);
  }

  void rangeSet (int l, int r, int v) {
    Tag t(0, v, true); 
    modify(1, 1, n, l, r, t);
  }

  info rangeQuery  (int l, int r) {
    return ask(1, 1, n, l, r);
  }
};

struct Tag {
  int add = 0;
  int set = 0;
  bool has_set = false;
  
  Tag() = default;
  Tag(int _add, int _set, bool _has_set): add(_add), set(_set), has_set(_has_set) {}

  Tag& operator+=(const Tag& oth) {
    if (oth.has_set == true) {
      set = oth.set;
      add = 0;
      has_set = true;
    }
    add += oth.add;
    return *this;
  }

  bool empty() {
    return add == 0 && !has_set;
  }
};

struct Info {
  int sum = 0;
  int mx = LLONG_MIN / 2;
  int mn = LLONG_MAX / 2;
  int len = 1; 

  Info() = default;
  Info(int _v, int _len = 1) : sum(_v), mx(_v), mn(_v), len(_len) {}

  friend Info operator+(const Info& L, const Info& R) {
    Info res;
    res.sum = L.sum + R.sum;
    res.mx = std::max(L.mx, R.mx);
    res.mn = std::min(L.mn, R.mn);
    res.len = L.len + R.len;
    return res;
  }

  Info& operator+=(const Tag& t) {
    if (t.has_set) {
      sum = t.set * len;
      mx = mn = t.set;
    }
    if (t.add) {
      sum += t.add * len;
      mx += t.add;
      mn += t.add;
    }
    return *this;
  }
};

void solve() {

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