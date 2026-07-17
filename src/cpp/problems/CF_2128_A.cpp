// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , c ; cin >> n >> c ; 
    vector<int> arr(n + 1) ; vector<int>  vals ;  
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
        if ( arr[i] <= c ) vals.push_back( arr[i] ) ; 
    }

    sort( vals.rbegin() , vals.rend() ) ;
    int used = 0 , p = 1 ; 
    for ( const auto &a : vals ) {
        if ( a * p <= c ) {
            used ++ ; 
            p *= 2 ; 
        }
    }

    cout << n - used  << endl ; 

    // cout << n - used << endl ; 

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

