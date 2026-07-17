// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

class RollbackDSU {
 public:
  struct His {
    int x;
    int y;
  };

  vector<int> f, sz;
  vector<His> his;

 public:
  RollbackDSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    sz.assign(n, 1);
  }

  void init(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    sz.assign(n, 1);
    his.clear();
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x];
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
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    his.emplace_back(x, y);
    f[y] = x;
    sz[x] += sz[y];
    return true;
  }

  void rollback() {
    auto [x, y] = his.back();
    his.pop_back();
    f[y] = y;
    sz[x] -= sz[y];
  }
};

void solve() {
  int n, m;
  cin >> n >> m;

  RollbackDSU dsu(n + 1);
  for (int i = 1; i <= m; i ++) {
    int op;
    cin >> op;
    if (op == 1) {
      int a, b;
      cin >> a >> b;
      
    }

    if (op == 2) {
      int k;
      cin >> k;

    }

    if (op == 3) {
      int a, b;
      cin >> a >> b;

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