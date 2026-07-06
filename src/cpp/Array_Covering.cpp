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
    vector<int> vec(n + 1) ; 

    int mx = 0 ; 
    for( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ; 
    }

    for( int i = 2 ; i <= n - 1 ; i ++ ) {
        mx = max( mx , vec[i] ) ;
    }

    mx = max({mx , vec[1] , vec[n] }) ;

    cout << (n - 2) * mx + vec[1] + vec[n] << endl ;

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