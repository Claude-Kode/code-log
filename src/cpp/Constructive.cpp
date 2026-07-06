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
    int mul = 1 , sum = 0 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        sum += i ;
        mul *= i ; 
    }
     
    if ( sum == mul ) {
        cout << "YES" << endl ; 
        for ( int i = 1 ; i <= n ; i++ ) cout << i << ' ' ;
        cout << endl ;
    } else {
        cout << "NO" << endl ; 
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