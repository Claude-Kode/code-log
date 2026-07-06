// // @Author : GoryK
// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")
// #include <bits/stdc++.h>
// using namespace std;

// #define int int_fast64_t
// #define endl '\n'

// const int mod = 1e9 + 7; 
// const int N = 2e5 + 10;

// int n; 
// vector<vector<int>> fa, adj; vector<int> dep;

// inline void dfs(int u, int f) {
//   fa[0][u] = f; dep[u] = dep[f] + 1;
//   for(const int &v : adj[u]) if (v != f) dfs(v, u);
// }

// inline void init() {
//   int lim = __lg(n);
//   for(int i = 1; i <= lim; i ++) {
//     for(int j = 1; j <= n; j ++) {
//       fa[i][j] = fa[i - 1][fa[i - 1][j]];
//     }
//   }
// }

// inline int lca(int u, int v) {
//   // 深度越小的越是爹
//   if (dep[u] < dep[v]) swap(u, v);
//   // 首先是上调到同一个深度
//   int lim = __lg(n);
//   for (int i = lim; i >= 0; i --) {
//     if (dep[fa[i][u]] >= dep[v]) u = fa[i][u];
//   }
//   if (u == v) return u;
//   for (int i = lim; i >= 0; i --) {
//     if (fa[i][u] != fa[i][v]) {
//       u = fa[i][u];
//       v = fa[i][v];
//     }
//   }
//   return fa[0][u];
// }

// void solve() { 

//   int m, r; cin >> n >> m >> r;
//   adj.assign(n + 1, {});
//   fa.assign(__lg(n) + 1, vector<int>(n + 1, 0));
//   dep.assign(n + 1, 0);

//   for(int i = 1; i < n; i ++) {
//     int u, v; cin >> u >> v;
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//   }

//   dfs(r, 0);
//   init();

//   while (m --) {
//     int u, v; cin >> u >> v;
//     cout << lca(u, v) << "\n";
//   }

// }

// /*
// 最近公共祖先的精髓 : 我们把 jump 之后的高度 和 LCA 的高度变成一个二进制数字
// 每次上跳到非LCA 的最大二次幂 相当于从高位到低位消掉这个长度的 1 
// 而且注意是从高位到低位 这个是一定是单调递减的 是具有单调性的 lg级别的次数 for 循环是一定可以通过的
// 所以最多需要 logn 次上跳

// 注意 我说的是中间 的长度 , 也就是 u - v 实际上从 u 跳到 v 是 u - v + 1 
// 所以消掉长度进制上所有的 1 之后就就是最后节点的父亲

// fa[x]][k] 表示 x 节点上跳 2 ^ k 次的父亲节点是多少
// dep数组存每个节点的深度
// 跟 st 表一样 lg 作为第一维 是更好的选择

// */

// signed main() {
  
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
  
//   #ifdef GK
//     freopen("INPUT.txt", "r", stdin);
//     freopen("OUTPUT.txt", "w", stdout);
//   #endif 

//   // cout << fixed << setprecision(6);

//   // int tt , CNT = 0; cin >> tt;
//   // while(tt -- && ++CNT) 
//     // cout << "TEST CASE : " << CNT << endl,
//     solve();
  
//   return 0;
// }

// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n, m, r;
vector<vector<int>> adj, fa;
vector<int> dep;

void dfs(int u, int f) {
  fa[0][u] = f;
  dep[u] = dep[f] + 1;
  for(const int &v : adj[u]) if (v != f) dfs(v, u);
}

void init(){
  for(int i = 1; i <= __lg(n); i ++) {
    for(int j = 1; j <= n; j ++) {
      fa[i][j] = fa[i - 1][fa[i - 1][j]];
    }
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int lim = __lg(n);
  for(int i = lim; i >= 0; i --) if (dep[fa[i][u]] >= dep[v]) {
    u = fa[i][u];
  }
  if (u == v) return u;
  for(int i = lim; i >= 0; i --) if (fa[i][u] != fa[i][v]) {
    u = fa[i][u]; v = fa[i][v];
  }
  return fa[0][u];
}

void solve() { 

  cin >> n >> m >> r;
  adj.assign(n + 1, {});
  fa.assign(__lg(n) + 1, vector<int>(n + 1, 0));
  dep.assign(n + 1, 0);

  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(r, 0); init();
  for(int i = 1; i <= m; i ++) {
    int u, v; cin >> u >> v;
    cout << lca(u, v) << endl;
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