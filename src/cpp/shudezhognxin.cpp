#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 50010;

int n;
vector<int> g[N];
int sz[N];     // 子树大小
long long dp[N];  // 距离和
int ans_node;  // 答案节点
long long min_sum;  // 最小距离和

// 第一次DFS：计算子树大小和初始dp[1]
void dfs1(int u, int fa) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == fa) continue             ;       
        dfs1(v, u);
        sz[u] += sz[v];
        dp[1] += sz[v];  // 节点1到v子树所有节点的距离 // 边u-v被使用了sz[v]次
    }
}

// 第二次DFS：换根计算所有dp[u]
void dfs2(int u, int fa) {
    // 更新答案
    if (dp[u] < min_sum || (dp[u] == min_sum && u < ans_node)) {
        min_sum = dp[u];
        ans_node = u;
    }
    
    for (int v : g[u]) {
        if (v == fa) continue;
        // 状态转移：从u换根到v
        dp[v] = dp[u] + (n - 2 * sz[v]);
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    // 读入树
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    // 初始化
    fill(sz, sz + n + 1, 0);
    fill(dp, dp + n + 1, 0);
    
    // 第一次DFS：以1为根
    dfs1(1, -1);
    
    // 第二次DFS：换根DP
    ans_node = 1;
    min_sum = dp[1];
    dfs2(1, -1);
    
    // 输出结果
    cout << ans_node << " " << min_sum << endl;
    
    return 0;
}