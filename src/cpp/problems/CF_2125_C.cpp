// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int l , r ; cin >> l >> r ; 
    
    int ans = r - l + 1 ; 
    
    l -- ; 

    ans -= (r / 2 - l / 2) ; 
    ans -= (r / 3 - l / 3) ; 
    ans -= (r / 5 - l / 5) ; 
    ans -= (r / 7 - l / 7) ; 

    ans += (r / 6 - l / 6) ; 
    ans += (r / 10 - l / 10) ; 
    ans += (r / 14 - l / 14) ; 
    ans += (r / 15 - l / 15) ; 
    ans += (r / 21 - l / 21) ; 
    ans += (r / 35 - l / 35) ; 

    ans -= (r / 30 - l / 30) ; 
    ans -= (r / 42 - l / 42) ; 
    ans -= (r / 70 - l / 70) ; 
    ans -= (r / 105 - l / 105) ; 

    ans += (r / 210 - l / 210) ; 

    cout << ans << endl ;


}

/*
就是求 2 , 3 , 5 , 7 可以标记多少个数
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