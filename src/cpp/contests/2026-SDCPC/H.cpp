#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long 

void solve() {
  int n, m, K;
  cin >> n >> m >> K;
  vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      char c;
      cin >> c;
      grid[i][j] = (c == '#');
    }
  }

  // 1 代表有, 0 代表没有
  vector<vector<vector<int>>> pins(K + 1);
  for (int i = 1; i <= K; i ++) {
    int r, c;
    cin >> r >> c;
    pins[i].resize(r);
    for (int j = 0; j < r; j ++) {
      for (int k = 0; k < c; k ++) {
        char c; cin >> c;
        pins[i][j].push_back(c == '#');
      }
    }
  }

  map<int, array<int, 2>> corner;
  for (int i = 1; i <= K; i ++) {
    bool f = false;
    for (int j = 0; j < pins[i].size(); j ++) {
      for (int k = 0; k < pins[i][j].size(); k ++) {
        if (pins[i][j][k]) {
          corner[i] = {j, k};
          f = true;
          if (f) break;
        }
      }
      if (f) break;
    }
  }

  vector<int> REM;
  for (int i = 1; i <= K; i ++) REM.push_back(i);

  auto chk_yes = [&](const auto &g) -> bool {
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= m; j ++) {
        if (g[i][j] == 0) {
          return false;
        }
      }
    }
    return true;
  };

  auto find_corner = [&](const auto &g) -> array<int, 2> {
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= m; j ++) {
        if (g[i][j] == 0) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  };

  auto chk_coor = [&](int x, int y) -> bool {
    return x > 0 and x <= n and y > 0 and y <= m;
  };

  int ans = 0;
  auto dfs = [&](auto &&sef, vector<vector<int>>& G, vector<int>& rem) -> void {
    if (chk_yes(G)) {
      ans ++;
      return;
    }
    
    auto [X, Y] = find_corner(G);
    for (int &idx : rem) {
      if (idx == 0) continue;
      auto [x, y] = corner[idx];
      int difx = x - X, dify = y - Y;
      bool f = true;
      for (int i = 0; i < pins[idx].size(); i ++) {
        for (int j = 0; j < pins[idx][i].size(); j ++) {
          int curx = i - difx, cury = j - dify;
          if (!chk_coor(curx, cury) or pins[idx][i][j] & G[curx][cury]) {
            f = false;
            break;
          }
        }
        if (!f) break;
      }
      
      if (!f) continue;
      auto g = G;
      for (int i = 0; i < pins[idx].size(); i ++) {
        for (int j = 0; j < pins[idx][i].size(); j ++) {
          int curx = i - difx, cury = j - dify;
          if (pins[idx][i][j]) {
            g[curx][cury] = 1;
          }
        }
      }
      
      int temp = idx; idx = 0;
      sef(sef, g, rem);
      idx = temp;
    }
  };

  dfs(dfs, grid, REM);

  cout << ans << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1, _ = 0; 
  cin >> tt;
  while (tt -- and ++_) {
    // cout << "TEST_CASE: " << _ << "\n";
    solve();
  }

  return 0;
}