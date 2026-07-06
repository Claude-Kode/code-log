/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream> 
#include <utility>
#include <bitset>
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <deque> 
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define TUP tuple<int , int , int>
#define ull unsigned long long
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD1 = 998244353 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ; 
int sx , sy , ex , ey ; 

int dirs[8][2] = {{-2 , 1}, {-1 , 2}, {1 , 2}, {2 , 1}, {-2 , -1}, {-1 , -2}, {1 , -2}, {2 , -1}} ; 

vector<vector<int>> cnt ; 
vector<vector<int>> grid ; 
vector<vector<int>> cost ; 
vector<vector<int>> graph ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

bool check( int x , int y ) {
    return x > 0 && x <= n && y > 0 && y <= m ; 
}

int get_id(  int x , int y ) {
    return (x - 1) * m + y ; 
}

void DFS(int source_id, int x, int y, vector<vector<int>>& vis) {

    vis[x][y] = 1 ; 
    for( auto &[delx , dely] : dirs ) {
        int nx = x + delx , ny = y + dely ; 
        if ( !check(nx , ny) ) continue ; 
        if ( grid[nx][ny] == 2 || vis[nx][ny] ) continue ; 
        if ( grid[nx][ny] == 0 || grid[nx][ny] == 4 ) {
            graph[source_id].push_back( get_id(nx , ny) ) ;
            vis[nx][ny] = 1 ;
        }
        else {
            DFS( source_id , nx , ny , vis ) ; 
        }    
    }

}


