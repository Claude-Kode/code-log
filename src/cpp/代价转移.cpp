// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e3 ; 

vector<vector<int>> grid ; 

void solve() {
    
    int a , b , pls , sub , mul ; cin >> a >> b >> pls >> sub >> mul ;    
    
    vector<int> dp( maxn , INT_MAX ) ; 
    dp[a] = 0 ; 
    for ( int i = a ; i <= b ; i ++ ) {
        dp[i] = min({ dp[i] , dp[i + 1] + sub , dp[i - 1] + pls }) ; 
        if ( i / 2 * 2 == i ) dp[i] = min( dp[i] , dp[i / 2] + mul ) ; 
    }

    cout << dp[b] << endl ;

}

signed main() {


    std :: ios :: sync_with_stdio(false) ; std :: cin.tie(nullptr) ; std :: cout.tie(nullptr) ;

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

