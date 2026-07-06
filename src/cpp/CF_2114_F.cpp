// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

// int gcd(int a , int b) { return (b ? a : gcd(b , a % b)) ; }

struct PII {int a ; int b ; } ; 


void solve() {

    int x , y , k ; cin >> x >> y >> k ; 
    int GCD = gcd(x , y) ; 
    int xx = x /= GCD , yy = y /= GCD ; 
    // x 和 y 现在一定是 互质的
    // 如果 x 和 y 任意一个数是质数那么是不可以的
    
    int lim = max(xx , yy) ; 
    vector<int> dp(lim + 1) ; dp[1] = 1 ; 
    for ( int i = 1 ; i <= k ; i ++ ) {
        for ( int j = (lim + i - 1) / i ; j > 0 ; j -- ) if ( dp[i] && dp[j] && j * i <= lim) {
            dp[j * i] = min(dp[j * i] , dp[j] + dp[i]) ; 
        }
    }

    if ( !dp[xx] || !dp[yy] ) {
        cout << -1 << endl ; 
        return ; 
    } else {
        dp[1] = 1 ; 
        cout << dp[xx] + dp[yy] << endl ; 
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


