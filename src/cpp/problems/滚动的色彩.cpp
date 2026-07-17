// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 301;
const int M = 301;

int n, m, sx, sy, tx, ty, ct; 
int c1, c2, c3, c4, c5, c6;

int dis[N][M][7][7][7] = {INT_MAX};

int opp[7] = {0, 6, 5, 4, 3, 2, 1}; // 1 -> 6, 2 -> 5, 3 -> 4

// dir: 1 = 上, 2 = 下, 3 = 左, 4 = 右
array<int, 3> roll(int U, int F, int R, int dir) {
  if (dir == 1) {// 上
    return {F, opp[U], R};
  } else if (dir == 2) {// 下
    return {opp[F], U, R};
  } else if (dir == 3) {// 左
    return {R, F, opp[U]};
  } else {// 右
    return {opp[R], F, U};
  }
}

// int cord[5][2]{{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int cord[5][2]{{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() { 

  cin >> n >> m ;
  cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
  cin >> sx >> sy >> tx >> ty >> ct;

  opp[c1] = c6;
  opp[c2] = c5;
  opp[c3] = c4;
  opp[c4] = c3;
  opp[c5] = c2;
  opp[c6] = c1;

  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      for(int x = 1; x <= 6; x ++) {
        for(int y = 1; y <= 6; y ++) {
          for(int z = 1; z <= 6; z ++) {
            dis[i][j][x][y][z] = INT_MAX;
          }
        }
      }
    }
  }
  // vector<vector<vector<vector<vector<int>>>>> dis(n + 1,
  // vector<vector<vector<vector<int>>>> (m + 1, 
  // vector<vector<vector<int>>> (7, 
  // vector<vector<int>> (7, 
  // vector<int> (7, INT_MAX)))));

  auto check = [&](int x, int y) -> bool {
    return x >= 1 and x <= n and y >= 1 and y <= m;
  };

  int ans = INT_MAX;
  queue<array<int, 5>> q;
  dis[sx][sy][c1][c2][c3] = 0;
  q.push({sx, sy, c1, c2, c3});
  while(!q.empty()) {
    auto [SX, SY, U, F, R] = q.front(); q.pop();
    if (SX == tx && SY == ty && opp[U] == ct) ans = min(dis[tx][ty][U][F][R], ans);
    // cout << "SX: " << SX << " " << " SY: " << SY << " U: " << U << " F: " << F << " R: " << R << endl;  
    for (int dir = 1; dir <= 4; dir ++) {
      int TX = SX + cord[dir][0];
      int TY = SY + cord[dir][1];
      if (!check(TX, TY)) continue;
      auto res = roll(U, F, R, dir);
      int nw = dis[SX][SY][U][F][R] + 1;
      if (dis[SX][SY][U][F][R] + 1 < dis[TX][TY][res[0]][res[1]][res[2]]) {
        dis[TX][TY][res[0]][res[1]][res[2]] = nw;
        q.push({TX, TY, res[0], res[1], res[2]});
      }
    }
  }
  
  cout << (ans == INT_MAX ? -1 : ans) << endl; 
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

