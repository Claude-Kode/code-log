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

    vector<int> ans ; int l = 1 , r = n ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if (i & 1) {
            ans.push_back( arr[l++] ) ;
        } else {
            ans.push_back( arr[r--] ) ; 
        }
    }
    
    for ( int i = n - 1 ; i >= 0 ; i -- ) {
        cout << ans[i] << ' ' ;
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