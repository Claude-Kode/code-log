// @Author : GoryK 
#include <bits/stdc++.h> 
using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 


void solve() {

    int n , q , s ; cin >> n >> q >> s ; 
    vector<int> arr( n + 1 ) ; 
    for( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ; 

    vector<int> stt(n + 1) ; stt[1] = s ;
    for( int i = 2 ; i <= n ; i ++ ) {
        stt[i] = stt[i - 1] + arr[i - 1] ;
    }

    while ( q -- ) {
        int x , y ; cin >> x >> y ; 
        cout << stt[x] + y - 1 << endl ;
    } 

}
    
    
signed main() {

    std::ios::sync_with_stdio(false) ; 
    std::cin.tie(nullptr) ; 
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen( "INPUT.out" , "r" , stdin ) ; 
        freopen( "OUTPUT.out" , "w" , stdout ) ; 
    #endif

    solve() ; 

    return 0 ;      
}   

