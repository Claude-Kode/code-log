// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ;
    vector<int> arr(n + 1) , ans(n + 1) ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }

    int mn = INT_MAX , temp = 0 ; 
    for(int i = 1 ; i <= n - 1 ; i ++ ) {
        ans[i] = temp + min(mn , arr[i] + arr[i + 1]) ; 
        mn = min(mn , arr[i]) ;
        temp += mn ; 
    }   temp += min( mn , arr[n] ) ;

    int res = temp ; 
    for ( int i = 1 ; i <= n - 1 ; i ++ ) {
        res = min( res , ans[i] ) ; 
    }

    cout << res << endl ; 

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