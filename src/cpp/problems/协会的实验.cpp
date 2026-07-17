// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    string op ; cin >> op ;

    // 前端添加的时候 只有添加的是 a 的时候才能对 acm 产生贡献
    // 后端添加的时候 只有添加的是 m 的时候才能对 acm 产生贡献

    int sa = 0  , sc = 0 , sm = 0 , ac = 0 , cm = 0 , acm = 0 ;  

    for ( const auto &c : op ) {
        if ( c == 'a' ) {
            sa ++ ; acm += cm ; ac += sc ; 
        } else if ( c == 'A' ) {
            sa ++ ; 
        } else if ( c == 'c' ) {
            sc ++ ; cm += sm ;
        } else if ( c == 'C' ) {
            sc ++ ; ac += sa ; 
        } else if ( c == 'm' ) {
            sm ++ ; 
        } else {
            sm ++ ; cm += sc ; acm += ac ; 
        }
        acm %= mod ; 
        cout << acm << ' ' ; 
    }

    cout << endl ; 
    
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
