// Kruskal 重构树（Kruskal Reconstruction Tree）
// 是一种基于 Kruskal 最小/最大生成树算法构建的特殊二叉树数据结构。
//
// 它的核心思想是把原图的“边权”转化为新树的“点权”，从而把图上复杂的路径极值、连通性问题，
// 转化为树上简单的 LCA（最近公共祖先）​ 或 子树查询​问题
#include <bits/stdc++.h> 
using namespace std;

#define int long long
#define ll long long

int dirs[4][2] = {
  {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  const int N = n * m;
  auto f = [&](int i, int j) -> int {
    return (i - 1) * m + j;
  };
  
  vector<int> fa(N + 1, 0), sz(N + 1, 0), val(N + 1, 0), mx(N + 1);
  auto find = [&](auto&& sef, int x) -> int {
    if (x != fa[x]) {
      sef(sef, fa[x]);
      mx[x] = max(mx[x], mx[fa[x]]); 
      fa[x] = fa[fa[x]];       
    }
    return fa[x];
  };

  auto work = [&](int i, int w) -> void {
    fa[i] = i;
    val[i] = w;
    sz[i] = 1;
  };

  auto chk = [&](int i) -> bool {
    return i > 0 and i <= n * m and fa[i];
  };

  // mx[u] 实际上是一种带权并查集, 他表示 从 u 一直跳联通块内部的递增节点

  int l = 0;
  for (int i = 1; i <= q; i++) {
    int op, x, y; cin >> op >> x >> y; x ^= l, y ^= l; 
    int u = f(x, y);
    if (op == 1) {
      int w; cin >> w; 
      work(u, w);

      for (auto& [dx, dy] : dirs) { int v = f(x + dx, y + dy); if (!chk(v)) continue;
        v = find(find, v);
        if (v != u) {
          fa[v] = u;
          mx[v] = w - sz[v];
          sz[u] += sz[v];
        }
      }

      cout << (l = sz[u] - 1) << "\n";
    } else {
      find(find, u);
      cout << (l = max(0LL, mx[u] - val[u] + 1)) << "\n";
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }

  return 0;
}
