// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    string str1 , str2 ; cin >> str1 >> str2 ; 
    int ans = 0 ; 
    int n = str1.size() , m = str2.size() ; 
ans = n + m ;
    n = min(n , m) ; 
    int free = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( str1[i] == str2[i] ) free ++; 
        else break ; 
    }
    
    if (free > 1) ans -= free - 1 ; 
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

    // cout << fixed << setprecision(6) ;

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}

