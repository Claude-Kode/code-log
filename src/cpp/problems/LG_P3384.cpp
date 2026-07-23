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

// ============================
// 懒标 SGT
// ============================

struct Tag {
  int add = 0;
  bool empty() const { return add == 0; }
  Tag operator+(const Tag &o) const { return Tag{add + o.add}; }
};

struct Info {
  int sum = 0;
  Info operator+(const Info &o) const { return Info{sum + o.sum}; }
  Info& operator+=(const Info &o) { sum += o.sum; return *this; }
  void apply(const Tag &t, int len) { sum += t.add * len; }
};

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
    build(a);
  }

  void build(const vector<int> &a) { build(1, 1, n, a); }
  void upd(int l, int r, int v) { upd(1, 1, n, l, r, v); }
  int ask(int l, int r) { return ask(1, 1, n, l, r).sum; }

 private:
  void put(int p, int l, int r, const Tag &tg) {
    seg[p].apply(tg, r - l + 1);
    tag[p] = tag[p] + tg;
  }

  void push(int p, int l, int r) {
    if (tag[p].empty()) return;
    int m = (l + r) >> 1;
    put(p << 1, l, m, tag[p]);
    put(p << 1 | 1, m + 1, r, tag[p]);
    tag[p] = Tag();
  }

  void pull(int p) { seg[p] = seg[p << 1] + seg[p << 1 | 1]; }

  void build(int p, int l, int r, const vector<int> &a) {
    if (l == r) { seg[p] = Info{a[l]}; return; }
    int m = (l + r) >> 1;
    build(p << 1, l, m, a);
    build(p << 1 | 1, m + 1, r, a);
    pull(p);
  }

  void upd(int p, int l, int r, int L, int R, int v) {
    if (L <= l and r <= R) { put(p, l, r, Tag{v}); return; }
    push(p, l, r);
    int m = (l + r) >> 1;
    if (L <= m) upd(p << 1, l, m, L, R, v);
    if (R > m)  upd(p << 1 | 1, m + 1, r, L, R, v);
    pull(p);
  }

  Info ask(int p, int l, int r, int L, int R) {
    if (L <= l and r <= R) return seg[p];
    push(p, l, r);
    int m = (l + r) >> 1;
    Info res = Info();
    if (L <= m) res += ask(p << 1, l, m, L, R);
    if (R > m)  res += ask(p << 1 | 1, m + 1, r, L, R);
    return res;
  }
};

// ============================
// 重链剖分 — P3384
// ============================

void solve() {
  int n, m, root, MOD;
  cin >> n >> m >> root >> MOD;

  vector<int> w(n + 1);
  for (int i = 1; i <= n; i ++) cin >> w[i];

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i ++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> fa(n + 1), dep(n + 1), siz(n + 1), son(n + 1);
  vector<int> top(n + 1), dfn(n + 1), rnk(n + 1), nw(n + 1);

  int timer = 0;

  auto dfs1 = [&](auto &&sef, int u, int f) -> void {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    for (const auto &v : g[u]) if (v != f) {
      sef(sef, v, u);
      siz[u] += siz[v];
      if (son[u] == 0 or siz[son[u]] < siz[v]) son[u] = v;
    }
  };
  dfs1(dfs1, root, 0);

  auto dfs2 = [&](auto &&sef, int u, int tp) -> void {
    top[u] = tp;
    dfn[u] = ++ timer;
    rnk[timer] = u;
    nw[timer] = w[u] % MOD;
    if (son[u] == 0) return;
    sef(sef, son[u], tp);
    for (const auto &v : g[u]) {
      if (v == fa[u] or v == son[u]) continue;
      sef(sef, v, v);
    }
  };
  dfs2(dfs2, root, root);

  // 线段树建在 dfn 序上，取模依赖外部 MOD，这里特化一下
  struct InfoH {
    int sum = 0;
    InfoH operator+(const InfoH &o) const { return InfoH{(sum + o.sum) % MOD}; }
    InfoH& operator+=(const InfoH &o) { sum = (sum + o.sum) % MOD; return *this; }
    void apply(const Tag &t, int len) { sum = (sum + t.add * len) % MOD; }
  };
  SGT<InfoH, Tag> seg(nw);

  auto upd_path = [&](int u, int v, int k) -> void {
    k %= MOD;
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) swap(u, v);
      seg.upd(dfn[top[u]], dfn[u], k);
      u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    seg.upd(dfn[u], dfn[v], k);
  };

  auto ask_path = [&](int u, int v) -> int {
    int res = 0;
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) swap(u, v);
      res = (res + seg.ask(dfn[top[u]], dfn[u])) % MOD;
      u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    res = (res + seg.ask(dfn[u], dfn[v])) % MOD;
    return res;
  };

  auto upd_sub = [&](int x, int k) -> void {
    k %= MOD;
    seg.upd(dfn[x], dfn[x] + siz[x] - 1, k);
  };

  auto ask_sub = [&](int x) -> int {
    return seg.ask(dfn[x], dfn[x] + siz[x] - 1);
  };

  auto lca = [&](int u, int v) -> int {
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) swap(u, v);
      u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
  };

  while (m --) {
    int op, x, y, z;
    cin >> op;
    if (op == 1) { cin >> x >> y >> z; upd_path(x, y, z); }
    else if (op == 2) { cin >> x >> y; cout << ask_path(x, y) << '\n'; }
    else if (op == 3) { cin >> x >> z; upd_sub(x, z); }
    else { cin >> x; cout << ask_sub(x) << '\n'; }
  }
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

