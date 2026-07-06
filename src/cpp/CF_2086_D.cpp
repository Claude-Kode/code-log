// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998244353 ; 
const int maxn = 2e5 + 10 ;

int fp(int x , int p) {
    int base = x , res = 1 ; 
    while ( p ) {
        if (p & 1) (res *= base) %= mod ; 
        (base *= base) %= mod ; 
        p >>= 1 ;
    }
    return res % mod ; 
}

int fac(int x) {
    int res = 1 ; 
    for (int i = 1 ; i <= x ; i ++ ) (res *= i) %= mod ;
    return res % mod ; 
}

void solve() {

    int n = 0 , inv = 1 ; 
    vector<int> fre(26 + 1) , suff (26 + 2), nums ; 
    for ( int i = 1 ; i <= 26 ; i ++ ) {
        cin >> fre[i] ; 
        suff[i] = fre[i] ;
        (inv *= fac(fre[i])) %= mod ; 
        if ( fre[i] != 0 ) {
            nums.push_back( fre[i] ) ; 
        }
    }

    n = std::accumulate(fre.begin() , fre.end() , 0LL) ;

    vector<int> dp(n + 1) ; dp[0] = 1 ; 
    for ( int i = 1 ; i <= 26 ; i ++ ) if ( fre[i]) {
        for ( int j = n ; j >= 0 ; j -- ) if ( j + fre[i] <= n ) {
            (dp[j + fre[i]] += dp[j]) %= mod ; 
        }
    }

    int odd = (n + 1) / 2 , even = n / 2 , cnt = dp[odd] ;

    cout << fac(odd) * fac(even) % mod * fp(inv , mod - 2) % mod * cnt % mod << endl ; 

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