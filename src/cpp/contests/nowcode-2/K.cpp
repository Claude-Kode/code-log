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

const int inf = LLONG_MAX / 2;

void solve() {
  int n, m, c;
  cin >> n >> m >> c;
  // dbug(n, m, c);

  vector<vector<int>> g(n + 1, vector<int>(n + 1, inf));
  unordered_map<int, pair<int, int>> ump;
  for (int i = 1 ; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u][v] = g[v][u] = c;
    ump[i] = pair(u, v);
  }

  int k; cin >> k;
  for (int i = 1; i <= k; i++) {
    int idx, w; cin >> idx >> w;
    auto [u, v] = ump[idx];
    g[u][v] = g[v][u] = w;
  }

  using pii = pair<int, int>;
  auto calc = [&](int s, int t) -> int {
    auto dis = vector<int>(n + 1, inf);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(pii(0, s)); dis[s] = 0;
    while (!pq.empty()) {
      auto [w, u] = pq.top(); pq.pop();
      if (w != dis[u]) continue;
      if (u == t) return w;
      for (int v = 1; v <= n; v++) {
        int nw = w + g[u][v];
        if (nw >= dis[v]) continue;
        dis[v] = nw;
        pq.emplace(pii(nw, v));
      }
    }
    return -1;
  };

  int q; cin >> q;
  for (int _ = 1; _ <= q; _++) {
    int IDX, W; cin >> IDX >> W;
    auto [u, v] = ump[IDX];
    g[u][v] = g[v][u] = W;
    int __; cin >> __;
    for (int ___ = 1; ___ <= __; ___++) {
      int s, t; cin >> s >> t;
      int ans = calc(s, t);
      // assert(ans);
      cout << ans << "\n";
    }
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

class SGT {
  int off = 0;
  std::vector<int> seg;
  void pull(int i) {
    seg[i] = std::max(seg[i << 1], seg[i << 1 | 1]);
  }

 public: 
  SGT() = default;
  SGT(int n) {
    off = std::bit_ceil(uint64_t(n + 2));
    seg.assign(off << 1, 0);
  }

  void upd(int p, int v) {
    if (seg[p += off] <= v) return;
    seg[p] = std::max(seg[p], v);
    while (p >>= 1) pull(p);
  } 

  int ask(int l, int r) {
    if (l > r) return 0;
    int res = 0;
    for (l += off - 1, r += off + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1) res = std::max(res, seg[l ^ 1]);
      if ( r & 1) res = std::max(res, seg[r ^ 1]);
    }
    return res;
  }
};