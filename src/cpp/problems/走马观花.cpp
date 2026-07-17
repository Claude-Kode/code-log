// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

vector<vector<int>> masks(7);
vector<vector<vector<int>>> dp((1 << 6),
vector<vector<int>> (6, 
vector<int>(1e4 + 1, INT_MAX)));

vector<vector<vector<vector<int>>>> now(7,
vector<vector<vector<int>>>((1 << 6),
vector<vector<int>>(6)));

void solve() { 
  int n, m, k; cin >> n >> m >> k;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) cin >> vec[i];

  vector<vector<array<int, 2>>> adj(n + 1);
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int ans = INT_MAX;
  mt19937 rng(time(0));
  int lim;
  if (k <= 3) lim = 100;
  else if (k == 4) lim = 200;
  else if (k == 5) lim = 300;
  else lim = 350;

  for(int iteration = 1; iteration <= lim; iteration ++) {
    vector<int> color(n + 1);
    for(int i = 1; i <= n; i ++) color[i] = rng() % k;

    int mx_msk = (1 << k) - 1;

    for(int i = 1; i <= n; i ++) {
      int msk = 1 << color[i];
      int mod = vec[i] % k;
      if (dp[msk][mod][i] == INT_MAX) now[__builtin_popcount(msk)][msk][mod].push_back(i);
      dp[msk][mod][i] = 0;
    }

    for(int cnt = 1; cnt < k; cnt ++) {
      for(int u_msk : masks[cnt]) { if (u_msk > mx_msk) break;
        for(int u_mod = 0; u_mod < k; u_mod ++) {
          for(int u : now[cnt][u_msk][u_mod]) if (dp[u_msk][u_mod][u] != INT_MAX) { 
            for(const auto &[v, w] : adj[u]) if (!(u_msk >> color[v] & 1)) {
              int v_msk = u_msk | (1 << color[v]);
              int v_mod = (u_mod + vec[v]) % k;
              if (dp[v_msk][v_mod][v] == INT_MAX) now[cnt + 1][v_msk][v_mod].push_back(v);
              dp[v_msk][v_mod][v] = min(dp[v_msk][v_mod][v], dp[u_msk][u_mod][u] + w);
            }
          }
        }
      }

    }

    for(int cnt = 1; cnt <= k; cnt ++) {
      for(int msk = 1; msk <= mx_msk; msk ++) {
        for(int mod = 0; mod < k; mod ++) {
          for(int u : now[cnt][msk][mod]) {
            if (mod == 0) ans = min(ans, dp[msk][0][u]);  
            dp[msk][mod][u] = INT_MAX;
          }
          now[cnt][msk][mod].clear();
        }
      }
    }

    // for(int msk = 1; msk <= mx_msk; msk ++) {
    //   for(int i = 1; i <= n; i ++) {
    //     ans = min(ans, dp[msk][0][i]);
    //   }
    // }



    // for(int cnt = 1; cnt <= k; cnt ++) {
    //   for(int msk = 1; msk <= mx_msk; msk ++) {
    //     if (__builtin_popcount(msk) != cnt) continue;
    //     for(int j = 0; j < k; j ++) {
    //       for(int u : now[cnt][msk][j]) {
    //         dp[msk][j][u] = INT_MAX;
    //       }
    //     }
    //   }
    // }

    // for(int i = 1; i <= k; i ++) {
    //   for(int msk = 1; msk <= mx_msk; msk ++) {
    //     if (__builtin_popcount(msk) > i) break;
    //     for(int j = 0; j < k; j ++) {
    //       now[i][msk][j].clear();
    //     }
    //   }
    // }
  }

  std::cout << (ans == INT_MAX ? -1 : ans) << endl; 

}

/*

不是 合着你这就是 瞎几把染色 然后看概率对吧 
我先来梳理一下这个整体的一个问题
首先得是题目要求的是简单路径 所以说我们不能走出一个环 
所以我们可能要标记一个路径 但是 n 太大了 显然要转台压缩
显然的我们可以得到一个结论, 就是最优路径的长度不能超过 k 的大小
这个是很显然的, 所以我们只需要记录路径的长度
吗
这样可能也是不对的, 因为环的长度也可能是小于 k 的啊
那么会不会存在一个环的大小小于 k 而且能得到比正解更有的结果呢
非常显然了 这样是可以的
所以我们考虑有一个实现方式, 对于每一条路径我们携带一个 unorderd_map 这样显然是可以的但是时间复杂度会爆炸
由于 k 很小 我们考虑状态压缩
2 ^ k * k * n ,这样的空间复杂度也是可以接受的
时间复杂度上由于装压的特性也是可以接受的
那么问题来了,  n 有 1e4 , 我们如何做到让每一条长度为 k 的路径上的都不一样 还能用很小的范围俩表示胡一个节点呢
很显然的 我们可以分类 但是这样的分类 我真的是想不到办法
所以最后我们考虑一个随机染色(其实就是给节点赋予属性分类即可)
然后这个染色很显然是有概率不能满足我们的条件的
这样下去应该怎么处理呢 我们应该多尝试几次 (相当于枚举了)
然后计算一下概率 多算几次
感觉大体的思路是这样的


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

  for(int i = 1; i <= (1 << 6) - 1; i ++) {
    int cnt = __builtin_popcount(i);
    masks[cnt].push_back(i);
  }

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}

