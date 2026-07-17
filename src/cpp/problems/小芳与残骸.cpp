// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998244353 ; 
const int maxn = 2e5 + 10 ;

int fp( int x , int p ) {
    int base = x , res = 1 ; 
    while (p) {
        if ( p & 1 ) res = res * base % mod ; 
        p >>= 1 ;
        base = base * base % mod ;  
    }
    return res % mod ; 
}

void solve() {

    int n ; cin >> n ; 
    cout << fp(2 , n - 1) << endl ; 
    // 对于每一段连续的 1 来说都有两种方案

    
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