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
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }

    auto check = [&](int x) -> bool {

        int cur = x ; 
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( cur < arr[i] ) cur -- ; 
            else if ( cur > arr[i] ) cur ++; 
        }

        // cout << x << ' ' << cur << endl ; 

        return cur > x ;
    } ; 
    
    int l = 0 , r = 1e9 , ans = 0 ;
    while ( l <= r ) {
        int mid = (l + r) / 2 ;
        if (check(mid)) { r = mid - 1 ; ans = mid ; }
        else { l = mid + 1 ; }
    } 
 
    cout << ans << endl ; 

}

/*
错误理解了题意啊  战斗的顺序是不能变的
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