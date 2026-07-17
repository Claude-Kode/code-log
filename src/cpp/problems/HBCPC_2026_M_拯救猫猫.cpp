
// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

class RollbackDSU {
 public:
  struct His {
    int child;
    int par;
  };

  vector<int> fa, siz;
  vector<His> his;

 public:
  RollbackDSU(int n) {
    fa.assign(n, 0);
    siz.assign(n, 1);
    his.clear();
    iota(fa.begin(), fa.end(), 0LL);
  }

  int find(int u) {
    while (u != fa[u]) {
      u = fa[u];
    }
    return u;
  }

  bool same(int u, int v) { 
    return find(u) == find(v); 
  }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
      return false;
    }

    if (siz[u] < siz[v]) {
      swap(u, v);
    }

    fa[v] = u;
    siz[u] += siz[v];
    his.push_back({v, u});
    return true;
  }

  bool rollback() {
    if (his.empty()) {
      return false;
    }
    auto [v, u] = his.back();
    his.pop_back();
    fa[v] = v;
    siz[u] -= siz[v];
    return true;
  }
};

struct Dog {
  int dog_x, dog_y;
  int dog_dx, dog_dy;
};

int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void solve() {
  int n, m;
  cin >> n >> m;
  // dbug(n);
  // dbug(m);
  vector<vector<char>> g(n + 1, vector<char>(m + 1));
  vector<Dog> dogs;

  auto to = [&](int x, int y) -> int { return (x - 1) * m + y; };

  auto check = [&](int i, int j) -> bool {
    return i >= 1 and i <= n and j >= 1 and j <= m;
  };

  int sx = 0, sy = 0, tx = 0, ty = 0;
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      cin >> g[i][j];
      // cout << g[i][j] << " \n"[j == m];
      if (g[i][j] == 'S') {
        sx = i, sy = j;
        g[i][j] = '.';
      } else if (g[i][j] == 'E') {
        tx = i, ty = j;
        g[i][j] = '.';
      } else if (g[i][j] == 'U') {
        dogs.push_back({i, j, -1, 0});
      } else if (g[i][j] == 'D') {
        dogs.push_back({i, j, 1, 0});
      } else if (g[i][j] == 'L') {
        dogs.push_back({i, j, 0, -1});
      } else if (g[i][j] == 'R') {
        dogs.push_back({i, j, 0, 1});
      }
    }
  }

  for (const auto& [x, y, dx, dy] : dogs) {
    g[x][y] = '#';
  }

  assert(!dogs.empty());
  vector<vector<int>> cnt(n + 1, vector<int>(m + 1));
  for (const auto& [dog_x, dog_y, dog_dx, dog_dy] : dogs) {
    int cur_x = dog_x + dog_dx, cur_y = dog_y + dog_dy;
    while (check(cur_x, cur_y) and g[cur_x][cur_y] == '.') {
      cnt[cur_x][cur_y] ++;
      cur_x += dog_dx;
      cur_y += dog_dy;
    }
  }

  RollbackDSU dsu(n * m + 1);
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) { 
      // 空地且没有狗覆盖
      if (g[i][j] == '.' and cnt[i][j] == 0) {
        // cout << "normal: " << i << ' '<< j << "\n";
        for (const auto &[dx, dy] : dirs) {
          int nx = i + dx, ny = j + dy;
          if (check(nx, ny) and g[nx][ny] == '.' and cnt[nx][ny] == 0) {
            // cout << "with: " << nx << ' ' << ny << "\n";
            dsu.merge(to(i, j), to(nx, ny));
          }
        }
      }
    }
  }

  // dbug(sx);
  // dbug(sy);
  // dbug(tx);
  // dbug(ty);
  // dbug(g);
  // dbug(cnt);
  // for (int i = 1; i <= n; i ++) {
  //   for (int j = 1; j <= m; j ++) {
  //     if (g[i][j] == '#') cout << "N" << " ";
  //     else if (cnt[i][j]) cout << "D" << " ";
  //     else cout << cnt[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  if (dsu.same(to(sx, sy), to(tx, ty))) {
    assert(dogs.size());
    cout << dogs.front().dog_x << ' ' << dogs.front().dog_y << "\n";
    return;
  }

  dsu.his.clear();
  for (const auto &[dog_x, dog_y, dog_dx, dog_dy] : dogs) {
    // cout << "dog: " << dog_x << ' ' << dog_y << "\n";
    int cur_x = dog_x + dog_dx, 
        cur_y = dog_y + dog_dy;
    int pre_x = -1, 
        pre_y = -1;
    while (check(cur_x, cur_y)) {
      // 这一个是墙或者狗 视线应该停止
      if (g[cur_x][cur_y] == '#') break;
      // 说明和别的狗的视线有交叉 应该跳过
      if (cnt[cur_x][cur_y] != 1) {
        pre_x = -1;
        pre_y = -1;
        cur_x += dog_dx;
        cur_y += dog_dy;
        continue;
      }

      // cout << "from: " << cur_x << ' ' << cur_y << "\n";
      for (const auto &[dx, dy] : dirs) {
        int nx = cur_x + dx, ny = cur_y + dy;
        // 坐标合法 没有狗看着 也不是墙也不是狗
        if (check(nx, ny) and !cnt[nx][ny] and g[nx][ny] == '.') {
          // cout << "to: " << nx << ' ' << ny << "\n";

          dsu.merge(to(cur_x, cur_y), to(nx, ny));
        }
      } 

      if (check(pre_x, pre_y)) {
        dsu.merge(to(cur_x, cur_y), to(pre_x, pre_y));
      }

      pre_x = cur_x;
      pre_y = cur_y;
      cur_x += dog_dx;
      cur_y += dog_dy;
    }

    if (dsu.same(to(sx, sy), to(tx, ty))) {
      cout << dog_x << ' ' << dog_y << "\n";
      return;
    }

    while (dsu.his.size()) {
      dsu.rollback();
    }
  }

  cout << -1 << ' ' << -1 << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_) 
    // std::cout << "TEST CASE : " << _ << endl, 
    solve();

  return 0;
}

// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif

// using arr = array<int, 3>;

// int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// struct Dog {
//   int x;
//   int y;
//   int dx;
//   int dy;
//   int id;
// };

// void solve() {
//   int n, m;
//   cin >> n >> m;

//   int sx = -1, sy = -1, tx = -1, ty = -1;
//   vector<Dog> dogs; 
//   vector<vector<char>> g(n + 1, vector<char>(m + 1));
//   vector<vector<int>> sign(n + 1, vector<int>(m + 1));

//   int cnt_id = 0;
//   for (int i = 1; i <= n; i ++) {
//     for (int j = 1; j <= m; j ++) {
//       cin >> g[i][j];
//       if (g[i][j] == 'S') {
//         sx = i;
//         sy = j;
//       } else if (g[i][j] == 'E') {
//         tx = i;
//         ty = j;
//       } else if (g[i][j] == 'U') {
//         dogs.push_back({i, j, -1, 0, ++cnt_id});
//         g[i][j] = '#';
//         sign[i][j] = INT_MAX;
//       } else if (g[i][j] == 'D') {
//         dogs.push_back({i, j, 1, 0, ++cnt_id});
//         g[i][j] = '#';
//         sign[i][j] = INT_MAX;
//       } else if (g[i][j] == 'L') {
//         dogs.push_back({i, j, 0, -1, ++cnt_id});
//         g[i][j] = '#';
//         sign[i][j] = INT_MAX;
//       } else if (g[i][j] == 'R') {
//         dogs.push_back({i, j, 0, 1, ++cnt_id});
//         g[i][j] = '#';
//         sign[i][j] = INT_MAX;
//       }
//     }
//   }

//   auto check = [&](int i, int j) -> bool {
//     return i >= 1 and i <= n and j >= 1 and j <= m;
//   };

//   for (const auto &[dog_x, dog_y, dog_dx, dog_dy, id] : dogs) {
//     int cur_x = dog_x + dog_dx,
//         cur_y = dog_y + dog_dy;
//     // 一个点最多被两个点看 所以遇到有狗标记的点直接就改成 INT_MAX
//     while (check(cur_x, cur_y) and g[cur_x][cur_y] != '#') {
//       if (sign[cur_x][cur_y]) {
//         g[cur_x][cur_y] = '#';
//       }
//       sign[cur_x][cur_y] = id;
//       cur_x += dog_dx;
//       cur_y += dog_dy;
//     }
//   }

//   for (int i = 1; i <= n; i ++) {
//     for (int j = 1; j <= m; j ++) {
//       if (g[i][j] == '#') cout << g[i][j] << " ";
//       else cout << sign[i][j] << " ";
//     }
//     cout << "\n";
//   }

//   // arr: {x, y, id};
//   auto cmp = [&](const auto &a, const auto &b) -> bool {
//     return a[2] < b[2]; 
//   };  

//   priority_queue<arr, vector<arr>, decltype(cmp)> pq(cmp);
//   pq.push({sx, sy, 0});
//   // id - 1 可以找到对应使用的狗
//   unordered_map<int, unordered_map<int, unordered_map<int, int>>> ump;
//   int cnt = 0;
//   while (pq.size()) {
//     auto [x, y, id] = pq.top();
//     pq.pop();
//     // cout << "infor: " << x << ' ' << y << ' ' << id << "\n";
//     if (ump[x][y][id]) continue;
//     // if (++cnt == 10000) {
//     //   cout << "TLE\n";
//     //   return;
//     // } 
//     if (x == tx && y == ty) {
//       cout << dogs[max(1LL, id) - 1].x << dogs[max(1LL, id) - 1].y << "\n";
//       return;
//     }

//     for (const auto &[dx, dy] : dirs) {
//       int nx = x + dx, ny = y + dy;
//       if (!check(nx, ny)) continue;
//       if (g[nx][ny] == '#') continue;

//       // 接下来的只有空地 和被狗覆盖的空地 而且是单只狗覆盖的场地
//       if (id == 0) {
//         pq.push({nx, ny, sign[nx][ny]});
//       } else {
//         if (sign[nx][ny] == 0) {
//           ump[nx][ny][id] = 1;
//           pq.push({nx, ny, id});
//         } else if (sign[nx][ny] == id) {
//           ump[nx][ny][id] = 1;
//           pq.push({nx, ny, id});
//         }
//       }
//     } 
//   }

//   cout << -1 << ' ' << -1 << "\n";
// }   

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);

//   int tt = 1, _ = 0;
//   std::cin >> tt;
//   while (tt-- && ++_)
//     // std::cout << "TEST CASE : " << _ << endl,
//     solve();

//   return 0;
// }
