// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int a, b; cin >> a >> b; 
    int aa = min(a , b) , bb = max(a, b);

    int cnt1 = 0, val = 1;
    while (1){
        if (!(cnt1 & 1)) {
            if ( aa >= val ) aa -= val, cnt1 ++ ;
            else break ;
        } else {
            if (bb >= val)  bb -= val, cnt1 ++ ;
            else break ;
        }
        val <<= 1; 
    }

    int cnt2 = 0; val = 1;
    aa = min(a ,b) , bb = max(a, b);
    while (1){                       
        if (!(cnt2 & 1)) {
            if ( bb >= val ) bb -= val, cnt2 ++ ;
            else break ;
        } else {
            if (aa>= val)  aa -= val, cnt2 ++ ;
            else break ;
        }
        val <<= 1; 
    }


    cout << max(cnt1 , cnt2) << endl ; 
    
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