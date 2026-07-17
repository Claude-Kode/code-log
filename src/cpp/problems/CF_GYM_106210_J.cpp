// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <climits>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque> 
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int , int , int>
// #define ull unsigned long long
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD1 = 998244353 ; 
// const int MOD2 = 1e9 + 7 ; 
// const int maxn = 1e9 ; 

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// struct infor { 
//     int id ; 
//     int val ; 
//     bool operator< ( const infor& other ) const {
//         return val < other.val ; 
//     }
// } ; 

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*

// 这道题 的意思是 定义我取下一个节点 , 然后不会有别的节点同时被取下 , 定义成合法的取下

// 我们要求每次取下的节点的珍贵值是最大的(在未取下的节点集合中)

// 什么情况不合法呢 , 很容易想到 , 取下的是叶子节点的父节点的时候 , 是不合法的

// 也就是被取下的节点的邻居有一个叶子节点

// 最朴素的做法是 , 每次遍历一遍图 , 然后寻找当前图中剩余的节点中 价值最大的那个

// 然后 BFS 他的邻居 , 查看入度是否是合法的 , 如果存在不合法的 , 即刻输出 NO 

// 这种朴素的想法是还原题目的想法来实现

// 这样做法的痛点是 , 每次需要遍历一遍图来寻找节点 , 第二 进行删除操作的时候 也要遍历一遍图

// 具体的实现方式就是维护一个未摘掉的集合 , 每次从当前最大值的集合中 暴力 DFS 所有节点

// 好消息 这个集合可以用桶来实现 , 每次都给了你上界

// 是否存在什么方法可以优化呢

// 正难则反 , 我们反着想呢 , 原题的题意是进行单个拆分 , 我们转换成单个组装

// 组装的起点自然是 0 , 每次组装的条件就是往上组装珍贵值最小的

// 那就是对价值从小到大进行遍历 , 然后只要最小的价值中出现了无法反组装上情况 即刻输出 NO

// 为什么会组装不上呢 , 因为题目有给定的边 , 如果给定了 a -> b 

// 但是出现了加装 B 的时候 a却不存在的情况 这个时候应该输出 no

// */
// // ========================== Main Function ====================================

// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     int n , m , k ; cin >> n >> m >> k ;

//     vector<int> removed( n + 1 ) ; 
//     vector<int> indegree( n + 1 ) ; 
//     vector<int> outdegree( n + 1 ) ; 
//     vector<vector<int>> indices( k + 1 ) ;
//     vector<vector<int>> adj( n + 1 ) ;
//     vector<vector<int>> fa( n + 1 ); 
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         int value ; cin >> value ; 
//         indices[value].push_back( i ) ; 
//     }
//     for ( int i = 1 ; i <= m ; i ++ ) {
//         int u , v ; cin >> u >> v ; 
//         adj[u].push_back( v ) ;
//         adj[v].push_back( u ) ;
//     }

//     queue<int> q ; 
//     q.push( 0 ) ; 
//     while( !q.empty() ) {
//         int u = q.front() ; q.pop() ; 
//         for ( auto &v : adj[u] ) {
//             indegree[u] ++ ; 
//             outdegree[v] ++ ; 
//             fa[v].push_back( u ) ;
//         }
//     }

//     // 有向边建立完成 , 然后挑入度是 0 的节点进行入队 , 用 pq 弹出价值最大的
//     // 弹出最大的以后判断这个点能否被合法的删掉
//     // 但是这样可以吗 , pq 只能弹出可以合法删掉的点中价值最大的 

//     priority_queue<infor> qq ; 
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         if ( !indegree[i] ) qq.emplace( i , indices[i] ) ; 
//     }

//     while ( !qq.empty() ) {
//         auto [u , val] = qq.top() ; qq.pop() ; 
//         for ( auto &v : fa[u] ) {

//             // 路径中肯定不能出现递增的情况
//             if ( indices[u] < indices[v] || outdegree[v] ) {
//                 cout << "NO" << endl ;
//                 return 0 ;  
//             }  

//             if ( !--indegree[v] ) {
//                 qq.emplace( v , indices[v] ) ; 
//             }

