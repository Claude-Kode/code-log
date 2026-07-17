// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , q ; cin >> n >> q ; 
    vector<int> arr(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i ] ; 
    }
    sort( arr.begin() + 1 , arr.end() , greater<int>()) ; 
    for ( int i = 1 ; i <= n ; i ++ ) arr[i] += arr[i - 1] ; 

    while(q -- ) {
        int val ; cin >> val ; 
        auto it = lower_bound(arr.begin() + 1 , arr.end() , val) ; 
        if ( it != arr.end() ) {
            cout << it - arr.begin() << endl ; 
        } else {
            cout << -1 << endl ; 
        }
    }

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