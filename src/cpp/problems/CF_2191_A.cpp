// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

struct infor { int val ; int color ; } ; 

void solve() {

    int n ; cin >> n ;
    vector<infor> arr( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i].val ;
        arr[i].color = i & 1 ;  
    }

    sort( arr.begin() + 1 , arr.end() , [&]( auto &a , auto &b ) {
        return a.val < b.val ; 
    }) ; 

    for ( int i = 1 ; i < n ; i ++ ) {
        if ( arr[i].color == arr[i + 1].color) {
            cout << "No" << endl ; 
            return ; 
        }
     }

    cout << "yes" << endl ; 


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