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
    if ( n == 1 ) { cout << 0 << endl ; return ; } 

    int ans = (n - 1) / 5 * 6 ;
    switch ((n - 1) % 5) {
        case 1 : ans += 1 ; break ; 
        case 2 : ans += 2 ; break ; 
        case 3 : ans += 3 ; break ; 
        case 4 : ans += 5 ; break ; 
        default : break ; 
    }

    cout << ans << endl ;

}

/*

一开始是结构搞错了

应该是这样的
& | & & Z & & | H & & & & | & & Z & & | 
& | H & & & & | & & Z & & | H & & & & | 

这样的链节结构即可

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