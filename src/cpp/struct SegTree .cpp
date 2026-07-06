#include <iostream>
#include <vector>

template<typename Info, typename Tag>
class SegmentTree {
private:
  int n = 0;
  std::vector<Info> vec;
  std::vector<Info> seg;
  std::vector<Tag> tag;

  static int ls(int i) {
    return i << 1;
  }

  static int rs(int i) {
    return i << 1 | 1;
  }

  void pull(int p) {
    seg[p] = seg[ls(p)] + seg[rs(p)];
  }

  void apply(int p, const Tag& t) {
    seg[p] += t;
  }

  void push(int p) {
    apply(ls(p), tag[p]);
    apply(rs(p), tag[p]);
    tag[p] = Tag();
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
  }

  void modify(int p, int l, int r, int L, int R, const Tag& t) {
    if (l <= L && R <= r) {
      apply(p, t);
      return;
    }
    push(p);
    int m = (l + r) / 2;
    modify(ls(p), l, m, L, R, t);
    modify(rs(p), m + 1, r, L, R, t);
    pull(p);
  } 

  Info aks(int p, int l, int r, int L, int R) {
    if (l <= L && R <= r) {
      return seg[p];
    }
    push(p);
    int m = (l + r) / 2; Info res;
    if (L <= m) res += aks(ls(p), l, m, L, R, t);
    if (m < R) res += aks(rs(p), m + 1, r, L, R, t);
    return res;
  }

public:
  SegmentTree() = default;
  SegmentTree(int _n) {
    n = _n;
    vec = std::vector<Info>(n);
    seg = std::vector<Info>(n << 2 | 1);
    tag = std::vector<Tag>(n << 2 | 1);
  }

  SegmentTree(std::vector<Info> vec) {
    n = vec.size() - 1;
    this -> vec = vec;
    this -> info = std::vector<Info>(n << 2 | 1);
    this -> tag = std::vector<Tag>(n << 2 | 1);
    build(1, 1, n);
  }

  void modify(int l, int r, int v) {
    Tag t(0, v, false);
    modify(1, 1, n, l, r, t);
  } 

  void modify(int p, int v) {
    Tag t(0, v, false);
    modify(1, 1, n, p, p, t);
  } 

  void set(int l, int r, int v) {
    Tag t(v, 0, false);
    modify(1, 1, n, l, r, t);
  }

  void set(int p, int v) {
    Tag t(v, 0, false);
    modify(1, 1, n, p, p, t);
  }

  Info ask(int l, int r) {
    return ask(1, 1, n, l, r);
  }
};

struct Tag {
  int set = 0;
  int add = 0;
  bool has_set = false;
  Tag() = default;
  Tag(int _set, int _add, int _has_set)
    : set(_set), add(_add), has_set(_has_set) {}
  Tag& operator+=(const Tag& oth) {
    if (oth.has_set) {
      has_set = true;
      set = oth.set;
      add = 0;
    }
    if (oth.add) {
      add += oth.add;
    }
  }
  bool empty() { return add == 0 && !has_set; }
};

struct Infor {
  int v = 0;
  int mx = v;
  int mn = v;
  int sum = v;
  int len = 1;
  Infor() = default;
  Infor(int _v)
    : v(_v), mx(_v), mn(_v), sum(_v), len(1LL) {}
  Infor operator+(const Infor& oth) {
    Infor res = *this;
    res.v += oth.v;
    res.mx = std::max(res.mx, oth.mx);
    res.mn = std::min(res.mn, oth.mn);
    res.sum += oth.sum;
    res.len += oth.len;
    return res;
  }
  Infor& operator+=(const Tag& oth) {
    if (oth.has_set)  v = oth.set;
    if (oth.add)      v += oth.add;
    mx = std::max(mx, v);
    mn = std::min(mn, v);
    sum = len * v;
    return *this;
  }
};

int main() { 
  int n; 
  std::cin >> n;
  SegmentTree<Infor, Tag> seg(n + 1);

  return 0;
}
