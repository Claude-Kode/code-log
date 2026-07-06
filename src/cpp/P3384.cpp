// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif

// template<typename Infor, typename Tag>
// class SegmentTree {
//  public:
//   int n;
//   vector<Infor> seg;
//   vector<Tag> tag;

//   SegmentTree(int _n) : n(_n) { init(); }
//   SegmentTree(const vector<int>& a) : n(a.size() - 1) { init(); build(1, 1,
//   n, a); }

//   void init() {
//     seg.assign(4 * n + 1, Infor());
//     tag.assign(4 * n + 1, Tag());
//   }

//   void build(int p, int l, int r, const vector<int>& a) { ... }
//   void apply(int p, int l, int r, Tag v) { ... }
//   void push(int p, int l, int r) { ... }
//   void pull(int p) { ... }
//   void modify(int p, int l, int r, int L, int R, int v) { ... }
//   Infor ask(int p, int l, int r, int L, int R) { ... }

//  public:
//   void modify(int l, int r, int v) { modify(1, 1, n, l, r, v); }
//   Infor ask(int l, int r) { return ask(1, 1, n, l, r); }
// };

// template<typename Infor, typename Tag>
// class SegmentTree {
//  public:
//   int n;
//   vector<Infor> seg = {};
//   vector<Tag> tag = {};

//   SegmentTree(int _n) : n(_n) {
//     init();
//   }

//   SegmentTree(const vector<int>& a) : n(a.size() - 1){
//     init();
//     build(1, 1, n, a);
//   }

//   void init() {
//     seg.assign(4 * n + 1, Infor());
//     tag.assign(4 * n + 1, Tag());
//   }

//   void build(int p, int l, int r, const vector<int>& a) {
//     if (l == r) {
//       apply(p, l, r, Tag{a[l]});
//     } else {
//       int m = (l + r) >> 1;
//       build(p << 1, l, m, a);
//       build(p << 1 | 1, m + 1, r, a);
//       pull(p);
//     }
//   }

//   void apply(int p, int l, int r, Tag v) {
//     seg[p] += v;
//     tag[p] += v;
//   }

//   void push(int p, int l, int r) {
//     if (tag[p] == Tag()) return;
//     int m = (l + r) >> 1;
//     apply(p << 1, l, m, tag[p]);
//     apply(p << 1 | 1, m + 1, r, tag[p]);
//     tag[p] = Tag();
//   }

//   void pull(int p) {
//     seg[p] = seg[p << 1] + seg[p << 1 | 1];
//   }

//   void modify(int p, int l, int r, int L, int R, int v) {
//     if (L <= l and r <= R) {
//       apply(p, l, r, Tag{v});
//     } else {
//       push(p, l, r);
//       int m = (l + r) >> 1;
//       if (L <= m) modify(p << 1, l, m, L, R, v);
//       if (R > m) modify(p << 1 | 1, m + 1, r, L, R, v);
//       pull(p);
//     }
//   }

//   Infor ask(int p, int l, int r, int L, int R) {
//     if (L <= l and r <= R) {
//       return seg[p];
//     } else {
//       push(p, l, r);
//       int m = (l + r) >> 1; Infor res;
//       if (L <= m) res += ask(p << 1, l, m, L, R);
//       if (R > m)  res += ask(p << 1 | 1, m + 1, r, L, R);
//       return res;
//     }
//   }

//  public:
//   void modify(int l, int r, int v) {
//     modify(1, 1, n, l, r, v);
//   }

//   Infor ask(int l, int r) {
//     return ask(1, 1, n, l, r);
//   }
// };

// struct Infor{
//   int sum = 0;
//   int mx = 0;
//   // 可以重载一个 信息之间的加号
//   Infor& operator+=(const Infor &other) {
//     sum += other.sum;
//     mx = max(mx, other.mx);
//     return *this;
//   }

//   Infor operator+(const Infor &other) {
//     Infor res;
//     res.sum = sum + other.sum;
//     res.mx = std::max(sum, other.mx);
//     return res;
//   }

//   Infor& operator+=(const int &other) {
//     sum += other;
//     mx += other;
//     return *this;
//   }

// };

// int timer = 0;

// void solve() {
//   int n, m, r, mod;
//   cin >> n >> m >> r >> mod;

//   vector<vector<int>> adj(n + 1);
//   for (int i = 1; i < n; i ++) {
//     int u, v;
//     cin >> u >> v;
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//   }

//   vector<int> fa(n + 1), son(n + 1, -1), dep(n + 1), sz(n + 1, 1);
//   auto dfs1 = [&](auto &&sef, int u, int f) -> void {
//     fa[u] = f;
//     dep[f] = dep[u] + 1;
//     for (const auto &v : adj[u]) if (v != f) {
//       sef(sef, v, u);
//       if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
//     }
//   };

//   dfs1(dfs1, r, 0);

//   vector<int> dfn(n + 1), top(n + 1);
//   auto dfs2 = [&](auto &&sef, int u, int tp) -> void {
//     top[u] = tp;
//     dfn[u] = ++timer;
//     if (son[u] == -1) return;
//     sef(sef, son[u], tp);
//     for (const int &v : adj[u]) {
//       if (v == son[u] || v == fa[u]) continue;
//       sef(sef, v, v);
//     }
//   };

//   dfs2(dfs2, r, r);

//   auto lca = [&](int u, int v) -> int {

//   };

//   SegmentTree<Infor, int> seg(n + 1);

// }

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);

//   int tt = 1, _ = 0;
//   std::cin >> tt;
//   while (tt-- && ++_)
//     // std::cout << "TEST CASE : " << _ << endl,
//     solve();

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

