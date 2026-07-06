// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int n , m ; cin >> n >> m ; 

    int suma = 0 , sumb = 0 ; 
    vector<int> a(n + 1) , b(m + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> a[i] , suma += a[i] ; 
    for ( int i = 1 ; i <= m ; i ++ ) cin >> b[i] , sumb += b[i] ; 

    if ( suma == sumb ) {
        cout << 1 << endl ; return ; 
    }

    sort( a.begin() + 1 , a.end() , greater<int>() ) ; 
    sort( b.begin() + 1 , b.end() , greater<int>() ) ; 

    if ( suma > sumb ) {

        for ( int i = 1 ; i <= n ; i ++ ) {
            suma -= a[i] ; 
            if ( suma <= sumb ) {
                cout << i << endl ; return ;
            }
        }

    } else {

        for ( int i = 1 ; i <= m ; i ++ ) {
            sumb -= b[i] ; 
            if ( sumb <= suma ) { cout << i << endl ; return ; }
        }

    }

}

/*

*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    
    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
    
*/


// int money = 100 ; 
// while (1) if ( 京爷 ) {
//     money ++ ;
// }
// bool 京爷 = false ; 