// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() { int n, m; }

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

class DSU {
 public:
  vector<int> f, siz, dis;

  DSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
    dis.assign(n, 0);
  }

  int find(int x) {
    if (x != f[x]) {
      int ffx = find(f[x]);
      dis[x] += dis[f[x]];
      f[x] = ffx;
    }
    return f[x];
  }

  bool same(int x, int y) { 
    return find(x) == find(y); 
  }

  bool merge(int x, int y, int w = 0) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return false;
    // 边权 w 表示 x 到 y 的关系：dis[x] + w = dis[y] + (新边权) ...
    // 这里计算 fx 到 fy 的相对权值
    int nw = w + dis[y] - dis[x];
    siz[fy] += siz[fx];
    dis[fx] = nw;  // 将 fx 挂到 fy 上，设置 dis[fx] 满足关系
    f[fx] = fy;
    return true;
  }

  // 从 l 到 r 的距离
  int ask(int l, int r) {
    if (!same(l, r)) {
      return -1;
    } 
    return dis[l] - dis[r];
  }

  int size(int x) { 
    return siz[find(x)]; 
  }
};