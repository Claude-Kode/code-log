// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n, m;

int dirs[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool c(int i, int j) {return i > 0 and i <= n and j > 0 and j <= m;}

void solve() { 
  cin >> n >> m;
  vector<vector<array<int, 2>>> vec(n + 1, vector<array<int, 2>>(m + 1));
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      cin >> vec[i][j][0];
      if (i == 1) vec[i][j][1] = 1;
      if (j == m) vec[i][j][1] = 1;
      if (j == 1) vec[i][j][1] = 2;
      if (i == n) vec[i][j][1] = 2;
    }
  }

  // for(int i = 1; i <= n; i ++) {
  //   for(int j = 1; j <= m; j ++) {
  //     cout << vec[i][j][1] << " \n"[j == m];
  //   }
  // }
 
  int mx = n + m - 1;
  vector<int> dis(mx + 1);
  vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
  queue<array<int, 2>> q; 
  for(int i = 1; i <= n; i ++) if (vec[i][m][0] <= mx) {
    q.push({i, m});
  }
  for(int i = 1; i <= m; i ++) if (vec[1][i][0] <= mx) {
    q.push({1, i});
  }

  while(!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    dis[vec[x][y][0]] |= vec[x][y][1];
    vis[x][y] = 1;
    for(const auto&[xx, yy] : dirs) {
      int nx = x + xx, ny = y + yy;
      if (c(nx, ny) and vec[nx][ny][0] == vec[x][y][0] and !vis[nx][ny]) {
        q.push({nx, ny});
      } 
    }
  }
   
  vector<int> nums(mx + 1);
  iota(nums.begin(), nums.end(), 0LL);
  set<int> mex(nums.begin(), nums.end());
  dis[vec[1][1][0]] = 3; dis[vec[n][m][0]] = 3;
  for(int i = 0; i <= mx; i ++) if (dis[i] == 3) { 
    mex.erase(i);
  }

  cout << *mex.begin() << endl; 
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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
} 
