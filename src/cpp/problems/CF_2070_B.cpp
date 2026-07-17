// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , x , k ; cin >> n >> x >> k ; 
    string op ; cin >> op ; 
    vector<int> pre(n + 1)  ;

    int pos = 0 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( op[i - 1] == 'L' ) 
            pre[i] = pre[i - 1] - 1 ; 
        else 
            pre[i] = pre[i - 1] + 1 ; 
        
    }

    int posx = LLONG_MAX , pos0 = LLONG_MAX ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( pre[i] == -x ) {
            posx = i ;
            break ; 
        }
    }

    if ( k < posx ) {
        cout << 0 << endl ; 
        return ; 
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( pre[i] == 0 ) {
            pos0 = i ;
            break ; 
        }
    }


    int ans = 0 ; 
    if ( k >= posx ) ans ++ ;
    k -= posx ;
    if ( k > 0 ) ans += k / pos0 ;

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

