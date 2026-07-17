// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int n , m ; 

void p(int x , int y , int d , vector<vector<int>> &sum ) {
    for( int i = 1 ; i <= n ; i ++ ) {
        int nx = i , ny = i + (y - x) ; 
        if ( ny > m ) break ;
        if ( ny < 1 ) continue ; 
        sum[nx][ny] += d ; 
    }


    for( int j = 1 ; j <= m ; j ++ ) {
        int nx = x + y - j , ny = j ; 
        if ( nx > n ) continue ; 
        if ( nx < 1 ) break ; 
        // cout << nx << ' ' << ny << endl ; 
        sum[nx][ny] += d ; 
    }
    
    // cout << endl ; 

    sum[x][y] -= d ; 

}

void solve() {

    cin >> n >> m ; 
    vector<vector<int>> grid(n + 1 , vector<int>(m + 1)) , sum(n + 1 , vector<int>(m + 1)); 
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            cin >> grid[i][j] ; 
            p(i , j , grid[i][j] , sum) ; 
        }
    }
    
    int mx = INT_MIN ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            mx = max( mx , sum[i][j] ) ; 
        }
    }

    cout << mx << endl ; 

    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     for ( int j = 1 ; j <= m ; j ++ ) {
    //         cout << sum[i][j] << ' ' ; 
    //     }
    //     cout << endl ; 
    // }

    // int cnt = 0 ; 
    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     for ( int j = 1 ; j <= m ; j ++ ) {
    //         cnt += (mx == sum[i][j]) ; 
    //     }
    // }

    // cout << cnt << endl ; 

}

/*

*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}