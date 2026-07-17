// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> a(n + 1) , b(n + 1) ; 
    for ( int i = 1 ;i  <= n ; i ++ ) cin >> a[i] ; 
    for ( int i = 1 ;i  <= n ; i ++ ) cin >> b[i] ; 

    vector<vector<int>> dp(n + 1 , vector<int>(2049 , 0)) ; 
    dp[0][0] = 1 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 0 ; j <= n ; j ++ ) if (dp[i - 1][j]) {
            dp[i][j ^ b[i]] = 1 ;
            dp[i][max(0LL , j - a[i])] = 1 ;
        }
    }

    int ans = 0 ; 
    for ( int i = 0 ; i <= 2048 ; i ++ ) if (dp[n][i]) {
        ans = max(ans , i) ; 
    }

    cout << ans << endl ; 

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

    solve() ;
    
    return 0 ;
}