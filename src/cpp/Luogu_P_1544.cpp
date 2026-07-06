// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , kk ; cin >> n >> kk ; 
    vector<vector<int>> vec(n + 1 , vector<int>(n + 1)) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        for (int j = 1 ; j <= i ; j ++ ) {
            cin >> vec[i][j] ; 
        }
    }

    vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(n + 1 , vector<int>(kk + 1 , INT_MIN))) ;
    
    auto DFS = [&](this auto&& DFS , int i , int j , int k ) -> int {
        if ( i > n || i < 0 || j < 0 || j > n ) {
            return 0 ; 
        }

        if (dp[i][j][k] != -INT_MIN) return dp[i][j][k] ; 

        dp[i][j][k] = max({
            dp[i][j][k] , 
            DFS(i + 1 , j , k) + vec[i][j] ,
            DFS(i + 1 , j + 1 , k)+ vec[i][j] }) ;

        if ( k > 0 ) {
            dp[i][j][k] = max({
                dp[i][j][k] , 
                DFS(i + 1 , j , k - 1) + vec[i][j] * 3 ,
                DFS(i + 1 , j + 1 , k - 1) + vec[i][j] * 3 }) ; 
        }

        // cout << i << ' ' << j << ' ' << k << endl ; 
        // cout << dp[i][j][k] << endl ; 

        return dp[i][j][k] ;

    } ;
    
    cout << DFS(1 , 1 , kk) << endl ; 


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
