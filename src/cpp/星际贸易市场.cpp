// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

const int mod = 998244353;

int fp(int x, int p, int mod) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

int inv (int x , int mod) { 
  return fp(x , mod - 2 , mod) ; 
}

template<typename Info, typename Tag> 
class SegmentTree {
 public:
  int n;
  vector<Info> seg;
  vector<Tag> tag;

  SegmentTree(int _n) : n(_n) {
    init();
  }

  SegmentTree(const vector<int>& a) : n(a.size() - 1){
    init();
    build(1, 1, n, a);
  }

  void init() {
    seg.assign(4 * n + 1, Info{});
    tag.assign(4 * n + 1, 0);
  }

  void build(int p, int l, int r, const vector<int>& a) {
    if (l == r) {
      seg[p].sum = a[l];
      seg[p].qsum = a[l] * a[l];
    } else {
      int m = (l + r) >> 1;
      build(p << 1, l, m, a);
      build(p << 1 | 1, m + 1, r, a);
      pull(p);
    }
  }

  void apply(int p, int l, int r, int v) {
    v %= mod;
    seg[p].qsum += (2 * seg[p].sum * v) % mod + (v * v) % mod * (r - l + 1) % mod;
    seg[p].sum += (r - l + 1) * v;
    tag[p] += v;
    seg[p].qsum %= mod;
    seg[p].sum %= mod;
    tag[p] %= mod;
  }

  void push(int p, int l, int r) {
    if (tag[p] == 0) return;
    int m = (l + r) >> 1;
    apply(p << 1, l, m, tag[p]);
    apply(p << 1 | 1, m + 1, r, tag[p]);
    tag[p] = 0;
  }

  void pull(int p) {
    seg[p].sum = (seg[p << 1].sum % mod + seg[p << 1 | 1].sum % mod) % mod;
    seg[p].qsum = (seg[p << 1].qsum % mod + seg[p << 1 | 1].qsum % mod) % mod;
  }

  void add(int p, int l, int r, int L, int R, int v) {
    if (L <= l and r <= R) {
      apply(p, l, r, v);
    } else {
      push(p, l, r);
      int m = (l + r) >> 1;
      if (L <= m) add(p << 1, l, m, L, R, v);
      if (R > m) add(p << 1 | 1, m + 1, r, L, R, v);
      pull(p);
    }
  }

  Info sum(int p, int l, int r, int L, int R) {
    if (L <= l and r <= R) {
      return seg[p];
    } else {
      push(p, l, r);
      int m = (l + r) >> 1; Info res;
      if (L <= m) res += sum(p << 1, l, m, L, R);
      if (R > m)  res += sum(p << 1 | 1, m + 1, r, L, R);
      return res;
    }
  }

 public:
  void add(int l, int r, int v) { 
    add(1, 1, n, l, r, v); 
  }

  Info sum(int l, int r) { 
    return sum(1, 1, n, l, r); 
  }
};

struct Infor {
  int sum = 0;
  int qsum = 0;
  Infor& operator+= (const auto &other) {
    sum += other.sum;
    qsum += other.qsum;
    sum %= mod;
    qsum %= mod;
    return *this;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i]; vec[i] %= mod;
  }

  int inv2 = inv(2, mod);

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
      Infor res = seg.sum(l, r);
      int sum = res.sum, qsum = res.qsum;
      cout << ((sum * sum) % mod - qsum % mod + mod) * inv2 % mod << "\n";
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