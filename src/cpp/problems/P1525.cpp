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
      dis[x] ^= dis[f[x]];
      f[x] = ffx;
    }
    return f[x];
  }
  
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  bool merge(int x, int y, int w) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
      return false;
    }
    dis[fx] = (w + dis[y] - dis[x] + 2) % 2;
    f[fx] = fy;
    siz[fy] += siz[fx];
    return true;
  }
  
  int ask(int x, int y) {
    if (!same(x, y)) return 1;
    return (dis[x] + dis[y]) % 2;
  }

  int size(int x) {
    return siz[find(x)];
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> vec(m + 1);
  for (int i = 1; i <= m; i ++) {
    cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
  }

  sort(vec.begin() + 1, vec.end(), [&](const auto &a, const auto &b) {
    return a[2] > b[2];

  });

  DSU dsu(n + 1);
  for (int i = 1; i <= m; i ++) {
    int x = vec[i][0], y = vec[i][1];
    if (dsu.ask(x, y) == 0) {
      cout << vec[i][2] << "\n";
      return; 
    }
    dsu.merge(x, y, 1);
  }

  cout << 0 << "\n";
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