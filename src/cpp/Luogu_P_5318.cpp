// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int n , m ;

vector<vector<int>> adj ; 
/*
    排序功能要在怎么实现呢 如果是 BFS 的话 , 可以卡都绿一次性全部出队 然后排序
    或者干脆直接用最小堆

    DFS 怎么排序呢

    直接把图给排序即可

    因为你搜索的时候是直接遍历邻接表 , 从左到右 , 这个时候排序即可

    如果是一棵树的话确实不用 vis 但是出现了有多条路经可以到达一个节点的时候就靠考虑 vis 数组标记了

*/
void DFS( int sta , vector<int>& vis ) {

    cout << sta << ' ' ; 


    vis[sta] = 1 ; 

    for ( auto &a : adj[sta] ) {

        if ( !vis[a] ) {
            vis[a] = 1;  
            DFS( a , vis ) ;
            // vis[a] = 0 ; 
        } 

    }

}

void BFS ( int sta ,vector<int>& vis ) {

    queue<int> q ; 
    q.push( sta ) ;
    vis[sta] = 1 ;
    while ( !q.empty() ) {
        auto &u = q.front() ; q.pop() ; 

        cout << u << ' ' ; 

        for ( auto &v : adj[u] ) {
            if ( !vis[v] ) {
                q.push( v ) ; vis[v] = 1 ; 
            }
        }
    }

}


// 无向图和有向图的遍历有什去呗 无向图是怎么做到不重复访问产生死循环的

// 1 可以搞一个 fa 变量 , 每次记录他爹 , 然后是他爹就不访问就可以
// 2. 直接开一个全局的vector vis , 每个店只能被访问一次即可
// 3. 我的这个 DFS 好像有bug 

// ai 说寄哪里有向图 , 那么我要思考的是
// 有向图的方向你跟应该怎么建立 , 是谁指向谁呢
// 第二个 为什么要建立有向图啊

signed main() {



    cin >> n >> m ; 
    adj.resize( n + 1 ) ;

    vector<int> vis( n + 1 ) ;

    while ( m -- ) {
        int u , v ; cin >> u >> v ;
        adj[u].push_back( v ) ;
        // adj[v].push_back( u ) ; 
        // adj[min(u , v)].push_back(max( u , v ))  ;
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        sort( adj[i].begin() , adj[i].end()  ) ;
    }
    // vis[1] = 1 ; 
    DFS( 1 , vis ) ; 
    cout << endl ; 
    for ( int i = 1 ; i <= n ; i ++ ) vis[i] = 0 ; 
    BFS( 1 , vis ) ;

    return 0 ; 
}   




//