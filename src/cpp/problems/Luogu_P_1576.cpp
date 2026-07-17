// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int double
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int n , m ; 
int a , b ; 

struct infor { int v ; int w ; } ;

vector<int> dp ; 
vector<vector<infor>> adj ; 

signed main() {

    cout << fixed << setprecision( 8 ) ; 

    cin >> n >> m ;
    dp.resize(n + 1 , INT_MAX) ; 
    adj.resize(n + 1) ; 
    while ( m -- ) {
        int u , v , w ; cin >> u >> v >> w ;
        adj[u].push_back( infor{v , w} ) ; 
        adj[v].push_back( infor{u , w} ) ; 
    }   

    cin >> a >> b ; 

    queue<int> q ; 
    q.push( a ) ; dp[a] = 100 ; 
    while ( !q.empty() ) {
        auto u = q.front() ; q.pop() ; 

        for ( auto &[v , ww] : adj[u] ) {
            if ( dp[v] > dp[u] * (1 + ww / 100) ) {
                dp[v] = dp[u] * (1 + ww / 100) ; 
            }
        }

    }

    cout << dp[b] << endl ; 

    return 0 ; 
}   

