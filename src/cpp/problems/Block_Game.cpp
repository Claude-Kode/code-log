// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int n , k ; cin >> n >> k ;
    queue<int> q ;
    vector<int> arr( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }

    for ( int i = n ; i > 0 ; i -- ) {
        q.push( arr[i] ) ;
    }

    n ++ ;
    int mx = INT_MIN ;
    while ( n -- ) {
        // cout << k << ' ' ;
        // cout << k + q.back() << ' ' ;
        mx = max( mx , k + q.back() ) ;
        q.push( k ) ; 
        k = q.front() ; q.pop() ; 
    }
    // cout << endl ; 
    
    cout << mx << endl ; 

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