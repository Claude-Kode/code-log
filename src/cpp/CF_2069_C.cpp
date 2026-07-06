// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998244353 ; 
const int maxn = 2e5 + 10 ;

void solve() {
    
    int n , temp ; cin >> n ;
    vector<int> dp(4 , 0) ; dp[0] = 1 ;
    while (n --) {
        cin >> temp ; 
        if (temp == 2) (dp[2] += dp[2]) %= mod ; 
        (dp[temp] += dp[temp- 1]) %= mod ; 
    }

    cout << dp[3] << endl ;

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
