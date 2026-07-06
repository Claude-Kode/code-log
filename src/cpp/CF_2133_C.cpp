// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    // Steve 会找出从 x开始、只经过 S中位置的最长路径，并告诉你该路径包含的位置数量。
    int n ; cin >> n ; int mx = INT_MIN ; 
    vector<vector<int>> adj(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << '?' << ' ' << i << ' ' << n << ' ' ; for ( int j = 1 ; j <= n ; j ++ ) cout << j << ' ' ;
        cout << endl ; cout.flush() ; 
        int num ; cin >> num ; mx = max(mx , num) ; 
        adj[num].push_back( i ) ; 
    }

    vector<int> path(1 , adj[mx][0]); 
    for ( int i = mx - 1 ; i >= 1 ; i -- ) {
        for (auto &x : adj[i]) {
            cout << '?' << ' ' << path.back() << ' ' << 2 << ' ' << path.back() << ' ' << x << endl ;
            cout.flush() ; 
            int num ; cin >> num ; if ( num == 2 ) { path.push_back(x) ; break ; }
        }
    }
    
    cout << '!' << ' ' << path.size() << ' ' ; 
    for (auto &a : path) cout << a << ' ' ;
    cout << endl ; cout.flush() ;

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