// // @Author : GoryK 
// // @Description : TEMPLATE-2 
// #include <bits/stdc++.h> 

// using namespace std ; 

// #define int long long 
// #define endl '\n'

// const int mod = 1e9 + 7 ;
// const int maxn = 2e5 ; 

// int n , m ; 

// vector<int> vis ; 
// vector<int> dis ; 
// vector<vector<int>> adj ;

// void DFS( int sta ) {

//     // error-1
//     if ( dis[sta] >= sta ) return ;

//     queue<int> q ; 
//     q.push( sta ) ; vis[sta] = 1 ;
//     while ( !q.empty() ) {
//         auto u = q.front() ; q.pop() ; 

//         dis[u] = max( dis[u] , sta ) ; 

//         for ( auto &v : adj[u] ) {
//             // error-2 vis[v] didnt set to 1 
//             if ( !dis[v] ) { q.push( v ) ; }
//         }
//     }
    
// }

// signed main() {
//     cin >> n >> m ; 
//     vis.resize( n + 1 ) ; 
//     adj.resize( n + 1 ) ;   
//     dis.resize( n + 1 , 0 ) ;  
//     while ( m -- ) {
//         int u ,v ; cin >> u >> v;  
//         adj[v].push_back( u ) ; 
//     }
//     for ( int i = n; i >= 1; i -- ) {
//         if ( dis[i] == 0 ) {
//             DFS( i ) ;
//             // error-3 
//             // 反图算法每个点就访问一次 这是为什么
//             // for ( int i = 1 ; i <= n ; i ++ ) vis[i] = 0 ;
//         }
//     }    
//     for( int i = 1; i <= n ; i ++ ) cout << dis[i] << ' '; 
//     return 0 ; 
// }   

//     // 如果这个图是一颗树的话一次遍历直接出绝对没有问题 !!!
//     // 但是这道题是一个混合图
//     // 有的时候父亲的信息是可以传给儿子的
//     // 所以要换根去搜
//     // 这就是个图上 dp 
//     // 所以可以用记忆化搜索
//     // 只要上一个节点有答案那么他一定被完整的搜索了吗 ?? 
//     // 

// // 

// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



/*
还是那个思路
正难则反 , 不行就直接重建图就行
忘记反向见图了 !!!!!
*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;


    int n , m ; cin >> n >> m ; 
    
    vector<vector<int>> adj( n + 1 ) ; 
    while ( m -- ) {
        int u , v ; cin >> u >> v;  
        adj[v].push_back( u ) ;
    }     

    vector<int> dis(n + 1 , -1) ; 
    auto BFS = [&]( int i ) -> void {
        queue<int> q ; q.push( i ) ;  
        dis[i] = i ;  
        while( !q.empty() ) {
            auto t = q.front() ; q.pop() ; 
            for ( auto &a : adj[t] ) {
                if ( dis[a] == -1 ) dis[a] = i , q.push( a ) ; 
            }
        }   
    } ; 

    for ( int i = n ; i > 0 ; i -- ) {
        if ( dis[i] == -1 ) BFS( i ) ; 
    }

    for ( int i = 1 ; i <= n ; i++ ) cout << dis[i] << ' ' ;

    cout << endl ; 

    return 0 ; 
}   

/*
    
*/