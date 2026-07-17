// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> adj(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> adj[i] ; 
    }

    int ans = 0 ; 
    for ( int i = 1 ; i <= n - 1 ; i ++ ) {
        for ( int j = i + 1 ; j <= n ; j ++ ) {
            if ( adj[j] <= adj[i] ) ans ++ ; 
        }
    }    

    cout << ans << endl ; 
    
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