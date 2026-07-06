// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i] >> b[i] >> c[i] >> d[i] ; 
    }

    int ans0 = 0 , ans1 = 0 ;
    unordered_map<int, int> mp ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( a[i] > c[i] ) ans0 += abs(a[i] - c[i]) ; 
        if ( b[i] > d[i] ) {
            ans1 += abs(d[i] - b[i]) + min(a[i] , c[i]) ;  
        }
    }

    cout << ans0 + ans1 << endl ; 

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