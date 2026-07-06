// @Author : GoryK 
#include <bits/stdc++.h> 
using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int n , m , q ; 
int ans = INT_MIN ; int mxx = 0 , mxy = 0 ;

int dirs[13][2] = {
    {0 , 0} , {-1 , 0} , {-2 , 0} , {1 , 0} , {2 , 0} ,
    {0 , -1} , {0 , -2} , {0 , 1} , {0 , 2} ,
    {1 , 1} , {1 , -1} , {-1 , 1} , {-1 , -1} ,
} ;

bool check(int x , int y) { return x > 0 && x <= n && y > 0 && y <= m ; }

void inc(int val , int x , int y , vector<vector<int>>& grid) {
    for ( auto &[xx , yy] : dirs ) {
        int nx = x + xx ; 
        int ny = y + yy ; 
        if ( check(nx , ny)) grid[nx][ny] += val ; 
    }
}

void upd(int x , int y , vector<vector<int>>& grid) {
    for ( auto &[xx , yy] : dirs ) {
        int nx = x + xx ; 
        int ny = y + yy ; 
        if ( check(nx , ny) && ans < grid[nx][ny] ) {
            ans = grid[nx][ny] ; 
            mxx = nx , mxy = ny ; 
        } 
    }
}

void solve() {

    cin >> n >> m >> q ; 
    vector<vector<int>> arr(n + 1 , vector<int>(m + 1)) ; 
    vector<vector<int>> grid(n + 1 , vector<int>(m + 1)) ; 
    for( int i = 1 ; i <= n ; i ++ ) {
        for( int j = 1 ; j <= m ; j ++ ) {
            cin >> arr[i][j] ; 
            inc(arr[i][j] , i , j , grid) ; 
        }
    } 

    for( int i = 1 ; i <= n ; i ++ ) {
        for( int j = 1 ; j <= m ; j ++ ) if ( ans < grid[i][j] ){
            ans = grid[i][j] ; 
            mxx = i , mxy = j ;
        }
    }

    // for( int i = 1 ; i <= n ; i ++ ) {
    //     for( int j = 1 ; j <= n ; j ++ ) {
    //         cout << grid[i][j] << ' ' ;
    //     }
    //     cout << endl ; 
    // }

    while (q -- ) {
        int x , y , z ; cin >> x >> y >> z ; 
        inc(z , x , y , grid) ; 
        upd(x , y , grid) ; 

        cout << mxx << ' ' << mxy << endl ; 
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

