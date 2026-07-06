// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int n ; cin >> n ;
    int ans = ( n + 1 ) / 2 ;
    cout << ans << ' ' ; 
    for ( int i = 1 ; i <= n - 1 ; i ++ ) {
        if ( i & 1 ) ans += i ;
        else ans -= i ;
        cout << ans << ' ' ; 
    }

    cout << endl ; 

}

signed main() {


    std :: ios :: sync_with_stdio(false) ; std :: cin.tie(nullptr) ; std :: cout.tie(nullptr) ;

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

