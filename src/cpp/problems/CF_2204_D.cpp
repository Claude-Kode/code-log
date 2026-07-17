// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , m ; cin >> n >> m ; 
    vector<vector<int>> adj(n + 1) ; 
    for ( int i = 1 ; i <= m ; i ++ ) {
        int u , v ; cin >> u >> v ; 
        adj[v].push_back( u ) ;
        adj[u].push_back( v ) ;
    }

    int ans = 0 ;
    vector<int> color(n + 1 , -1) , vis(n + 1) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        int cnt1 = 0 , cnt0 = 1 ;
        if ( vis[i] ) continue ; 
        vis[i] = 1 ; color[i] = 0 ;  bool con = true ; 
        queue<int> q ; q.push(i) ; 
        while ( !q.empty() ) {
            auto u = q.front() ; q.pop() ; 
            for ( const auto &v : adj[u] ) {
                vis[v] = 1 ; 
                if ( color[v] == -1 ) {
                    q.push(v) ; 
                    if (color[u] == 0) color[v] = 1 , cnt1 ++ ; 
                    if (color[u] == 1) color[v] = 0 , cnt0 ++ ; 
                }
                if ( color[u] == color[v] ) con = false ; 
            }
        }
        if (con) ans += max(cnt1 , cnt0) ;  
    }

    cout << ans << endl ; 

}

/*
所谓的挖煤单奇数
完美点是从一个点出发的所有路径都是交替路径  
注意是所有 , 所以二分途中有一个矛盾的地方就不行了
*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif

    // cout << fixed << setprecision(6) ;

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}