//         }
//     }

//     cout << "YES" << endl ; 

//     return 0 ;
// }

// // ========================== Question =========================================
// /*

// */

// signed main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
//     int n, m, k; cin >> n >> m >> k;
    
//     vector<int> value(n + 1);
//     vector<vector<int>> indices(k + 1);
//     vector<vector<int>> adj(n + 1);
    
//     for (int i = 1; i <= n; i++) {
//         int v; cin >> v;
//         value[i] = v;
//         indices[v].push_back(i);
//     }
    
//     for (int i = 0; i < m; i++) {
//         int u, v; cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
    
//     vector<bool> assembled(n + 1, false);
//     assembled[0] = true;  // 房梁始终存在
    
//     // 按价值从小到大组装
//     for (int val = 1; val <= k; val++) {
//         // 对于当前价值的所有节点，尝试组装
//         bool changed = true;
//         while (changed) {
//             changed = false;
//             vector<int> to_assemble;
            
//             for (int x : indices[val]) {
//                 if (assembled[x]) continue;
                
//                 // 检查x是否可以组装
//                 // 条件：至少有一个邻居已经组装
//                 bool can_assemble = false;
//                 for (int nei : adj[x]) {
//                     if (assembled[nei]) {
//                         can_assemble = true;
//                         break;
//                     }
//                 }
                
//                 if (can_assemble) {
//                     to_assemble.push_back(x);
//                     changed = true;
//                 }
//             }
            
//             // 组装所有可以组装的节点
//             for (int x : to_assemble) {
//                 assembled[x] = true;
//             }
//         }
        
//         // 检查是否还有未组装的当前价值节点
//         for (int x : indices[val]) {
//             if (!assembled[x]) {
//                 cout << "NO" << endl;
//                 return 0;
//             }
//         }
//     }
    
//     cout << "YES" << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> val(n + 1);
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    
    // 读入原图
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    
    // 构建依赖有向图
    vector<vector<int>> dep_adj(n + 1);
    vector<int> dep_in(n + 1, 0);
    
    // 计算每个节点有多少个非0邻居
    vector<int> non_zero_neighbors(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int nei : adj[i]) {
            if (nei != 0) non_zero_neighbors[i]++;
        }
    }
    
    // 对于原图中的每条边 (u, v)，u和v都不为0
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (v == 0 || u >= v) continue;  // 跳过连接到0的边，每条边只处理一次
            
            // 如果v只有u这一个非0邻居，那么v必须先于u移除
            if (non_zero_neighbors[v] == 1) {
                dep_adj[v].push_back(u);
                dep_in[u]++;
            }
            
            // 如果u只有v这一个非0邻居，那么u必须先于v移除
            if (non_zero_neighbors[u] == 1) {
                dep_adj[u].push_back(v);
                dep_in[v]++;
            }
        }
    }
    
    // 拓扑排序，同时检查价值约束
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (dep_in[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo_order.push_back(u);
        
        for (int v : dep_adj[u]) {
            // 检查价值约束：u → v，如果val(u) < val(v)，非法
            if (val[u] < val[v]) {
                cout << "NO\n";
                return 0;
            }
            
            dep_in[v]--;
            if (dep_in[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // 检查是否有环（拓扑序包含所有节点）
    if (topo_order.size() != n) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> val(n + 1);
    vector<vector<int>> byVal(k + 1);
    vector<vector<int>> adj(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        byVal[val[i]].push_back(i);
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> has(n + 1, false);
    has[0] = true;  // 房梁始终存在
    
    // 从低价值到高价值组装
    for (int v = 1; v <= k; v++) {
        bool changed = true;
        while (changed) {
            changed = false;
            for (int x : byVal[v]) {
                if (has[x]) continue;
                // 检查是否能连接到已有结构
                for (int nei : adj[x]) {
                    if (has[nei]) {
                        has[x] = true;
                        changed = true;
                        break;
                    }
                }
            }
        }
        
        // 检查是否所有该价值的节点都能组装
        for (int x : byVal[v]) {
            if (!has[x]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    
    cout << "YES\n";
    return 0;
} 