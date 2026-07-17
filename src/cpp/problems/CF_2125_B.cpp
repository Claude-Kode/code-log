// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int gcd(int a , int b) { return b == 0 ? a : gcd(b , a % b) ; }

void solve() {

    int a , b , k ; cin >> a >> b >> k ;
    int GCD = gcd(a , b) ; 
    if ( a / GCD <= k && b / GCD <= k ) cout << 1 << endl ; 
    else cout << 2 << endl ; 

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