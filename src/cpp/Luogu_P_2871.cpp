// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , m ; cin >> n >> m ; 
    vector<pair<int, int>> vec(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i].first >> vec[i].second ; 
    } 

    vector<int> dp(m + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        int t = vec[i].first , v = vec[i].second ;
        for ( int j = m - t ; j >= 0 ; j -- ) {
            dp[j + t] = max(dp[j + t] , dp[j] + v) ;
        }
    } 

    // for( int i = 1 ; i <= m ; i ++ ) if ( dp[i] ) {
    //     cout << i << ' ' << dp[i] << endl ;
    // }

    cout << *max_element(dp.begin() , dp.end()) << endl ; 

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