void SPFA( int sx , int sy ) {

    queue<int> q ; 
    cnt[sx][sy] = 1 ; 
    cost[sx][sy] = 0 ; 
    vector<vector<int>> inque( n + 1 , vector<int>( m + 1 ) ) ; 
    inque[sx][sy] = 1 ;  
    q.emplace( get_id(sx , sy) ) ;
    while ( !q.empty() ) {
        auto source_id = q.front() ; q.pop() ; 
        int x = (source_id - 1) / m + 1 ;
        int y = (source_id - 1) % m + 1 ; 
        inque[x][y] = 0 ;
        for ( auto &cur_id : graph[source_id] ) {

            int nx = (cur_id - 1) / m + 1 ;
            int ny = (cur_id - 1) % m + 1 ; 
    
            if ( cost[nx][ny] > cost[x][y] + 1 ) {
                cost[nx][ny] = cost[x][y] + 1 ;
                cnt[nx][ny] = cnt[x][y] ; 
                if ( !inque[nx][ny] ) q.emplace( get_id(nx , ny) ) ;
                inque[nx][ny] = 1 ; 
            } else if ( cost[nx][ny] == cost[x][y] + 1 ) {
                cnt[nx][ny] += cnt[x][y] ; 
            } 

        }
    }

}

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
    cin >> n >> m ; 
    graph.resize( n * m + 1 ) ; 
    cnt.resize( n + 1 , vector<int>(m + 1)) ; 
    grid.resize( n + 1 , vector<int>(m + 1)) ; 
    cost.resize( n + 1 , vector<int>(m + 1 , INT_MAX)) ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            cin >> grid[i][j] ; 
            if ( grid[i][j] == 4 ) ex = i , ey = j ;  
            if ( grid[i][j] == 3 ) sx = i , sy = j , grid[i][j] = 1 ; 
        }
    }
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            if ( grid[i][j] == 0 ) {
                vector<vector<int>> vis( n + 1 , vector<int>( m + 1 )) ; 
                DFS( get_id(i , j) , i , j , vis ) ;
            }
        }
    }

    vector<vector<int>> vis( n + 1 , vector<int>( m + 1 )) ; 
    DFS( get_id(sx , sy) , sx , sy , vis ) ; 

    SPFA( sx , sy ) ;

    if ( cost[ex][ey] == INT_MAX ) cout << -1 << endl ; 
    else {
        cout << cost[ex][ey] - 1 << endl << cnt[ex][ey] << endl ; 
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/


// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 0x3f3f3f3f;

// int n, m;
// int sx, sy, ex, ey;

// int dirs[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
//                   {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

// vector<vector<int>> grid;
// vector<vector<long long>> cnt;
// vector<vector<long long>> cost;
// vector<vector<int>> graph;

// int get_id(int x, int y) {
//     return (x - 1) * m + y;
// }

// bool check(int x, int y) {
//     return x >= 1 && x <= n && y >= 1 && y <= m;
// }

// // 正确的DFS
// void DFS(int source_id, int x, int y, vector<vector<bool>>& vis) {
//     vis[x][y] = true;
    
//     for (auto &[dx, dy] : dirs) {
//         int nx = x + dx, ny = y + dy;
//         if (!check(nx, ny) || vis[nx][ny]) continue;
        
//         if (grid[nx][ny] == 2) continue;  // 石头
        
//         if (grid[nx][ny] == 1) {  // 莲花
//             DFS(source_id, nx, ny, vis);
//         } 
//         else {  // 水(0)或终点(4)
//             graph[source_id].push_back(get_id(nx, ny));
//             vis[nx][ny] = true;  // 标记但不继续DFS
//         }
//     }
// }

// void SPFA() {
//     queue<int> q;
//     vector<vector<bool>> inque(n + 1, vector<bool>(m + 1, false));
    
//     cost[sx][sy] = 0;
//     cnt[sx][sy] = 1;
//     q.push(get_id(sx, sy));
//     inque[sx][sy] = true;
    
//     while (!q.empty()) {
//         int id = q.front(); q.pop();
//         int x = (id - 1) / m + 1;
//         int y = (id - 1) % m + 1;
//         inque[x][y] = false;
        
//         for (int nid : graph[id]) {
//             int nx = (nid - 1) / m + 1;
//             int ny = (nid - 1) % m + 1;
            
//             long long new_cost = cost[x][y] + 1;  // 所有边权都是1
            
//             if (new_cost < cost[nx][ny]) {
//                 cost[nx][ny] = new_cost;
//                 cnt[nx][ny] = cnt[x][y];
//                 if (!inque[nx][ny]) {
//                     q.push(nid);
//                     inque[nx][ny] = true;
//                 }
//             } 
//             else if (new_cost == cost[nx][ny]) {
//                 cnt[nx][ny] += cnt[x][y];
//             }
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     cin >> n >> m;
    
//     graph.resize(n * m + 5);
//     grid.resize(n + 1, vector<int>(m + 1));
//     cost.assign(n + 1, vector<long long>(m + 1, INF));
//     cnt.assign(n + 1, vector<long long>(m + 1, 0));
    
//     // 读取
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             cin >> grid[i][j];
//             if (grid[i][j] == 3) {
//                 sx = i; sy = j;
//                 grid[i][j] = 1;  // 起点视为莲花
//             } else if (grid[i][j] == 4) {
//                 ex = i; ey = j;
//             }
//         }
//     }
    
//     // 对每个水位置和起点进行DFS预处理
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             // 只处理水(0)和起点(3，已变成1)
//             if (grid[i][j] == 1 || grid[i][j] == 2) continue;
            
//             // 终点在DFS中会被作为目标处理，但不要从终点开始DFS
//             if (grid[i][j] == 4) continue;
            
//             vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
//             DFS(get_id(i, j), i, j, vis);
//         }
//     }
    
//     // 还需要从起点DFS（因为起点现在是莲花1）
//     vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
//     DFS(get_id(sx, sy), sx, sy, vis);
    
//     // 计算最短路
//     SPFA();
    
//     if (cost[ex][ey] == INF) {
//         cout << -1 << endl;
//     } else {
//         cout << cost[ex][ey] - 1 << endl << cnt[ex][ey] << endl;
//     }
    
//     return 0;
// }

// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

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

// int n , m ; 
// int sx , sy , ex , ey ; 

// int dirs[8][2] = {{-2 , 1}, {-1 , 2}, {1 , 2}, {2 , 1}, {-2 , -1}, {-1 , -2}, {1 , -2}, {2 , -1}} ; 

// vector<vector<int>> cnt ; 
// vector<vector<int>> cost ; 
// vector<vector<int>> grid ; 
// vector<vector<int>> graph ; 

// struct node { int x , y ; } ; 

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// bool check ( int x , int y ) {
//     return x > 0 && x <= n && y > 0 && y <= m ;
// }

// int get_id( int i , int j ) {
//     return i * (m - 1) + j ; 
// }

// void DFS( int source_id , int x , int y ) {

//     int cur_id = get_id(x , y) ; 

//     if ( grid[x][y] == 2 ) return ; 

//     if ( grid[x][y] == 1 ) {
//         // 加一条边
//         graph[source_id].push_back( cur_id ) ;
//         return ; 
//     }

//     for ( auto [delx , dely] : dirs ) {
//         int nx = x + delx , ny = y + dely ; 
//         if ( check(nx , ny) ) {
//             DFS( get_id(x , y) , nx , ny ) ;
//         } 
//     }

// }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*

// 因为我的计数原则是根据权值进行区分的 ,
// 本质上就是去重没有做好,  
// 还有就是因为这个是免费 , 
// 经过它不会改变权值 , 
// 所以如果这个莲花之间的路径有权值就好了 , 
// 代码的思路就是 , 
// 当接触到一个莲花的联通快的时候 , 
// 直接从这个莲花搜索到所有能免费去的水的地方 , 
// 这样莲花到水就是权值是 1 了

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     cin >> n >> m ;
//     graph.resize( n * m + 1 ) ; 
//     grid.resize( n + 1 , vector<int>( m + 1 )) ; 
//     cnt.resize( n + 1 , vector<int>( m + 1 , 0)) ; 
//     cost.resize( n + 1 , vector<int>( m + 1 , INT_MAX)) ; 

//     // 1 -> 水 . 2 -> 石头(不能放莲花) . 3 -> 起点 , 4 -> 终点
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         for ( int j = 1 ; j <= m ; j ++ ) {
//             cin >> grid[i][j] ; 
//         }
//     }

//     for ( int i = 1 ; i <= n ; i ++ ) {
//         for ( int j = 1 ; j <= m ; j ++ ) {
//             if ( grid[i][j] == 3 || grid[i][j] == 1 ) {
//                 DFS(get_id(i , j) , i , j) ; 
//             }
//         }
//     }

//     // cost[i][j] 代表从起点走到 (i , j) 的最小花费 ) 
//     // cnt[i][j] 代表这个最小花费对应的方法数量
//     deque<node> dq ; 
//     cost[sx][sy] = 0 ; cnt[sx][sy] = 1 ;
//     dq.emplace_back( node{sx , sy} ) ;
//     while ( !dq.empty() ) {
//         auto [x , y] = dq.front() ; dq.pop_front() ;

//         int source_id = get_id( x , y ) ;   
//         for (auto &cur_id : graph[source_id] ) {
//             // cout << "yes" << endl ; 
//             int nx = cur_id / m ; 
//             int ny = cur_id % m ;
//             if ( nx > 0 && nx <= n && ny > 0 && ny <= m && grid[nx][ny] != 2 ) {
//                 int curCost = (grid[nx][ny] == 1) ; 
//                 if ( cost[nx][ny] > cost[x][y] + curCost) {
//                     if ( curCost == 0 ) {
//                         dq.emplace_front( node{nx , ny} ) ; 
//                     } else {
//                         dq.emplace_back( node{nx , ny} ) ;
//                     }
//                     cost[nx][ny] = cost[x][y] + curCost ; 
//                     cnt[nx][ny] = cnt[x][y] ; 
//                 } else if ( cost[nx][ny] == cost[x][y] + curCost ) {
//                     cnt[nx][ny] += cnt[x][y] ; 
//                 }
//             } 
//         }

//     }  

//     cout << "cost" << endl ; 
//     for ( auto &row : cost ) {
//         for ( auto &a : row ) {
//             cout << a << ' ' ;
//         }
//         cout << endl ; 
//     }

//     cout << "cnt" << endl ; 
//     for ( auto &row : cnt ) {
//         for ( auto &a : row ) {
//             cout << a << ' ' ;
//         }
//         cout << endl ; 
//     }

//     if ( cost[ex][ey] == INT_MAX ) { cout << -1 << endl ; return 0 ; } 

//     cout << cost[ex][ey] << endl << cnt[ex][ey] << endl ;  

//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */

// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 35;
// const int MAX_NODES = MAXN * MAXN + 5;

// int n, m;
// int sx, sy, ex, ey;

// int dirs[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
//                   {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

// vector<vector<int>> grid;
// vector<int> graph[MAX_NODES];
// vector<long long> dist;
// vector<long long> cnt;

// // 正确的一维编号
// int get_id(int x, int y) {
//     return (x - 1) * m + y;  // 编号从1开始
// }

// // DFS预处理（和原AC代码一样的逻辑）
// void dfs_preprocess(int source_id, int x, int y, vector<vector<bool>>& visited) {
//     visited[x][y] = true;
    
//     for (auto &[dx, dy] : dirs) {
//         int nx = x + dx, ny = y + dy;
        
//         // 边界检查
//         if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
//         if (visited[nx][ny]) continue;
        
//         // 如果是石头，跳过
//         if (grid[nx][ny] == 2) continue;
        
//         // 如果是莲花(1)，继续DFS
//         if (grid[nx][ny] == 1) {
//             dfs_preprocess(source_id, nx, ny, visited);
//         }
//         // 如果是水(0)或终点(4)，建边
//         else if (grid[nx][ny] == 0 || grid[nx][ny] == 4) {
//             visited[nx][ny] = true;
//             graph[source_id].push_back(get_id(nx, ny));
//         }
//         // 注意：起点(3)在网格中已经标记为1（莲花）
//     }
// }

// // SPFA最短路计数
// void spfa(int start_id, int end_id) {
//     int total_nodes = n * m + 5;
//     dist.assign(total_nodes, LLONG_MAX);
//     cnt.assign(total_nodes, 0);
//     vector<bool> inq(total_nodes, false);
    
//     queue<int> q;
//     dist[start_id] = 0;
//     cnt[start_id] = 1;
//     q.push(start_id);
//     inq[start_id] = true;
    

//     // 如果是水(0)或终点(4)，建边
//     // 注意：起点(3)在网格中已经标记为1（莲花）
//     while (!q.empty()) {
//         int u = q.front(); q.pop();
//         inq[u] = false;
        
//         for (int v : graph[u]) {
//             long long new_dist = dist[u] + 1;  // 所有边权都是1
            
//             if (new_dist < dist[v]) {
//                 dist[v] = new_dist;
//                 cnt[v] = cnt[u];
//                 if (!inq[v]) {
//                     q.push(v);
//                     inq[v] = true;
//                 }
//             } else if (new_dist == dist[v]) {
//                 cnt[v] += cnt[u];
//             }
//         }
//     }
    
//     if (dist[end_id] == LLONG_MAX) {
//         cout << -1 << endl;
//     } else {
//         // 注意：距离要减1，因为起点不算添加的莲花
//         cout << dist[end_id] - 1 << endl << cnt[end_id] << endl;
//     }
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     cin >> n >> m;
//     grid.resize(n + 1, vector<int>(m + 1));
    
//     // 读取网格
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             cin >> grid[i][j];
//             if (grid[i][j] == 3) {
//                 sx = i; sy = j;
//                 grid[i][j] = 1;  // 起点视为莲花
//             } else if (grid[i][j] == 4) {
//                 ex = i; ey = j;
//                 // 终点保持为4，在DFS中会特殊处理
//             }
//         }
//     }
    
//     // 对每个特殊位置进行DFS预处理
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             // 跳过石头(2)和普通莲花(1)
//             if (grid[i][j] == 1 || grid[i][j] == 2) continue;
            
//             // 跳过终点
//             if (grid[i][j] == 4) continue;
            
//             // 只对水(0)和起点(3，已经变成1)进行DFS
//             // 实际上这里只剩下水(0)了
//             vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
//             dfs_preprocess(get_id(i, j), i, j, visited);
//         }
//     }
    
//     // 还需要处理起点（因为起点在网格中是1）
//     vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
//     dfs_preprocess(get_id(sx, sy), sx, sy, visited);
    
//     // 跑最短路
//     spfa(get_id(sx, sy), get_id(ex, ey));
    
//     return 0;
// }

// // #include <bits/stdc++.h>
// // using namespace std;

// // const int MAXN = 35;
// // const int MAXM = 35;
// // const int MAX_NODES = MAXN * MAXM + 5;
// // const long long INF = 1e16;

// // // 马步的8个方向
// // const int knight_moves[8][2] = {
// //     {1, 2}, {-1, 2}, {1, -2}, {-1, -2},
// //     {2, 1}, {-2, 1}, {2, -1}, {-2, -1}
// // };

// // int n, m;
// // int start_x, start_y, end_x, end_y;
// // int grid[MAXN][MAXN];

// // // 图相关
// // vector<int> graph[MAX_NODES];
// // long long dist[MAX_NODES];
// // long long path_count[MAX_NODES];
// // bool in_queue[MAX_NODES];

// // // 工具函数：二维坐标转一维编号
// // inline int get_id(int x, int y) {
// //     return (x - 1) * m + y;
// // }

// // // 读取整数（快速读入）
// // inline int read_int() {
// //     int num = 0;
// //     char ch = getchar();
// //     while (ch < '0' || ch > '9') ch = getchar();
// //     while (ch >= '0' && ch <= '9') {
// //         num = num * 10 + (ch - '0');
// //         ch = getchar();
// //     }
// //     return num;
// // }

// // // 检查位置是否非法
// // inline bool is_invalid(int x, int y) {
// //     return x < 1 || x > n || y < 1 || y > m || 
// //            grid[x][y] == 2 || grid[x][y] == 3;
// // }

// // // DFS预处理：从位置(x,y)出发，找到所有可达的水位置
// // void dfs_preprocess(int source_id, int x, int y, bool visited[MAXN][MAXN]) {
// //     visited[x][y] = true;
    
// //     for (int i = 0; i < 8; i++) {
// //         int nx = x + knight_moves[i][0];
// //         int ny = y + knight_moves[i][1];
        
// //         // 跳过非法位置或已访问位置
// //         if (is_invalid(nx, ny) || visited[nx][ny]) continue;
        
// //         // 如果是莲花(1)，继续DFS
// //         if (grid[nx][ny] == 1) {
// //             dfs_preprocess(source_id, nx, ny, visited);
// //         } 
// //         // 如果是水(0)或终点(4)，建边并标记访问
// //         else {
// //             visited[nx][ny] = true;
// //             graph[source_id].push_back(get_id(nx, ny));
// //         }
// //     }
// // }

// // // SPFA计算最短路和路径数
// // void spfa_shortest_path(int start_id, int end_id) {
// //     // 初始化
// //     for (int i = 1; i <= n * m; i++) {
// //         dist[i] = INF;
// //         path_count[i] = 0;
// //         in_queue[i] = false;
// //     }
    
// //     // 队列
// //     int queue[MAX_NODES * 10];
// //     int head = 0, tail = 1;
    
// //     // 起点初始化
// //     dist[start_id] = 0;
// //     path_count[start_id] = 1;
// //     queue[1] = start_id;
// //     in_queue[start_id] = true;
    
// //     while (head < tail) {
// //         head = (head + 1) % (MAX_NODES * 10);
// //         int u = queue[head];
// //         in_queue[u] = false;
        
// //         // 遍历所有邻接点
// //         for (int v : graph[u]) {
// //             long long new_dist = dist[u] + 1;  // 所有边权都是1
            
// //             // 找到相同距离的路径，累加计数
// //             if (dist[v] == new_dist) {
// //                 path_count[v] += path_count[u];
// //             }
// //             // 找到更短路径，更新距离和计数
// //             else if (dist[v] > new_dist) {
// //                 dist[v] = new_dist;
// //                 path_count[v] = path_count[u];
                
// //                 if (!in_queue[v]) {
// //                     tail = (tail + 1) % (MAX_NODES * 10);
// //                     queue[tail] = v;
// //                     in_queue[v] = true;
// //                 }
// //             }
// //         }
// //     }
    
// //     // 如果无法到达终点
// //     if (dist[end_id] == INF) {
// //         printf("-1");
// //         exit(0);
// //     }
// // }

// // int main() {
// //     // 读取网格大小
// //     n = read_int();
// //     m = read_int();
    
// //     // 读取网格
// //     for (int i = 1; i <= n; i++) {
// //         for (int j = 1; j <= m; j++) {
// //             grid[i][j] = read_int();
            
// //             // 记录起点和终点
// //             if (grid[i][j] == 3) {
// //                 start_x = i;
// //                 start_y = j;
// //             } else if (grid[i][j] == 4) {
// //                 end_x = i;
// //                 end_y = j;
// //             }
// //         }
// //     }
    
// //     // 对每个特殊位置进行DFS预处理建图
// //     for (int i = 1; i <= n; i++) {
// //         for (int j = 1; j <= m; j++) {
// //             // 跳过石头(2)和普通莲花(1)
// //             if (grid[i][j] && grid[i][j] <= 2) continue;
            
// //             // 跳过终点（在后面的代码中处理）
// //             if (grid[i][j] == 4) continue;
            
// //             // 对起点(3)和水(0)进行DFS预处理
// //             bool visited[MAXN][MAXN] = {false};
// //             dfs_preprocess(get_id(i, j), i, j, visited);
// //         }
// //     }
    
// //     // 计算最短路
// //     int start_id = get_id(start_x, start_y);
// //     int end_id = get_id(end_x, end_y);
// //     spfa_shortest_path(start_id, end_id);
    
// //     // 输出结果：距离-1 和 路径数
// //     printf("%lld\n%lld", dist[end_id] - 1, path_count[end_id]);
    
// //     return 0;
// // }