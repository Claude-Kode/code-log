// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , k ; cin >> n >> k ; 
    if( n <= k) {
        cout << 1 << endl ; 
        return ; 
    }

    int ans = 1 ; n -= k ;
    if ((n & 1) && (k & 1)) {
        ans += (n + (k - 1) - 1) / (k - 1) ; 
    } else if ((n & 1) && !(k & 1)) {
        ans += (n + k - 1) / k ; 
    } else if (!(n & 1) && !(k & 1))  {
        ans += (n + k - 1) / k ; 
    } else {
        ans += (n + (k - 1) - 1) / (k - 1) ; 
    }
    
    cout << ans << endl ;
}

/*
odd - odd == even
even - even == even
your biggest question is understand the q LOL

7 min

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