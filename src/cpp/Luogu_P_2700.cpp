// // @Author : GoryK 
// // @Description : TEMPLATE-2 
// #include <bits/stdc++.h> 

// using namespace std ; 

// #define int long long 
// #define endl '\n'

// const int mod = 1e9 + 7 ;
// const int maxn = 2e5 ; 



// void solve() {

//     int n ; cin >> n ;
//     vector<int> arr( n + 1 ) ; 



// }

// signed main() {


//     int tt ; cin >> tt ;
//     while( tt -- ) solve() ; 


//     return 0 ; 
// }   

// // 为了方便理解 , 我这里用的是点权
// // 实际计算可能要替换成边权
// vector<vector<int>> cost ;
// vector<vector<int>> min_dis ; 

// int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}} ;

// void DFS( int x , int y , int w ) {

//     if ( x == n && y == m ) {
//         min_dis[n][m] = min( min_dis[n][m] , w ) ; 
//         return ; 
//     }

//     for (auto &[delx , dely] : dirs ) {
//         int nx = x + delx ;
//         int ny = y + dely ; 
//         int nw = w + cost[nx][ny] ; 
//         DFS(nx , ny , nw) ; 
//     }

// }


// // 一般来说 最短路很少是网格图 我没怎么见过
// // 我写的题少 勿喷 QwQ
// struct infor { int v ; int w ; } ; 
// vector<vector<infor>> adj ; 
// vector<vector<int>> min_dis ; 

// int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}} ;


// void BFS( int u ) {

//     queue<infor> q ; 
//     for ( auto &[v , w] : adj[u] ) {
//         q.emplace( infor{v , w} ) ; 
//     }

//     while ( !q.empty() ) {
//         auto &[u ,w] = q.front() ; q.pop() ; 

//         if ( u == target ) { min_dis[u] = w ; return ; }

//         for ( auto &[v , ww] : adj[u] ) {
//             int curw = w + ww ; 
//             q.emplace( infor{v , curw } ) ; 
//         } 

//     }

//     cout << "Not reachable" << endl ; 

// }

// // 一般来说 最短路很少是网格图 我没怎么见过
// // 我写的题少 勿喷 QwQ
// struct infor { int v ; int w ; } ; 
// vector<vector<infor>> adj ; 
// vector<int> min_dis( n + 1 , INT_MAX ) ; 

// int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}} ;


// void bellman_ford( int u ) {

//     queue<infor> q ; 
//     for ( auto &[v , w] : adj[u] ) {
//         q.emplace( infor{v , w} ) ; 
//     }

//     while ( !q.empty() ) {
//         auto &[u ,w] = q.front() ; q.pop() ; 

//         for ( auto &[v , ww] : adj[u] ) {
//             int curw = w + ww ; 
//             if ( min_dis[v] > curw ) {
//                 min_dis[v] = curw ; 
//                 q.emplace( infor{v , curw } ) ; 
//             }
//         } 

//     }

//     if ( min_dis[target] == INT_MAX ) cout << "Not reachable" << endl ; 
//     else cout << min_dis[target] ; 

// }

// struct infor { int v ; int w ; } ; 
// vector<vector<infor>> adj ; 
// vector<int> min_dis( n + 1 , INT_MAX ) ; 

// int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}} ;

   
// void BFS( int u ) {

//     queue<infor> q ; 
//     for ( auto &[v , w] : adj[u] ) {
//         q.emplace( infor{v , w} ) ; 
//     }

//     while ( !q.empty() ) {
//         auto &[u ,w] = q.front() ; q.pop() ; 

//         for ( auto &[v , ww] : adj[u] ) {
//             if ( min_dis[v] > dis[u] + ww ) {
//                 min_dis[v] = curw ; 
//                 q.emplace( infor{v , curw } ) ; 
//             }
//         } 

//     }

//     if ( min_dis[target] == INT_MAX ) cout << "Not reachable" << endl ; 
//     else cout << min_dis[target] ; 

// }


// struct infor { int v ; int w ; } ; 

// // 围殴什么要添加这样一个数组呢 
// // 因为如果一个点的距离被更新了 , 他一定你是在队列里面的
// // 此时如果再去更新 , 就会把一个节点记性你冲愤怒入队
// vector<int> inque ; 
// vector<vector<infor>> adj ; 
// vector<int> min_dis( n + 1 , INT_MAX ) ; 

// int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}} ;


// void SPFA( int u ) {

//     queue<infor> q ; 
//     for ( auto &[v , w] : adj[u] ) {
//         q.emplace( infor{v , w} ) ; 
//     }

//     while ( !q.empty() ) {
//         auto &[u ,w] = q.front() ; q.pop() ; 
//         inque[u] = 1 ; 

//         for ( auto &[v , ww] : adj[u] ) {
//             int curw = w + ww ; 
//             if ( min_dis[v] > curw && !inque[v] ) {
//                 inque[v] = 1 ;    
//                 min_dis[v] = curw ; 
//                 q.emplace( infor{v , curw } ) ; 
//             }
//         } 
//     }

//     if ( min_dis[target] == INT_MAX ) cout << "Not reachable" << endl ; 
//     else cout << min_dis[target] ; 

// }