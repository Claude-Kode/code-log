// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int x1 , x2 , x3 , y1 , y2 , y3 ; 
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
    
    double a = 1.0 * (y1 - y2) / (x1 - x2) ; 
    double b = 1.0 * (y2 - y3) / (x2 - x3) ; 
    double c = 1.0 * (x1 - x3) ; 

    if (((a - b) / c) > 0) cout << "UP" << endl ; 
    else cout << "DOWN" << endl ;   

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