template <typename Info, typename Tag>
class SegmentTree {
 public:
  int n;
  vector<Info> seg;
  vector<Tag> tag;

 private:
  // 三个操作，用 std::function 保存（lambda 可以自动转换）
  function<Info(const Info&, const Info&)> pull_op;
  function<Info(const Info&, const Tag&, int, int)> apply_op;
  function<Tag(const Tag&, const Tag&)> compose_op;

  void apply(int p, int l, int r, const Tag& v) {
    seg[p] = apply_op(seg[p], v, l, r);
    tag[p] = compose_op(tag[p], v);
  }

  void push(int p, int l, int r) {
    if (tag[p] == Tag{}) return;  // 默认 Tag 是空标记
    int m = (l + r) >> 1;
    apply(p << 1, l, m, tag[p]);
    apply(p << 1 | 1, m + 1, r, tag[p]);
    tag[p] = Tag{};
  }

  void pull(int p) { seg[p] = pull_op(seg[p << 1], seg[p << 1 | 1]); }

  void build(int p, int l, int r, const vector<Info>& a) {
    if (l == r) {
      seg[p] = a[l - 1];
    } else {
      int m = (l + r) >> 1;
      build(p << 1, l, m, a);
      build(p << 1 | 1, m + 1, r, a);
      pull(p);
    }
  }

  void modify(int p, int l, int r, int L, int R, const Tag& v) {
    if (L <= l && r <= R) {
      apply(p, l, r, v);
    } else {
      push(p, l, r);
      int m = (l + r) >> 1;
      if (L <= m) modify(p << 1, l, m, L, R, v);
      if (R > m) modify(p << 1 | 1, m + 1, r, L, R, v);
      pull(p);
    }
  }

  Info ask(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return seg[p];
    push(p, l, r);
    int m = (l + r) >> 1;
    if (R <= m) return ask(p << 1, l, m, L, R);
    if (L > m) return ask(p << 1 | 1, m + 1, r, L, R);
    return pull_op(ask(p << 1, l, m, L, R), ask(p << 1 | 1, m + 1, r, L, R));
  }

 public:
  // 1. 只给大小，后续手动 build
  SegmentTree(int _n, function<Info(const Info&, const Info&)> _pull,
              function<Info(const Info&, const Tag&, int, int)> _apply,
              function<Tag(const Tag&, const Tag&)> _compose)
      : n(_n), pull_op(_pull), apply_op(_apply), compose_op(_compose) {
    seg.assign(4 * n + 1, Info{});
    tag.assign(4 * n + 1, Tag{});
  }

  // 2. 直接通过 int 数组初始化（最常用）
  //    要求 Info 有 Info(int) 构造函数，或者你手动建 vector<Info> 再调 build
  SegmentTree(const vector<int>& a,
              function<Info(const Info&, const Info&)> _pull,
              function<Info(const Info&, const Tag&, int, int)> _apply,
              function<Tag(const Tag&, const Tag&)> _compose)
      : n(a.size() - 1),
        pull_op(_pull),
        apply_op(_apply),
        compose_op(_compose) {
    seg.assign(4 * n + 1, Info{});
    tag.assign(4 * n + 1, Tag{});
    vector<Info> init(n);
    for (int i = 0; i < n; ++i) init[i] = Info(a[i + 1]);
    build(1, 1, n, init);
  }

  void build(const vector<Info>& a) { build(1, 1, n, a); }

  void modify(int l, int r, const Tag& v) { modify(1, 1, n, l, r, v); }

  Info ask(int l, int r) { return ask(1, 1, n, l, r); }
};

template<typename Info, typename Tag>
class SegmentTree {
 public:
  int n; 
  vector<Info> seg;
  vector<Tag> tag;
 private:
  void put(int p, int l, int r, const Tag &tg) {

  } 

  void push(int p, int l, int r) {
    if (tg.empty()) {
      return; 
    }
    int m = (l + r) >> 1;
    put(p << 1, l, m, tag[p]);
    put(p << 1 | 1, m + 1, r, tag[p]);
    tag[p] = Tag();
  }

  void pull(int p) {
    seg[p] = seg[p << 1] + seg[p << 1 | 1];
  }

  void build(int p, int l, int r) {
    if (l == r) {
      seg[p] = vec[l];
    } else {
      int m = (l + r) >> 1;
      build(p << 1, l, m);
      build(p << 1 | 1, m + 1, r);
      pull(p);
    }
  }

  void set(int p, int l, int r, int L, int R, const Tag &tg) {
    if (L <= l and r <= R) {
      put(p, l, r, tg);
    } else {
      push(p, l, r);
      int m = (l + r)  >> 1;
      if (L <= m) set(p << 1, l, m, L, R, tg);
      if (m < R) set(p << 1 | 1, m + 1, r, L, R, tg);
      pull(p);
    }
  }

  void ask(int p, int l, int r, int L, int R) {
    if (L <= l and r <= R) {
      return seg[p];
    } else {
      push(p, l, r);
      int m = (l + r)  >> 1;
      Info res;
      if (L <= m) res += ask(p << 1, l, m, L, R);
      if (m < R) res += (p << 1 | 1, m + 1, r, L, R);
      return res;
    }
  }

 public: 
  SegmentTree(): n(0) {}
  SegmentTree(int _n): n(_n) {}
  SegmentTree(const vector<int> &a): n(a.size() - 1) {

  }

  void set(int l, int r) {
    set(1, 1, n, l, r);
  }

  Info ask(int l, int r) {
    return ask(1, 1, n, l, r);
  }
};

void solve() {
  int n; cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end(), greater<int>());
  for (auto &a : vec) {
    cout << a << " \n"[a == vec.back()];
  }

  cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt; cin >> tt;
  while (tt --) 
    solve();

  return 0;
}