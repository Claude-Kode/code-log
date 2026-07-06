// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;


    
void solve() { 



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



#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100005; // 最大节点数
const int LOG = 17;      // 2^LOG > MAXN， 通常取17或20足够

// fa 数组
vector<int> tree[MAXN];  // 邻接表存树
int depth[MAXN];         // 每个节点的深度
int parent[MAXN][LOG];   // parent[u][k] 表示节点u向上跳2^k步到达的祖先

// DFS预处理：计算每个节点的深度和直接父节点（即2^0祖先）
void dfs(int u, int p) {
    parent[u][0] = p; // 直接父节点
    depth[u] = (p == -1) ? 0 : depth[p] + 1;

    // 计算向上跳2^k的祖先
    for (int k = 1; k < LOG; k++) {
        if (parent[u][k-1] != -1) {
            // 核心递推：u向上跳2^k步 = 先跳2^(k-1)步，再跳2^(k-1)步
            parent[u][k] = parent[parent[u][k-1]][k-1];
        } else {
            parent[u][k] = -1; // 已经跳到根节点之上
        }
    }

    // 递归处理子节点
    for (int v : tree[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

// 将节点u向上跳step步
int jump(int u, int step) {
    for (int k = LOG - 1; k >= 0; k--) {
        // 利用step的二进制表示：如果step的第k位是1，就跳2^k步
        if (step & (1 << k)) {
            u = parent[u][k];
            if (u == -1) break; // 已超出根节点
        }
    }
    return u;
}

// 查询LCA
int lca(int u, int v) {
    // 1. 将u和v调整到同一深度
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    u = jump(u, diff); // u向上跳diff步，与v同深

    // 如果此时就是同一个节点，直接返回
    if (u == v) return u;

    // 2. 二分查找LCA：从最大步长开始尝试
    for (int k = LOG - 1; k >= 0; k--) {
        // 如果跳2^k步后，祖先不同，说明LCA还在上方，可以安全跳上去
        if (parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    // 最后，u和v的父节点就是LCA
    return parent[u][0];
}

int main() {
    int n; // 节点数
    cin >> n;

    // 建树 (n-1条边)
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 初始化，假设根节点为1
    memset(parent, -1, sizeof(parent));
    dfs(1, -1); // 从根节点1开始DFS预处理

    // 查询示例
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << "LCA of " << a << " and " << b << " is: " << lca(a, b) << endl;
    }

    return 0;
}