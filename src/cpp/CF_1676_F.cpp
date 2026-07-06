// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , k ; cin >> n >> k ; 
    vector<int> temp ;
    vector<int> arr(n + 1) ; 
    map<int, int> ump  ;
    for ( int i = 1; i  <= n ; i ++ ) {
        cin >> arr[i] ; 
        ump[arr[i]] ++ ; 
    } 

    for ( auto &[val , cnt] : ump) {
        if( cnt >= k ) temp.push_back( val ) ; 
    }

    if ( temp.empty() ) {
        cout << -1 << endl ;
        return ; 
    }

    int nn = temp.size() ; int ans = 1 , cont = 1 , l = 0 , r = 0 ;
    int ll = temp[0] , rr = temp[0] ; 
    for ( int i = 1 ; i < nn ; i ++ ) {
        if ( temp[i] == temp[i - 1] + 1 ) {
            cont ++ ; 
            if ( cont == 2 ) l = i  - 1;
            r = i  ; 
        } else {
            cont = 1 ; 
        }
        
        if ( ans < cont ) {
            ll = temp[l] ; rr = temp[r] ;ans = cont ;
        }

    }

    cout << ll << ' ' << rr << endl ; 
    
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