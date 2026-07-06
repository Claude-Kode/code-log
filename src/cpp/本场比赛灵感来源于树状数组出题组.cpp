// @Author : GoryK 
#include <bits/stdc++.h> 
using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 1e3 + 10 ; 


void solve() {

    int n ; cin >> n ; 
    vector<int> vec(n + 1), buckle(1001, 0) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ; 
        buckle[vec[i]] ++ ; 
    }

    for ( int i = 1 ; i <= 1000 ; i ++ ) {
        buckle[i] += buckle[i - 1] ; 
    }
    
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        int pre = buckle[vec[i]] - 1 ; 
        int base = n - 1 ; 
        ans += (5 * pre >= 4 * base) * vec[i] ; 
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

    solve() ; 

    return 0 ;      
}   

