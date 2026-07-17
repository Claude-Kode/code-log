// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int a , b , c ; cin >> a >> b >> c ; 
    int mn = min({a, b, c}) ;
    a -= mn , b -= mn , c -= mn ;
    if ( a > 1 || b > 1 || c > 1 ) cout << "NO" << endl  ;
    else cout << "YES" << endl  ;
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


