s# 最短路算法综述
关于最短路问题 本质上是一个求解最优解的问题
这个问题显然是不能贪心的 为什么呢 如果能贪心我还 bb 什么你自己写不得了
有非常非常多的算法可以求解最短路问题 但是我个人认为 本质上都是 ```DP```

## 对于单源最短路问题 
我们总是可以在很多算法中发现一个操作 -- relax 操作(松弛)
有什么对边进行松弛的 有对点进行松弛的 本质上都是一个公式 -
```dis[v] = min(dis[u] + w, dis[v])```
很容易发现啊 这就是是一个状态转移方程啊 而且是线性的(即状态的转移是有固定方向的)
这就是一个线性 dp 啊

## 下面来介绍单元最短路的三个算法 : 

```
下面会经常用到的
struct edge {
  int v; // 边的终点
  int w; // 边的边权
  bool operator< (edge other) const {
    return w > other.w;
  }
};
vector<vector<edge>> adj(n + 1); // adjcent-list
priority_queue<edge> pq; // dijkstra 的最小堆
```
另 : 前置知识 BFS, 线性 dp , 区间 dp


### 1. Bellman-Ford

**概述** : 每次遍历所有的边 看看能不能更新某一个点到源点的距离 重复这样的操作 n - 1 次

下面直接上具体的代码 : 
```
struct edge {int u; int v; int w;};
int bellman_ford(int s, int t, vector<edge>& edges) {
  vector<int> dis(n + 1, INT_MAX); dis[s] = 0;
  for(int i = 1; i <= n - 1; i ++) {
    bool update = false;
    for(const auot &[u, v, w] : edges) if (dis[u] + w < dis[v] && dis[u] != INT_MAX) {
      update = true, dis[v] = dis[u] + w;
    }
    if (!update)  break;
  }
  return dis[t];
}


```
其实来说 他的本质上就是一个 BFS + dp
我们来看看 你在脑子里面想象一下 是不是这么回事
开始的图的节点都是灰色的 只有当被 bfs 枚举到的时候才能被点亮
我们可以任意画一张图来重复这个 n - 1 次的循环 你就会发现 他本质上跟 bfs 的点亮顺序竟然是 tm 一模一样的 !
本质上就是在图上进行 BFS , BFS 本身就是一种图的遍历方式 , 在 dp 的环节中充当一个枚举的角色

那么有人要问了为啥这个傻der不用 BFS呢 我告诉你
他发明这个算法的时候 , BFS 还没被发明呢(难评)

那么为什么要循环 n - 1 次就非常的简单了
一共就 tm n个节点了 , 就算是 BFS 最多 n-1 次这条最长的路也就处理完事了
所以只需要 n - 1 次就可以了
bbbbbbbbbbbbbbbut !
如果出现环呢 ? 是不是路径的长度就可以无限延伸了 ? 要是无向图呢 , 每两个节点之间也是一个环
没必要啊 我们求的是最短路啊喂 , 你增加变边的数量路径是一定会变长的
dis[u] + w < dis[v] 这个 dis[v] 在 n -1 以后的枚举中一定不会被更新的 
所以 n - 1次是无懈可击的

吗 ? 

如果我围绕这个环 , 每次走一圈下来 我的花费都会减少呢 ? 
比如 (u, v, w)
1 2 -1
2 3 -1
3 4 -1
4 1 0

我们可以观察到 这是一个负环 所以还能引申出来一个结论 , 
如果在第 n 次 , 还能出现 dis[v] 被更新的情况 , 一定会存在一个负环, 所以我们可以改写一下这个函数

```
struct edge {int u; int v; int w;};
int bellman_ford(int s, int t, vector<edge>& edges) {
  bool negativeCycle = false;
  vector<int> dis(n + 1, INT_MAX); dis[s] = 0;
  for(int i = 1; i <= n; i ++) {
    bool update = false;
    for(const auot &[u, v, w] : edges) if (dis[u] + w < dis[v] && dis[u] != INT_MAX) {
      if (i == n) { negetiveCycle = true; break ; }
      update = true, dis[v] = dis[u] + w;
    }
    if (!update)  break;
  }
  if (negativeCycle) return -1;
  return dis[t];
}
```
这样返回值是 -1 的时候就代表图里面有一个负环

