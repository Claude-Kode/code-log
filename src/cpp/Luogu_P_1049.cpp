// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int v , n ; cin >> v >> n ; 
    vector<int> dp(v + 1) , vec(n + 1) ; dp[0] = 1 ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> vec[i] ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        // j represent the target w
        int w = vec[i] ;
        for ( int j = v - w ; j >= 0 ; j -- ) if (dp[j] ) {
            dp[j + w] = 1 ;
        }
    }

    for ( int i = v ; i > 0 ; i -- ) if (dp[i]) {
        cout << v - i ; return ;
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

    solve() ;
    
    return 0 ;
}