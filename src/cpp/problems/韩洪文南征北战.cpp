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
  std::vector<int> f, siz;
  
public: 
  DSU() {}
  DSU(int n) {
    init(n);
  }
  
  void init(int n) {
    f.resize(n);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n, 0);
  }
  
  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }
  
  void merge(int x, int y, int w) {
    x = find(x);
    y = find(y);
    if (x != y) {
      f[x] = y;
      siz[y] ^= siz[x];
    }
    siz[y] ^= w;
  }

  int size(int x) {
    return siz[find(x)];
  }
};

void solve() {    
  int n, m, k; 
  cin >> n >> m >> k;
  vector<array<int, 3>> edges;
  for (int i = 1; i <= m; i ++) {
    int u, v, w; 
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  } 

  auto calc = [&](int msk) -> int {
    DSU dsu(n + 1);
    for (int i = 0; i < m; i ++) {
      int u = edges[i][0], v = edges[i][1], w = edges[i][2];
      if ((msk >> (u - 1) & 1) && (msk >> (v - 1) & 1)) {
        dsu.merge(u, v, w);
      }
    }

    int res = 0;
    for (int i = 1; i <= n; i ++) if(msk >> (i - 1) & 1) {
      if (dsu.find(i) == i) res += dsu.size(i);
    }
    return res;
  };

  int ans = LLONG_MAX;
  for (int msk = 0; msk <= (1 << n) - 1; msk ++) {
    if (__builtin_popcount(msk) >= n - k && __builtin_popcount(msk) < n) {
      // int res = calc(msk);
      // cout << res << ' '
      ans = std::min(ans, calc(msk));
    }
  }

  std::cout << ans << "\n";
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