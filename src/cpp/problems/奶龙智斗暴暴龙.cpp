// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ;
    double res = 0.5 + 0.5 * (n - 1) / (2 * n - 1) ; 
    cout << res << endl ; 
    
}

/*
double p = 0.5 + (n - 1.0) / (4.0 * n - 2.0);
*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif

    cout << fixed << setprecision( 6 ) ;

    solve() ;
    
    return 0 ;
}