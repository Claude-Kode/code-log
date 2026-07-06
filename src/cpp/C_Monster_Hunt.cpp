// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif

// void solve() {
//   int n, m, q;
//   cin >> n >> m >> q;
//   vector<vector<int>> son(n + 1);
//   for (int i = 2; i <= n; i ++) {
//     int fa;
//     cin >> fa;
//     son[fa].push_back(i);
//   }

//   std::vector<int> sign;
//   for (int i = 1; i <= m; i ++) {
//     int tmp;
//     cin >> tmp;
//     sign.push_back(tmp);
//   }

//   auto add = [&](int x) -> void {

//   };

//   auto remo = [&](int x) -> void {

//   };

//   while (q --) {
//     int op, x;
//     cin >> op >> x;
//     if (op == 1) {

//     }

//     if (op == 2) {

//     }

//   }

// }

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);

//   int tt = 1, _ = 0;
//   // std::cin >> tt;
//   while (tt-- && ++_)
//     // std::cout << "TEST CASE : " << _ << endl,
//     solve();

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, root, mod;
vector<int> g[N];  // 邻接表
int w[N];          // 原树点权

// ---------- 树剖数组 ----------
int fa[N], dep[N], siz[N], son[N];
int top[N];          // 所在重链的链头
int dfn[N], rnk[N];  // dfn序，dfn到节点的映射
int nw[N];           // dfs序对应的点权
int timestamp;       // 时间戳

// ---------- 线段树 ----------
struct SegTree {
  int l, r;
  int sum, add;
} tr[N << 2];

// ---------- 第一次DFS ----------
// 计算fa, dep, siz, son（重儿子）
void dfs1(int u, int father, int depth) {
  fa[u] = father;
  dep[u] = depth;
  siz[u] = 1;

  for (int v : g[u]) {
    if (v == father) continue;

    dfs1(v, u, depth + 1);
    siz[u] += siz[v];

    // 更新重儿子（子树大小最大的儿子）
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}

// ---------- 第二次DFS ----------
// 计算top, dfn, rnk
void dfs2(int u, int t) {
  top[u] = t;
  dfn[u] = ++timestamp;
  rnk[timestamp] = u;
  nw[timestamp] = w[u] % mod;

  // 1. 先走重儿子（保证重链连续）
  if (son[u]) {
    dfs2(son[u], t);  // 重儿子继承当前链头
  }

  // 2. 再走轻儿子
  for (int v : g[u]) {
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);  // 轻儿子开启新链，自己是链头
  }
}

// ---------- 线段树操作 ----------
void pushup(int u) { tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod; }

void pushdown(int u) {
  if (tr[u].add) {
    int len1 = tr[u << 1].r - tr[u << 1].l + 1;
    int len2 = tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1;

    tr[u << 1].sum = (tr[u << 1].sum + 1LL * tr[u].add * len1) % mod;
    tr[u << 1 | 1].sum = (tr[u << 1 | 1].sum + 1LL * tr[u].add * len2) % mod;

    tr[u << 1].add = (tr[u << 1].add + tr[u].add) % mod;
    tr[u << 1 | 1].add = (tr[u << 1 | 1].add + tr[u].add) % mod;

    tr[u].add = 0;
  }
}

void build(int u, int l, int r) {
  tr[u] = {l, r, nw[l], 0};
  if (l == r) return;

  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void update(int u, int l, int r, int k) {
  if (l <= tr[u].l && tr[u].r <= r) {
    tr[u].sum = (tr[u].sum + 1LL * k * (tr[u].r - tr[u].l + 1)) % mod;
    tr[u].add = (tr[u].add + k) % mod;
    return;
  }

  pushdown(u);
  int mid = (tr[u].l + tr[u].r) >> 1;
  if (l <= mid) update(u << 1, l, r, k);
  if (r > mid) update(u << 1 | 1, l, r, k);
  pushup(u);
}

int query(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) {
    return tr[u].sum;
  }

  pushdown(u);
  int mid = (tr[u].l + tr[u].r) >> 1;
  int res = 0;
  if (l <= mid) res = (res + query(u << 1, l, r)) % mod;
  if (r > mid) res = (res + query(u << 1 | 1, l, r)) % mod;
  return res;
}

// ---------- 树剖操作 ----------

// 1. 更新路径 u->v
void update_path(int u, int v, int k) {
  k %= mod;

  // 当u和v不在同一条重链时
  while (top[u] != top[v]) {
    // 让u是深度更深的链
    if (dep[top[u]] < dep[top[v]]) swap(u, v);

    // 更新u所在重链的一段 [top[u], u]
    // dfn[top[u]] 到 dfn[u] 是连续的！
    update(1, dfn[top[u]], dfn[u], k);

    // u跳到上一条链
    u = fa[top[u]];
  }

  // 现在u和v在同一条重链上
  if (dep[u] > dep[v]) swap(u, v);
  update(1, dfn[u], dfn[v], k);
}

// 2. 查询路径 u->v
int query_path(int u, int v) {
  int res = 0;

  // 当u和v不在同一条重链时
  while (top[u] != top[v]) {
    // 让u是深度更深的链
    if (dep[top[u]] < dep[top[v]]) swap(u, v);

    // 查询u所在重链的一段
    res = (res + query(1, dfn[top[u]], dfn[u])) % mod;

    // u跳到上一条链
    u = fa[top[u]];
  }

  // 现在u和v在同一条重链上
  if (dep[u] > dep[v]) swap(u, v);
  res = (res + query(1, dfn[u], dfn[v])) % mod;
  return res;
}

// 3. 更新子树 u
void update_subtree(int u, int k) {
  k %= mod;
  // 子树在dfs序中是连续的: [dfn[u], dfn[u] + siz[u] - 1]
  update(1, dfn[u], dfn[u] + siz[u] - 1, k);
}

// 4. 查询子树 u
int query_subtree(int u) {
  // 子树在dfs序中是连续的
  return query(1, dfn[u], dfn[u] + siz[u] - 1);
}

// ---------- 主函数 ----------
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> root >> mod;

  // 读入点权
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }

  // 建图
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // 树剖预处理
  dfs1(root, 0, 1);  // 第一次DFS
  dfs2(root, root);  // 第二次DFS

  // 建线段树
  build(1, 1, n);

  // 处理操作
  while (m--) {
    int op, x, y, z;
    cin >> op;

    if (op == 1) {  // 路径加
      cin >> x >> y >> z;
      update_path(x, y, z);
    } else if (op == 2) {  // 路径查询
      cin >> x >> y;
      cout << query_path(x, y) << '\n';
    } else if (op == 3) {  // 子树加
      cin >> x >> z;
      update_subtree(x, z);
    } else if (op == 4) {  // 子树查询
      cin >> x;
      cout << query_subtree(x) << '\n';
    }
  }

  return 0;
}