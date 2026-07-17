// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<vector<int>> vec(n + 1, vector<int>(n + 1)) ; 
    unordered_map<int,int> ump ; bool ok = false ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= n ; j ++ ) {
            cin >> vec[i][j] ;
            ump[vec[i][j]] ++ ; 
            if ( ump[vec[i][j]] > n * (n - 1) ) ok = true ;
        }
    } 
    
    if ( !ok ) {
        cout << "YES" << endl ; 
    } else {
        cout << "NO" << endl ; 
    }

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

