// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

template<typename Info, typename Tag>
class SGT {
 public:
  int n;
  vector<Info> seg;
  vector<Tag> tag;

  SGT(int _n = 0) : n(_n) {
    seg.assign(4 * n + 1, Info());
    tag.assign(4 * n + 1, Tag());
  }

  SGT(const vector<int> &a) : n(a.size() - 1) {
    seg.assign(4 * n + 1, Info());
    tag.assign(4 * n + 1, Tag());
    build(1, 1, n, a);
  }

  void build(const vector<int> &a) { build(1, 1, n, a); }

  void upd(int l, int r, int v) { upd(1, 1, n, l, r, v); }

  Info ask(int l, int r) { return ask(1, 1, n, l, r).sum; }

 private:
  void put(int p, int l, int r, const Tag &tg) {
    seg[p].sum += tg.add * (r - l + 1);
    tag[p] = tag[p] + tg;
  }

  void push(int p, int l, int r) {
    if (tag[p].empty()) return;
    int m = (l + r) >> 1;
    put(p << 1, l, m, tag[p]);
    put(p << 1 | 1, m + 1, r, tag[p]);
    tag[p] = Tag();
  }

  void pull(int p) {
    seg[p] = seg[p << 1] + seg[p << 1 | 1];
  }

  void build(int p, int l, int r, const vector<int> &a) {
    if (l == r) {
      seg[p] = {a[l]};
    } else {
      int m = (l + r) >> 1;
      build(p << 1, l, m, a);
      build(p << 1 | 1, m + 1, r, a);
      pull(p);
    }
  }

  void upd(int p, int l, int r, int L, int R, int v) {
    if (L <= l and r <= R) {
      put(p, l, r, {v});
    } else {
      push(p, l, r);
      int m = (l + r) >> 1;
      if (L <= m) upd(p << 1, l, m, L, R, v);
      if (R > m)  upd(p << 1 | 1, m + 1, r, L, R, v);
      pull(p);
    }
  }

  Info ask(int p, int l, int r, int L, int R) {
    if (L <= l and r <= R) return seg[p];
    push(p, l, r);
    int m = (l + r) >> 1;
    if (R <= m) return ask(p << 1, l, m, L, R);
    if (L > m)  return ask(p << 1 | 1, m + 1, r, L, R);
    return ask(p << 1, l, m, L, R) + ask(p << 1 | 1, m + 1, r, L, R);
  }
};

struct Info {
  int sum = 0;
  Info operator+(const Info &o) const { return {sum + o.sum}; }
};

struct Tag {
  int add = 0;
  bool empty() const { return add == 0; }
  Tag operator+(const Tag &o) const { return {add + o.add}; }
};

void solve() {  
  


} 
    
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
} 