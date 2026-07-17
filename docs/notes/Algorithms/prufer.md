1. 一个点在 Prufer 序列中出现的次数 = 它在原树中的度数 − 1

## Prufer 序列常见题型速查表

| 题型 | Prufer 序列的核心作用 | 关键思路 / 公式 |
|------|----------------------|----------------|
| Cayley 公式：n 个标号节点的无根树总数 | 序列长度为 `n-2`，每位可取 `1..n` | 总方案数 = $n^{n-2}$ |
| 指定度数序列的树计数 | 点 $i$ 在序列中出现次数 = $\deg(i)-1$ | 方案数 = $\dfrac{(n-2)!}{\prod (\deg(i)-1)!}$（合法时需 $\sum \deg(i)=2n-2$） |
| “某节点是叶子”的概率 | 叶子 ⇔ 该编号不在 Prufer 序列中 | 概率 = $\left(\dfrac{n-1}{n}\right)^{n-2}$ |
| 最大度 $\le k$ 的树计数 | 每个编号最多出现 $k-1$ 次 | 对长度 $n-2$ 的序列做“受限排列”计数 |
| 生成随机有标号树 | 随机生成合法 Prufer 序列 → 解码 | 均匀随机序列 ⇒ 均匀分布的有标号树 |
| 树的无损编码 / 压缩 | 树 ↔ 序列双向一一映射 | 编码长度 $n-2$，优于邻接表 |
| 最小 / 最大度生成树存在性 | 用度数约束反推 Prufer 中允许的出现次数 | 结合 Havel–Hakimi 判定 + Prufer 计数 |
| 矩阵树定理的特殊验证 | 小规模手算时用 Prufer 枚举所有树 | 枚举所有 Prufer 序列 → 验证行列式结果 |

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

// ====== 树 → Prufer ======
// 输入: n 个节点的树 (邻接表)
// 输出: 长度为 n-2 的 prufer 序列
vector<int> tree_to_prufer(int n, const vector<vector<int>>& g) {
  vector<int> deg(n + 1), prufer;
  for (int u = 1; u <= n; u++) deg[u] = (int)g[u].size();

  // 用优先队列找最小度=1的节点
  priority_queue<int, vector<int>, greater<int>> leaf;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 1) leaf.push(i);

  vector<bool> used(n + 1);

  for (int step = 1; step <= n - 2; step++) {
    int u = leaf.top(); leaf.pop();
    used[u] = true;

    // 找 u 的唯一邻接点 (未删除的)
    int parent = -1;
    for (int v : g[u])
      if (!used[v]) { parent = v; break; }

    prufer.push_back(parent);
    deg[parent]--;
    if (deg[parent] == 1) leaf.push(parent);
  }
  return prufer;
}

// ====== Prufer → 树 ======
// 输入: 长度为 n-2 的 prufer 序列
// 输出: 树的 n-1 条边
vector<pair<int, int>> prufer_to_tree(int n, const vector<int>& prufer) {
  vector<int> deg(n + 1, 1);
  for (int x : prufer) deg[x]++;

  priority_queue<int, vector<int>, greater<int>> leaf;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 1) leaf.push(i);

  vector<pair<int, int>> edges;
  for (int x : prufer) {
    int u = leaf.top(); leaf.pop();
    edges.push_back({u, x});
    deg[u]--;
    deg[x]--;
    if (deg[x] == 1) leaf.push(x);
  }

  // 最后两个度为 1 的节点连边
  int a = leaf.top(); leaf.pop();
  int b = leaf.top(); leaf.pop();
  edges.push_back({a, b});

  return edges;
}
```

通过度数还原一颗合法的树
```cpp
priority_queue<pair<int, int>> pq; 
for (int i = 1; i <= n; i++) {
  pq.emplace(d[i], i);
}

vector<pair<int, int>> edges;

while (!pq.empty()) {
  auto [udeg, u] = pq.top();
  pq.pop();

  if (udeg == 0) continue;

  vector<pair<int, int>> buf;
  for (int i = 0; i < udeg; i++) {
    auto [vdeg, v] = pq.top();
    pq.pop();
    edges.push_back({u, v});
    if (vdeg > 1) buf.push_back({vdeg - 1, v});
  }

  for (auto& p : buf) {
    pq.push(p);
  }
}
```
符合度数要求的树有多少棵树? 
待完成