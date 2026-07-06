// // @Author : GoryK  
// #include <bits/stdc++.h>
// using namespace std;

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif 

// #define int int64_t
// #define endl "\n"

// using i64 = long long;
// using i128 = __int128;

// using u32 = unsigned; 
// using u64 = unsigned long long;
// using u128 = unsigned __int128;

// const int mod = 1e9 + 7; 
// const int N = 2e5 + 10;

// void solve() { 
//   int n; cin >> n; 
//   vector<int> vec(1);
//   for(int i = 1; i <= n; i ++) {
//     int temp; cin >> temp;
//     if (temp) vec.push_back(temp);
//   }

//   n = vec.size() - 1;
//   if (n >= 120) {cout << 3 << endl; return;}

//   vector<vector<int>> g(n + 1, vector<int>(n + 1));
//   for(int i = 1; i < n; i ++) {
//     for(int j = i + 1; j <= n; j ++) {
//       if (vec[i] & vec[j]) {
//         g[i][j] = g[j][i] = 1;
//       }
//     }
//   }

//   auto bfs = [&](int s) -> int {
//     vector<int> p(n + 1, -1), dis(n + 1, INT_MAX);
//     queue<int> q; q.push(s); dis[s] = 0;
//     while(!q.empty()) {
//       int u = q.front(); q.pop();
//       for(int v = 1; v <= n; v ++) if (g[u][v] && v != p[u]) {
//         if (dis[v] == INT_MAX) dis[v] = dis[u] + 1;
//         else return dis[u] + dis[v] + 1;
//         q.push(v); p[v] = u;
//       }
//     }

//     return INT_MAX;
//   };

//   int ans = INT_MAX;
//   for(int i = 1; i <= n; i ++) {
//     ans = min(ans, bfs(i));
//   }

//   cout << (ans == INT_MAX ? -1 : ans) << endl;
// }

// /*
// 这个题饭局很有意思 
// 要么是公式变形 
// 要么是问题转化
// 感觉稚嫩用着两种方法来写
// 或者来说 我们可以这样来进行尝试呢 首先我们去二分环的长度 
// 这个可以用二分

// 或许我们可以从正难则反的角度来考虑这道题

// 可不可以证明 环的最大程度 不超过 64 应该是可以的

// 我们从每个点开始进行搜索 对于我们搜索过但是不能成环的点 我们直接进行一个并查集的合并? 

// 或者说能不能用并查集来找环呢 ? 
// 这个只能支持一个 

// 一个数至少有两个 1 才可以
// */

// signed main() {
  
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);

//   // cout << fixed << setprecision(6);

//   // int tt , CNT = 0; cin >> tt; 
//   // while(tt -- && ++CNT) 
//     // cout << "TEST CASE : " << CNT << endl,
//     solve();
  
  
//   return 0;
// }

