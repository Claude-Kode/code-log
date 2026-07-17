// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct Info {
  int sum = 0;
};

struct Tag {
  int rev = 0; 
};

template<typename Info, typename Tag>
class SegTree {
 private:
  int n;
  vector<Info> seg;
  vector<Tag> tag;

  void build(int p, int l, int r, const vector<int>& a) {
    if (l == r) {
      seg[p].sum = a[l];
      return;
    }
    int m = (l + r) >> 1;
    build(p << 1, l, m, a);
    build(p << 1 | 1, m + 1, r, a);
    pull(p);
  }

  void apply(int p, int l, int r) {
    seg[p].sum = (r - l + 1) - seg[p].sum;  
    tag[p].rev ^= 1;                        
  }

  void push(int p, int l, int r) {
    if (tag[p].rev == 0) return;
    int m = (l + r) >> 1;
    apply(p << 1, l, m);
    apply(p << 1 | 1, m + 1, r);
    tag[p].rev = 0;
  }

  void pull(int p) { seg[p].sum = seg[p << 1].sum + seg[p << 1 | 1].sum; }

  void flip(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
      apply(p, l, r);
      return;
    }
    push(p, l, r);
    int m = (l + r) >> 1;
    if (L <= m) flip(p << 1, l, m, L, R);
    if (R > m) flip(p << 1 | 1, m + 1, r, L, R);
    pull(p);
  }

  int ask(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return seg[p].sum;
    push(p, l, r);
    int m = (l + r) >> 1, res = 0;
    if (L <= m) res += ask(p << 1, l, m, L, R);
    if (R > m) res += ask(p << 1 | 1, m + 1, r, L, R);
    return res;
  }

 public:
  SegTree(int _n) : n(_n) {
    seg.resize(n << 2 | 1);
    tag.resize(n << 2 | 1);
  }

  void build(const vector<int>& a) { 
    build(1, 1, n, a); 
  }
  void flip(int l, int r) { 
    flip(1, 1, n, l, r); 
  }
  int query(int l, int r) { 
    return ask(1, 1, n, l, r); 
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<SegTree<Info, Tag>> segs(32, SegTree<Info, Tag>(n));

  for (int bit = 0; bit < 32; bit++) {
    vector<int> bits(n + 1);
    for (int i = 1; i <= n; i++) {
      bits[i] = (a[i] >> bit) & 1;
    }
    segs[bit].build(bits);
  }

  while (m --) {
    int op, l, r, x;
    cin >> op;
    if (op == 1) { 
      cin >> l >> r;
      int ans = 0;
      for (int i = 0; i < 32; i++) {
        int cnt = segs[i].query(l, r);
        ans += cnt * (1LL << i);
      }
      cout << ans << "\n";
    } else if (op == 2) { 
      cin >> l >> r >> x;
      for (int i = 0; i < 32; i++) {
        if ((x >> i) & 1) {
          segs[i].flip(l, r);
        }
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
