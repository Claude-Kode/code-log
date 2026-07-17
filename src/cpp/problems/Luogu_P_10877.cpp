// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998244353 ; 
const int maxn = 2e5 + 10 ;

int fp(int x , int p) {
    int res = 1 , base = x ;
    while ( p ) {
        if (p & 1) (res *= base) %= mod ; 
        (base *= base) %= mod ;
        p >>= 1 ;
    }
    return res ; 
}

void solve() {

    int n ; cin >> n ; 
    string str ; cin >> str ; 
    cout << fp(2 , n - 2) << endl ;
    
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

