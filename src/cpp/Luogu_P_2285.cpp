// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

struct infor { int x ; int y ; int t ; } ; 

void solve() {

    int n , m ; cin >> n >> m ; 
    vector<infor> vec(m + 1) ; 
    for ( int i = 1 ; i <= m ; i ++ ) {
        int tt , xx , yy ; cin >> vec[i].t >> vec[i].x >> vec[i].y ; 
    } 

    vector<int> dp(m + 1 , 1) ; 
    for ( int i = 2 ; i <= m ; i ++ ) {
        for (int j = 1 ; j < i ; j ++ ) {
            int dis = abs(vec[i].x - vec[j].x) + abs(vec[i].y - vec[j].y) ,
                tim = vec[i].t - vec[j].t ;
            // if ( dis <= tim ) cout << "nmsl" << endl ;
            if ( dis <= tim ) dp[i] = max(dp[i] , dp[j] + 1) ; 
            
        } 
        
    }

    // int ans = INT_MIN ; 
    // for ( int i = 1 ; i <= m ; i ++ )  ans = max(ans , dp[i]) ;

    cout << *max_element(dp.begin() , dp.end()) << endl ; 

}

/*
就是我发现 dp 有一个换一种方式进行枚举的办法
*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif
    
    solve() ;
    
    return 0 ;
}