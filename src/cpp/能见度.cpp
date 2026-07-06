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
  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> g(n + 2, vector<int>(m + 2));

  while(q --) {
    int op; cin >> op;
    if (op == 1) {
      int x1, y1, x2, y2, k; 
      cin >> x1 >> y1 >> x2 >> y2 >> k;
      for(int i = x1; i <= x2; i ++) {
        for(int j = y1; j <= y2; j ++) {
          g[i][j] += k;
        }
      }
    } else {
      int x, y, res = 1; cin >> x >> y;
      for(int i = x - 1; i > 0; i --) {
        // g[i][y]
        if (g[i][y] <= g[x][y]) res ++;
        else break;
      }
      for(int i = x + 1; i <= n; i ++) {
        // g[i][y]
        if (g[i][y] <= g[x][y]) res ++;
        else break;
      }
      for(int j = y - 1; j > 0; j --) {
        // g[x][j]
        if (g[x][j] <= g[x][y]) res ++;
        else break;
      }
      for(int j = y + 1; j <= m; j ++) {
        // g[x][j]
        if (g[x][j] <= g[x][y]) res ++;
        else break;
      }
      cout << res << ' ';
    }
  }
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}