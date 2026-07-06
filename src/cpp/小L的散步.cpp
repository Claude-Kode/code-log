// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , m , len ; cin >> n >> m >> len ; 
    vector<int> stones(n + 1) , feets(m + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> stones[i] , stones[i] += stones[i - 1] ; 
    for ( int i = 1 ; i <= m ; i ++ ) cin >> feets[i] ;

    vector<int> l(m + 1) , r(m + 1) ; l[0] = 0 , r[0] = len ;
    for ( int i = 1 ; i <= m ; i ++ ) {
        l[i] = l[i - 1] + feets[i] ; 
        r[i] = r[i - 1] + feets[i] ; 
    }
     
    int p1 = 1 , p2 = 0 ; 
    while ( p1 <= n && p2  <= m ) {
        if ( stones[p1] < r[p2] && stones[p1] > l[p2] ) {
            cout << "YES" << endl ; return ; 
        }
        if ( stones[p1] >= r[p2] ) p2 ++ ; 
        if ( stones[p1] <= l[p2] ) p1 ++ ; 
    }

    cout << "NO" << endl ; 

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

    solve() ;
    
    return 0 ;
}