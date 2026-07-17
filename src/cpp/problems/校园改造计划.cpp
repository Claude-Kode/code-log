// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve() { 
  int n, m; cin >> n >> m;
  vector<vector<int>> vec(n + 2, vector<int>(m + 2));
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      cin >> vec[i][j];
    }
  }

  auto check = [&](int x, int y) -> bool {
    int res = 0;
    queue<array<int, 2>> q; q.push({x, y});
    unordered_map<int, unordered_map<int, int>> vis;
    while(!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      vis[x][y] = 1; res ++;
      if (res == 3) break;
      for(const auto&[xx, yy] : dirs) if (!vis[x + xx][y + yy] && vec[x + xx][y + yy]) {
         q.push({x + xx, y + yy});
      }
    }
    return res == 3;
  }; 

  int ans = INT_MAX; bool f = false;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) if (vec[i][j]) {
      int temp = 0; f = true;
      for(const auto &[x, y] : dirs) {
        temp += vec[i + x][j + y];
      }
      if (check(i, j)) 
        ans = min(ans, temp);
      else ans = min(ans, (int64_t)2);
    }
  } 

  cout << (f ? ans : 0) << endl;
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