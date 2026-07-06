// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int xa , ya , xb , yb ;
    cin >> xa >> ya >> xb >> yb ;
    
    int c = xa * yb - xb * ya ; 
    int d = ya - yb ;
    
    if ( !d ) {
        if ( abs(c) - 4 <= 1e-4 ) cout << 0 << endl  ;
        else cout << "no answer" << endl ;
    } else {
        double x = (4 * 1.0 - c) / d ;
        cout << x << endl ;     
    }

}

/*

三角形面积就是 1/2 * ab(v) * ac(v) 就是这样的
*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    cout << fixed << setprecision(8) ;

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
