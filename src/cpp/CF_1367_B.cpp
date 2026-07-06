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
    int odd = 0 , eve = 0 ; 
    vector<int> arr( n ) ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> arr[i] ; 
        odd += arr[i] & 1 ; 
        eve += !(arr[i] & 1) ; 
    } 

    int t1 = n / 2 , t2 = n - t1 ; 
    if ( t1 != odd || t2 != eve ) {
        cout << -1 << endl ; 
        return ; 
    }

    int ans = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        ans += (arr[i] & 1) != (i & 1) ;
    } 

    cout << ans / 2 << endl ; 
    
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


