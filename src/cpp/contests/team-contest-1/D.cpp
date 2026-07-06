// #ifdef __GNUC__
//   #pragma GCC optimize("fast-math")
//   #pragma GCC optimize("Ofast, unroll-loops = full")
//   #pragma GCC optimize("avx, avx2")
// #endif

#include <bits/stdc++.h>
using namespace std;

#define int long long 

int dirs[2][2] = {{1, 0}, {0, 1}};

// using ump = unordered_map<int, int>;

inline void solve() {
  int  n, m;
  cin >> n >> m;
  vector<vector<int>> price(n + 1, vector<int>(m + 1)),
                      cost(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      cin >> price[i][j];
    }
  }

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      cin >> cost[i][j];
    }
  }

  auto check = [&](int x, int y) -> bool {
    return x >= 1 and x <= n and y >= 1 and y <= m;
  };

  int base = price[1][1];
  queue<array<int, 3>> q;
  // vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
  // vis[1][1] = 1;
  q.push({1, 1, cost[1][1]});
  while (!q.empty()) {
    auto [x, y, mx] = q.front();
    q.pop();

    for (auto& [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (!check(nx, ny)) continue;
      //  or vis[nx][ny]
      int nmn = price[nx][ny] - base;
      int nmx = mx + cost[nx][ny];
      if (nmn < nmx) continue;
      if (nx == n or ny == m) {
        cout << "YES" << "\n";
        return;
      }
      q.push({nx, ny, nmx});
      // vis[nx][ny] = 1;
    }
  }

  cout << "NO" << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }
}