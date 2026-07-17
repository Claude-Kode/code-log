// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;



void solve() { 

  int n; cin >> n;
  vector<vector<int>> grid(n + 1, vector<int>(n + 1));
  while (true) {
    int x, y, w; cin >> x >> y >> w;
    if (!x && !y && !w) break; 
    grid[x][y] = w;
  }

  vector<vector<vector<vector<int>>>> memo(n + 1, 
  vector<vector<vector<int>>>(n + 1,
  vector<vector<int>>(n + 1,
  vector<int>(n + 1))));

  std::function<int(int, int, int, int)> dfs = [&](int x1, int y1, int x2, int y2) -> int{
    if (x1 > n || y1 > n || x2 > n || y2 > n) return 0;
    if (memo[x1][y1][x2][y2]) return memo[x1][y1][x2][y2];
    int &res = memo[x1][y1][x2][y2];

    if (x1 < n && x2 < n) {
      res = max(res, 
        dfs(x1 + 1, y1, x2 + 1, y2) + grid[x1 + 1][y1] + 
        grid[x2 + 1][y2] - grid[x1 + 1][y1] * (x1 + 1 == x2 + 1 && y1 == y2));
    }


    if (x1 < n && y2 < n) {
      int val = grid[x1 + 1][y1] + grid[x2][y2 + 1];
      if (x1 + 1 == x2 && y1 == y2 + 1) val -= grid[x1 + 1][y1];
      res = max(res, dfs(x1 + 1, y1, x2, y2 + 1) + val);
    }
    
    if (y1 < n && x2 < n) {
      int val = grid[x1][y1 + 1] + grid[x2 + 1][y2];
      if (x1 == x2 + 1 && y1 + 1 == y2) val -= grid[x1][y1 + 1];
      res = max(res, dfs(x1, y1 + 1, x2 + 1, y2) + val);
    }
    
    if (y1 < n && y2 < n) {
      int val = grid[x1][y1 + 1] + grid[x2][y2 + 1];
      if (x1 == x2 && y1 + 1 == y2 + 1) val -= grid[x1][y1 + 1];
      res = max(res, dfs(x1, y1 + 1, x2, y2 + 1) + val);
    }

    return res;

  };

  cout << dfs(1, 1, 1, 1) + grid[1][1] << endl; 
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}

