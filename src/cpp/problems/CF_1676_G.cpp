// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , root ; cin >> n ; 
    vector<int> adj(n + 1) , indegree(n + 1) ; 
    for ( int i = 2 ; i <= n ; i ++ ) {
        cin >> adj[i] ; indegree[adj[i]] ++ ; 
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        // cout << indegree[i] << ' ' ;
    }

    // cout << endl ; 

    string infor(1 , '0') , temp ; cin >> temp , infor += temp ;  
    vector<vector<int>> memo(n + 1 , vector<int>(2)) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( infor[i] == 'W' ) memo[i][1] ++ ;
        else memo[i][0] ++ ;  
    }

    queue<int> q ; 
    for ( int i = 1 ; i <= n ; i ++ ) if(!indegree[i]) {
        
        // cout << i << ' ' ; 

        // indegree[adj[i]] -- ; 
        // memo[adj[i]][0] += memo[i][0] ;
        // memo[adj[i]][1] += memo[i][1] ;
        q.push(i) ; 
    }

    while(!q.empty()) {
        auto x = q.front() ; q.pop() ;
        int t = adj[x] ; 

        // cout << x << ' ' << t << endl ; 

        memo[t][0] += memo[x][0] ;
        memo[t][1] += memo[x][1] ;
        if (!--indegree[t]) q.push(t) ; 
    }
 
    // cout << endl ; 

    int cnt = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        // cout << memo[i][0] << ' ' << memo[i][1] << endl ;
        cnt += (memo[i][0] == memo[i][1] && memo[i][0] && memo[i][1] ) ; 
    }

    // cout << endl ;
    cout << cnt << endl ; 

}

/*

*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}