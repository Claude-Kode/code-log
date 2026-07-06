// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998244353 ; 
const int maxn = 2e5 + 10 ;

int n ; 
set<string> st ; 
void DFS(string s , int step) {
    if (step == n + 1) {
        st.insert(s) ; return ; 
    }
    DFS( s + "0" , step + 1) ; 
    DFS( s + "1" , step + 1) ; 
    DFS( s + "01" , step + 1) ; 
    DFS( s , step + 1) ; 
}

void solve() {

    int n ; cin >> n ; 
    vector<int> dp(n + 1 ) ; 
    dp[0] = 1 ; dp[1] = 4 ;  
    for ( int i = 2 ; i <= n ; i ++ ) {
        dp[i] = (3 * dp[i - 1] - dp[i - 2] + 1 + mod ) % mod ; 
    }

    cout << dp[n] << endl ; 

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
    while (tt --) solve() ;
    
    return 0 ;
}

