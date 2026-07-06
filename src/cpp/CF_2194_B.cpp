// @Author : GoryK 
#include <bits/stdc++.h> 
using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 


void solve() {

    int n , x , y ; cin >> n >> x >> y ; 
    vector<int> arr( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ; 
    auto money = arr ; 
    int sum = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        money[i] = money[i] / x * x - money[i] / x * (x - y) ; 
        sum += money[i] ; 
    }

    int ans = INT_MIN ; 
    for( int i = 1 ; i <= n ; i ++ ) {
        ans = max( ans , sum - money[i] + arr[i] ) ;
    }

    cout << ans << endl ;
    
}
    
    
signed main() {

    std::ios::sync_with_stdio(false) ; 
    std::cin.tie(nullptr) ; 
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen( "INPUT.out" , "r" , stdin ) ; 
        freopen( "OUTPUT.out" , "w" , stdout ) ; 
    #endif

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ;      
}   

