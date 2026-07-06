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
    for( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ;  
    }

    auto a = arr ; sort( a.begin() , a.end() ) ; 
    vector<int> ans ; 
    for( int i = 1 ; i <= n ; i ++ ) {
        if( a[i] == arr[i] ) continue ; 
        else ans.push_back( arr[i] ) ;
    }

    if ( ans.empty() ) {
        cout << "NO" << endl ; 
        return ; 
    } 

    cout << "YES" << endl << ans.size() << endl ; 
    for ( auto &a : ans ) {
        cout << a << ' ' ; 
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