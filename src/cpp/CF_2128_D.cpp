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
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> arr[i]  ; 
    }

    

    vector<int> g(n + 1) ; int ans = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( arr[i] < arr[i - 1] ) g[i] = g[i - 1] + 1 ; 
        else g[i] = 1 ; 

        // cout << g[i] << ' '  ; 

        int pre = i - g[i] ; 
        ans += (pre * g[i] + (g[i] + 1) * g[i] / 2) * (n - i + 1) ; 

    }

    // cout << endl ; 

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

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}