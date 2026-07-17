// @Author : GoryK 
#include <bits/stdc++.h> 
using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 


void solve() {

    int n , a , b ; cin >> n >> a >> b ; 
    
    int lim = (n + a + b - 1) / (a + b) ; 
    for( int i = )

    int l = 0 , r = (n + a + b - 1) / (a + b) , ans = -1 ;
    while( l <= r ) {
        int mid = (l + r) / 2 ; 
        if ( check(mid) ) l = mid + 1 , ans = mid ; 
        else r = mid - 1 ; 
    }

    if ( ans == -1 ) cout << "NO" << endl ; 
    else {

    }

}
    
    
signed main() {

    std::ios::sync_with_stdio(false) ; 
    std::cin.tie(nullptr) ; 
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen( "INPUT.txt" , "r" , stdin ) ; 
        freopen( "OUTPUT.txt" , "w" , stdout ) ; 
    #endif

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ;      
}   

