// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998'244'353 ; 
const int maxn = 2e5 + 10 ;

int fp( int x , int p ) {
    int base = x , res = 1 ;
    while ( p ) {
        if ( p & 1 ) res = ( res * base ) % mod ; 
        base = (base * base) % mod ;  
        p >>= 1 ; 
    }
    return res % mod ; 
}

void solve() {

    int n ; cin >> n ; 
    vector<int> arr(n + 1) , pre(n + 1); 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
        // pre[i] = arr[i] ; 
        // pre[i] += pre[i - 1] ; 
    }
    
    vector<int> dp(n + 1) ; dp[0] = 1 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        int curo = 0 , curs = 0 ;
        for ( int j = i ; j > 0 ; j -- ) {
            curo |= arr[j] ; 
            curs += arr[j] ; 
            if ( curo != curs ) break ; 
            dp[i] = (dp[i] + dp[j - 1]) % mod ; 
        }
    }  

    cout << dp[n] << endl ; 

}

/*

这里强调了 | 运算符号的优先级高于 + 号这是重点啊

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
