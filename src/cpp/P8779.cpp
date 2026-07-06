// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

// DSU
class DSU {
 public:
  vector<int> f, siz, dis; 
 public:  
  DSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
    dis.assign(n, 0);
  }
  
  int find(int x) {
    if (x != f[x]) {
      int ffx = find(f[x]);
      dis[x] += dis[f[x]];
      f[x] = ffx;
    }
    return f[x];
  }
  
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  bool merge(int x, int y, int w) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return false;
    // fx -> fy 
    int nw = w + dis[y] - dis[x];
    siz[fy] += siz[fx];
    dis[fx] += nw;
    f[fx] = fy;
    return true;
  }
  
  int ask(int l, int r) {
    if (!same(l, r)) {
      return -1;
    }
    return dis[l] - dis[r]; 
  }

  int size(int x) {
    return siz[find(x)];
  }
};


void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  DSU dsu(n + 2);
  for (int i = 1; i <= m; i ++) {
    int l, r, w;
    cin >> l >> r >> w;
    dsu.merge(l, r + 1, w);
  }

  for (int i = 1; i <= q; i ++) {
    int l, r;
    cin >> l >> r;
    int res = dsu.ask(l, r + 1);
    cout << (res == -1 ? "UNKNOWN" : to_string(res)) << "\n";
  }
}

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