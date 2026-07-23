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

int dirs[4][2] = {
  {0, 1}, {1, 0}, {-1, 0},{0, -1}
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n + 1);
  int sx, sy, tx, ty;
  for (int i = 1; i <= n; i ++) {
    g[i].resize(m + 1);
    for (int j = 1; j <= m; j ++) {
      cin >> g[i][j];
      if (g[i][j] == 'S') sx = i, sy = j;
      if (g[i][j] == 'T') tx = i, ty = j;
    }
  }

  vector<vector<array<int, 2>>> dis(n + 1,
  vector<array<int, 2>>(m + 1, {INT_MAX, INT_MAX}));

  queue<tuple<int, int, int>> q; 
  q.push({sx, sy, 1});
  dis[sx][sy][1] = 0;

  while (!q.empty()) {
    auto [x, y, c] = q.front(); q.pop();
    if (x == tx and y == ty) { 
      cout << dis[x][y][c] << "\n"; return; 
    }

    int nd = dis[x][y][c] + 1;
    for (auto [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (nx < 1 or nx > n or ny < 1 or ny > m) continue;

      if (g[nx][ny] != '#') {             
        if (nd < dis[nx][ny][c]) {
          dis[nx][ny][c] = nd;
          q.push({nx, ny, c});
        }
      } else if (c > 0) {                  
        if (nd < dis[nx][ny][0]) {
          dis[nx][ny][0] = nd;
          q.push({nx, ny, 0});
        }
      }
    }
  }
  cout << -1 << "\n";
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