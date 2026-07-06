// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998244353 ; 
const int maxn = 2e5 + 10 ;

int fp(int x , int p) {
    int base = x , res = 1 ; 
    while ( p ) {
        if ( p & 1 ) res = res * base % mod ;
        base = base * base % mod ; 
        p >>= 1 ; 
    }
    return res % mod ; 
}

void solve() {

    int n , m ; cin >> n >> m ; 

    vector<int> l(n + 1), r(n + 1), p(n + 1), q(n + 1), pp(n + 1) ; 
    int ans = 1 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> l[i] >> r[i] >> p[i] >> q[i] ; 
        int invq = fp(q[i] , mod - 2) ; 
        pp[i] = invq * p[i] % mod ; 
        
        ans = ( ans * fp(pp[i], r[i] - l[i] + 1) ) % mod ; 
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