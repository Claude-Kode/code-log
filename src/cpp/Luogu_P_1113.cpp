// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int n ; 

struct edge{ int v ; int w ; } ;

/*

*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    
    cin >> n ; 
    vector<int> cost( n + 1 ) ;
    vector<int> indegree( n + 1 ) ;
    vector<vector<int>> adj( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        int u , v , w ; cin >> u >> cost[i] ; 
        while ( cin >> v && v ) adj[v].emplace_back( u ) , indegree[u] ++ ; 
    }

    int ans = 0 ; 
    queue<int> q ;
    for ( int i = 1 ; i <= n ; i ++ ) { if ( !indegree[i] ) q.push( i ) ; }

    while ( !q.empty() ) {
        auto t = q.front() ; q.pop() ; 
        ans += cost[t] ; 
        for ( auto &a : adj[t] ) {
            // cout << t << ' ' << a  << ' ' << cost[a] << endl ; 
            if ( !--indegree[a] ) q.push( a ) ; 
        }
        // cout << endl ; 
    }

    cout << ans << endl ; 




    return 0 ; 
}   

/*
    
*/