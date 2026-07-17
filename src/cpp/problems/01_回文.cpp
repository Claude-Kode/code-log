// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , m ; cin >> n >> m ; 
    vector<vector<char>> grid(n + 1, vector<char>(m + 1)) ;
    unordered_map<int, int> mp ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            cin >> grid[i][j] ;
            mp[grid[i][j]] ++ ; 
        }
    }
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            if ( mp[grid[i][j]] > 1 ) cout << "Y" ;
            else cout << "N" ; 
        }
        cout << endl  ;
    }

}

/*

我的第一想法就是找这个回文串最终会长成什么样子

但是我想不到怎么才能尽可能的搜到会问的路径

然后猜结论就猜到了

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