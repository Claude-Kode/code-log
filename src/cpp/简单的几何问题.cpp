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

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void solve() { 
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      char c; cin >> c;
      g[i][j] = c == '1';
    }
  }

  // dbug(g);

  auto check = [&](int x, int y) -> bool {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };

  auto calc = [&](int x, int y) -> int {
    int res = 4;
    for(const auto& [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (!check(nx, ny)) continue;
      res -= g[nx][ny];
    }
    return res;
  };

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) if (g[i][j]) {
      ans += calc(i, j);
    }
  }

  cout << ans << endl;
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