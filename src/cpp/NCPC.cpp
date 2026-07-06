// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int n , mx = INT_MIN ; cin >> n ; 
    vector<int> vec(n + 1) ; 
    unordered_map<int, int> mp ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
       cin >> vec[i] ; 
       mp[vec[i]] ++ ; 
       mx = max(mx , vec[i]) ;
    }

    if ( !(mp[mx] & 1) ) {
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( vec[i] != mx ) {
                cout << 1 ;
            } else {
                cout << 0 ;
            }
        }
    } else {
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( vec[i] == mx ) {
                cout << 1 ;
            } else {
                cout << 0 ;
            }
        }
    }

    cout << endl ; 

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

