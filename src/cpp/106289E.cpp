// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

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

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void solve() { 

  auto t1 = [&](char c) -> int {
    return (c == 'U' ? 1 : c == 'D' ? 2 : c == 'L' ? 3 : c == 'R' ? 4 : 0);
  };

  int n, m; cin >> n >> m;
  vector<vector<unordered_map<int, int>>> g(n + 1, vector<unordered_map<int, int>>(m + 1));
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      char c1, c2; cin >> c1 >> c2;
      g[i][j][t1(c1)] = 1;
      g[i][j][t1(c2)] = 1;
    }
  }

  auto t2 = [&](int i, int j) -> int{return (i - 1) * m + j; };
  auto check = [&](int x1, int y1, int x2, int y2) -> bool {
    if (x2 == x1 - 1) return !g[x1][y1][1] && !g[x2][y2][2];
    if (x2 == x1 + 1) return !g[x1][y1][2] && !g[x2][y2][1];
    if (y2 == y1 - 1) return !g[x1][y1][3] && !g[x2][y2][4];
    if (y2 == y1 + 1) return !g[x1][y1][4] && !g[x2][y2][3];
    return false;
  };

  DSU dsu(n * m + 1);
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      for(const auto&[dx, dy] : dirs) {
        int x = i + dx, y = j + dy;
        if (x < 1 || x > n || y < 1 || y > m) continue;
        int d1 = t2(i, j), d2 = t2(x, y);
        if (check(i, j, x, y)) dsu.merge(d1, d2);
      }
    }
  }

  unordered_map<int, int> vis; 
  multiset<int> s;

  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      int m = t2(i, j), f = dsu.find(m);
      if (!vis[f]) s.insert(dsu.size(f)), vis[f] = 1;
    }
  }

  int a = 0, b = 0, cnt = 0;
  for(const auto &x : s) {
    if (cnt & 1) a += x - 1;
    else b += x - 1;
    cnt ++;
  }

  cout << (a > b ? "YES" : "NO") << endl;
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}