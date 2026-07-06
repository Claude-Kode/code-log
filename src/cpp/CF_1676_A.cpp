// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int cal(char c) { return (c - '0') ; }

void solve() {

    string str ; cin >> str ; 
    int a , b ; 
    a = cal(str[0]) + cal(str[1]) + cal(str[2]) ; 
    b = cal(str[3]) + cal(str[4]) + cal(str[5]) ; 
    
    if ( a == b) cout << "YES" << endl ; 
    else cout << "NO" << endl ;  

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