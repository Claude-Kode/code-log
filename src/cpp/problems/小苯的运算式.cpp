// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> arr(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ;
    }

    // vector<vector<int>> dp(2 , vector<int>(n + 1)) ; 
    // dp[0][1] = arr[1] ; 
    int plus = 0 , minus = arr[1] ; 
    for ( int i = 2 ; i <= n ; i ++ ) {
        minus = max(minus , plus + arr[i]) ; 
        plus = max(plus , minus - arr[i]) ; 
    }
    
    cout << max(minus , plus) << endl ; 

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