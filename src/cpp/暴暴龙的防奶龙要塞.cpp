// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    if ( n <= 4 ) {
        cout << -1 << endl ; 
        return ; 
    }

    cout << n + 1  << endl ; 
    for ( int i = 1 ; i < n ; i ++ ) {
        cout << i << ' ' << i + 1 << endl ;
    }
    cout << 1 << ' ' << n - 2 << endl ; 
    cout << n - 2 << ' ' << n << endl ; 
    
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

    solve() ;
    
    return 0 ;
}