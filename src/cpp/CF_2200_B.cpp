// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ;
    vector<int> vec(n + 1) ; 
    int mx = INT_MIN ; bool f = false ; 
    for ( int i = 1 ; i <= n; i ++ ) {
        cin >> vec[i] ;
        if ( vec[i] < mx ) f = true ;
        mx = max(mx , vec[i]) ;
    }
    
    if ( f ) {
        cout << 1 << endl ; 
    } else cout << n << endl ;

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

    // cout << fixed << setprecision(6) ;

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}

