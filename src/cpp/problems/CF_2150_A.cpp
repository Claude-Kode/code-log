// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int n , m ; cin >> n >> m ;
    string op ; cin >> op ; 
    set<int> arr ; 
    for ( int i = 1 ; i <= m ; i ++ ) {
        int temp ; cin >> temp ; 
        arr.insert( temp ) ; 
    }

    int p = 1 ; 
    for ( auto c : op ) {
        p ++ ; 
        if ( c == 'B' ) {

        }
        arr.insert( p ) ;
        if ( c == 'B' ) {

        }
    }    

    cout << arr.size() << endl ; 
    for ( auto &a : arr ) cout << a << ' ' ; 
    cout << endl ; 

}

/*
这题我就是想不到这个 1 -> i 操作怎么从 1 -> i-1 推过来
*/

signed main() {


    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
    
*/

