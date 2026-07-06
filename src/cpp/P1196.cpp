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

  bool merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return false;
    // dis between fx -> fy
    dis[fx] += siz[fy];
    f[fx] = fy;
    siz[fy] += siz[fx];
    return true;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int ask(int x, int y) {
    if (!same(x, y)) return -1;
    return abs(dis[x] - dis[y]) - 1;
  }

  int size(int x) {
    return siz[find(x)];
  }
};

const int n = 3e4;

void solve() {
  int m;
  cin >> m;

  DSU dsu(n + 1);
  for (int i = 1; i <= m; i ++) {
    char op; cin >> op;
    int l, r; cin >> l >> r;
    if (op == 'M') {
      dsu.merge(l, r);
    }

    if (op == 'C') {
      cout << dsu.ask(l, r) << "\n";
    }
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