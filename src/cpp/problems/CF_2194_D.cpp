// @Author : GoryK 
#include <bits/stdc++.h> 
using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;

void solve() {
    int n , m ; cin >> n >> m ;
    
    int sum = 0 ;
    vector<vector<int>> a(n + 10, vector<int>(m + 10)) ;
    vector<vector<int>> b(n + 10, vector<int>(m + 10)) ;
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            cin >> a[i][j] ;
            sum += a[i][j] ;
        }
    }
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = m ; j > 0 ; j -- ) {
            b[i][j] = b[i][j + 1] + a[i][j] ;
        }
    }
    
    int x = sum / 2 ;
    int ans = x * (sum - x) ;  
    cout << ans << endl ;
     
    int ans1 = 1 , ans2 = 1 ;
    
    // 找到最后一行
    for ( int i = 1; i <= n ; i ++ ) {
        if (x < b[i][1]) {
            ans1 = i ; 
            break ;    
        } 
        x -= b[i][1] ;   
    }

    if (x == 0) {
        ans2 = 1 ;  
    } else {
        for ( int i = 1 ; i <= m ; i ++ ) {
            if (b[ans1][i] == x) {
                ans2 = i ;
                break ;
            }
        }
    }
    
    for ( int i = 1 ; i < ans1 ; i ++ ) {
        cout << 'D';
    }
    for ( int i = 1 ; i < ans2 ; i ++ ) {
        cout << 'R' ;  // 这里应该是R不是D
    }
    
    if (x > 0) {
        cout << 'D' ;
    } else {
        ans1 -- ;
    }
    
    for ( int i = ans2 ; i <= m ; i ++ ) {
        cout << 'R' ;
    }
    for ( int i = ans1 + 1 ; i <= n ; i ++ ) {
        cout << 'D' ;
    }
    cout << endl ;
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            a[i][j] = b[i][j] = 0 ;
        }
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
