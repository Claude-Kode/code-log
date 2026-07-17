// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int x ; cin >> x ; 
    int lim = sqrt( x ) ; 
    for ( int i = 1 ; i <= lim ; i ++ ) {
        if ( i * (i + 1) == x ) { cout << "YES" << endl ;return ; }
    }

    cout << "NO" << endl ;

}

/*

*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    
solve() ; 


    return 0 ; 
}   

/*
    
*/


// int money = 100 ; 
// while (1) if ( 京爷 ) {
//     money ++ ;
// }
// bool 京爷 = false ; 