// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() { 
  int n, r; cin >> n >> r;
  vector<array<int, 2>> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i][0] >> vec[i][1];
  }

  int w = 2 * r, h = (int)ceil(1.0 * sqrt(3) * r), H = 2 * h;
  while (true) {
    int dx = rng() % w;
    int dy = rng() % H;

    auto check = [&](int x, int y, int cx, int cy) -> bool {
      int a = (x - cx) * (x - cx), b = (y - cy) * (y - cy);
      return a + b <= r * r;
    };  

    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
      int tx = vec[i][0] - dx;
      int ty = vec[i][1] - dy;

      // (r, 0) (0, h) (2 * r, h), (r, 2 * h)
      int map_x = (tx % w + w) % w;
      int map_y = (ty % H + H) % H;
      cnt += (
        check(map_x, map_y, r, 0) or
        check(map_x, map_y, 0, h) or
        check(map_x, map_y, w, h) or
        check(map_x, map_y, r, H)
      );
    }

    if (100 * cnt < 89 * n) continue; 

    set<array<int, 2>> ans;
      for(int i = 1; i <= n; i ++) {
      int tx = vec[i][0] - dx;
      int ty = vec[i][1] - dy;

      // (r, 0) (0, dy) (r, dy), (2 * r, dy)
      int map_x = (tx % w + w) % w;
      int map_y = (ty % H + H) % H;
      int cx = -1, cy = -1;
      if (check(map_x, map_y, r, 0)) cx = r, cy = 0;
      else if (check(map_x, map_y, 0, h)) cx = 0, cy = h;
      else if (check(map_x, map_y, r, H)) cx = r, cy = H;
      else if (check(map_x, map_y, w, h)) cx = w, cy = h; 

      if (cx != -1) ans.insert({vec[i][0] - map_x + cx, vec[i][1] - map_y + cy});
    }

    cout << ans.size() << endl;
    for(const auto&[x, y] : ans) {
      cout << x << ' ' << y << endl; 
    }
    // SB 
    return;
  }
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



// // @Author : GoryK
// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")
// #include <bits/stdc++.h>
// using namespace std;

// #define int int64_t
// #define endl "\n"

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// void solve() { 
//   int n, r; 
//   cin >> n >> r;
//   vector<int> x(n), y(n);
//   for (int i = 0; i < n; i++) {
//     cin >> x[i] >> y[i];
//   }

//   int dy = ceil(1.0 * sqrt(3) * r);

//   const int a = 2 * r;
//   const int b = dy;

//   auto check = [&](int dx, int dy, int cx, int cy) -> bool {
//     int nx = dx - cx, ny = dy - cy;
//     return nx * nx + ny * ny <= r * r;
//   };

//   while (true) {
//     // 坐标轴的 x 偏移量
//     int ddx = rng() % (2 * r);
//     // 坐标轴的 y 偏移量
//     int ddy = rng() % (2 * dy);
    
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//       int tx = x[i] - ddx;
//       int ty = y[i] - ddy;
//       int gx = ((tx % (2 * r)) + (2 * r)) % (2 * r);
//       int gy = ((ty % (2 * dy)) + (2 * dy)) % (2 * dy);
      
//       if (check(gx, gy, r, 0)) cnt ++;
//       else if (check(gx, gy, 0, dy)) cnt ++;
//       else if (check(gx, gy, 2 * r, dy)) cnt ++;
//       else if (check(gx, gy, r, 2 * dy)) cnt ++;
//     }
    
//     if (cnt * 100 < n * 89) continue;
    
//     set<array<int, 2>> ans;
//     for (int i = 0; i < n; i++) {
//       int tx = x[i] - ddx;
//       int ty = y[i] - ddy;
//       int gx = ((tx % (2 * r)) + (2 * r)) % (2 * r);
//       int gy = ((ty % (2 * dy)) + (2 * dy)) % (2 * dy);
      
//       int cx = -1, cy = -1;
//       if (check(gx, gy, r, 0)) cx = r, cy = 0; 
//       else if (check(gx, gy, 0, dy)) cx = 0, cy = dy;
//       else if (check(gx, gy, 2 * r, dy)) cx = 2 * r, cy = dy;
//       else if (check(gx, gy, r, 2 * dy)) cx = r, cy = 2 * dy;
      
//       if (cx != -1) {
//         int real_cx = x[i] - gx + cx;
//         int real_cy = y[i] - gy + cy;
//         ans.insert({real_cx, real_cy});
//       }
//     }
    
//     std::cout << ans.size() << endl;
//     for (auto [cx, cy] : ans) {
//       std::cout << cx << " " << cy << endl;
//     }
//     return;
//   }
// }

// /*
// 很显然的 按照一个极尽可能近似等边三角形的排列是最优的
// 我们直接设定好一整张这种网格
// 然后 我们可以假设这些网格是可以微调的 

// 然后我们就可以 枚举偏移量
// 对于整张无限的网格来说 偏移量是有意义的当且仅当
// dx >= 0 && dx <= 单元 x
// dy >= 0 && dy <= 单元 y

// 对于一个偏移的量 我们要写一个 check 来验证每一个点是否在这个偏移量的周围的网格内部()
// 具体的意义就是根据偏移量 算出这个点偏移后的坐标
// 然后把他映射到一个单位的网格里面去验证即可
// */

// signed main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   solve();
//   return 0;
// }