// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    double n ; cin >> n ; 
    
    if (n < 60) cout << 0.00 << endl ; 
    else {
        cout << (n - 60) / 0.1 * 0.01 + 1.0 << endl ;
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

    std::cout << std::fixed << std::setprecision(2) ;

    solve() ;
    
    return 0 ;
}