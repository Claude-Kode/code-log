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
  vector<int> f, siz; 
 public:  
  DSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
  }
  
  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }
  
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }
  
  int size(int x) {
    return siz[find(x)];
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  // eat.find(x) == fx fx   
  DSU dsu(3 * n + 1);

  int fake = 0;
  for (int i = 1; i <= m; i ++) {
    int op, x, y;
    cin >> op >> x >> y;
    
    if (x > n || y > n) {
      fake ++;
      continue;
    }

    if (op == 1) {
      if (dsu.same(x, y + n) || dsu.same(x + n, y)) {
        fake ++;
        continue;
      }
      dsu.merge(x, y);
      dsu.merge(x + n, y + n);
      dsu.merge(x + 2 * n, y + 2 * n);
    }
    
    if (op == 2) {
      if (dsu.same(x, y) || dsu.same(x + n, y)) {
        fake ++;
        continue;
      }
      dsu.merge(x, y + n);
      dsu.merge(x + n, y + 2 * n);
      dsu.merge(x + 2 * n, y);
    }
  }

  cout << fake << "\n";
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