我们再来看这个地方
```
if (!update)  break;
```
这个就是个小优化 , 我们来深入解析一下 :
你发现没有 Bellman-Ford 就是一个 dp 啊
我们设 dp[k][u] 为 , 从起点到 u 最多经过 k 条路中的最小代价
很容易得到状态转移方程 : 
```
dp[k][v] = min(dp[k][v], dp[k - 1][u] + w)
u 为所有跟 v 有建边的节点
```
这样也可以解释循环 n - 1 次的原因 因为两个点的最长距离就是 n - 1 条边了
我们再来看这个优化

当 dp[k][v] 无法被更新的时候 dp[k + 1][v] 还能被更新吗 ? 
聪明的你已经懂了吧 OVO


### 2. SPFA

这个其实就是 bellman-ford 的优化版本
就是把 n - 1 次的循环改成了 BFS 枚举
所以非常简单啊 

```



void spfa(int s, int t, vector<vector<edge>>& adj) {
  vector<int> inque(n + 1, 0), dis(n + 1, INT_MAX), cnt(n + 1, 0);
  dis[s] = 0;
  queue<int> q;  // 只需要存储节点编号
  q.push(s);
  inque[s] = 1;
  cnt[s] = 1;  // 起始节点入队次数+1
  while (!q.empty()) {
    int u = q.front(); q.pop();
    inque[u] = 0;
    for (const auto &[v, ww] : adj[u]) if (dis[u] + ww < dis[v]) { // 只要可以松弛就更新
      dis[v] = dis[u] + ww;
      if (!inque[v]) {         // 不在队列中才入队
        inque[v] = 1;
        cnt[v]++;
        if (cnt[v] >= n) {   // 检测到负环，立即返回
          return -1;
        }
        q.push(v);
      }
    }
  }

  return dis[t];
}
```
我们可以注意到一个细节 首先是朴素的 BFS 一般会有一个 vis 数组 这样是为了避免重复访问
但是 spfa 可能会需要一个节点被多次更新 所以取而代之的是一个 inque 数组

当 inque[v] 是 1 的时候只会影响这个节点入不入队
因为就算出队了 我们用的也是 dis 的值 
我们假设一个节点 k 被更新了 我们塞进队列里面 , 这个 k 出来之前又有一个点可以到达 k , 而且比前面那个 k 入队的时候的 dis[k]更小
你觉得有必要入队吗 ,没必要啊 你更新的是 dis[k] 啊 , 队列是用来枚举用的

枚举只要保证不漏就可以啊

### 3. Dijkstra 

啥都不说了 直接上代码 
这个我懒得写了 本质上就是按照到起点距离从小到大枚举节点的写法 思考明白这个就很简单了

```
int dijkstra (int s, int t, vector<vector<edge>>& adj, vector<int>& vis, vector<int>& dis) {
  priority_queue<edge> pq; pq.push({s, 0}); dis[s] = 0;
  while (!pq.empty()) {
    auto [u, w] = pq.top(); pq.pop();
    if (u == t) return w;
    if (vis[u]) continue; vis[u] = 1;
    for(const auto &[v, ww] : adj[u]) if (dis[v] > w + ww) {
       dis[v] = w + ww, pq.push({v, dis[v]});
    }
  }
  return -1; 
}
```

## 对于多元最短路问题

### 4. Floyd(多元最短路问题)

这个 Floyd 其实不能说是算法了 他真的就是一个 区间 dp
很简答啊
比如说我给你个图
```
1 -- 2 -- 3 -- 4 -- 5
```
我们 1 - 5 的最短路径可以从哪里转过来
1 - 2 + 3 - 5
1 - 3 + 4 - 5
所以 dp[i][j] 设为从 i 到 j 的路径最小值
很容易就能想到一个状态转移方程 : 
```
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
```

于是就有一个代码
```
vector<vector<int>> floyd(int n, const vector<tuple<int, int, int>>& edges) {
  vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX / 2));
  
  // 对角线为0
  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }
  
  // 填充边
  for (const auto& [u, v, w] : edges) {
    dist[u][v] = min(dist[u][v], w);  // 处理重边
  }
  
  // Floyd 核心
  for (int k = 1; k <= n; k++) {    
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  
  return dist;
}
```