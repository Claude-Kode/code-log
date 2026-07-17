// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int n ; 

int dirs[4][2] = {{1 , 0} , {-1 , 0}, {0 , -1} , {0 , 1}} ; 

vector<vector<int>> vis ;
vector<vector<int>> grid ;

bool turnRight( int x , int y , int delx , int dely ) {
    int nx = x + delx , ny = y + dely ;
    if ( nx > n || ny > n || nx < 1 || ny < 1 ) return true ; 
    if ( vis[x + dely][y + delx] ) return false ; 
    return true ; 

}

void solve() {

    cin >> n ;

    if ( n == 1 ) {
        cout << 0 << endl ; 
        vis.clear() ; grid.clear() ; 
        return ; 
    }

    vis.resize( n + 1 , vector<int>( n + 1 )) ; 
    grid.resize( n + 1 , vector<int>( n + 1 )) ;

    int nx , ny ;
    int x = (n + 1) / 2 , y = x ;
    int lx = x , ly = y ; 
    int delx , dely ; 
    int cnt = 2 ; 

    grid[x][++y] = 1 ; 
    grid[lx][ly] = 0 ; 
    vis[x][y] = 1 ; vis[lx][ly] = 1 ; 

    while ( cnt < n * n ) {


        delx = x - lx ; dely = y - ly ; 
        // cout << "nnx" << delx << ' ' << dely << endl ; 

        turnRight( x , y , delx , dely ) ? nx = x + dely , ny = y + delx : nx = x + delx , ny = y + delx ;
        // turnRight( x , y , delx , dely ) ? cout << "r" << ' ' : cout << "h" << ' ' ;
        // cout << "nx" << nx << " ny" << ny << endl ;  
        // cout << "x" << x << " y" << y << endl ; 
        // cout << "lx" << lx << " ly " << ly << endl ; 
        grid[nx][ny] = cnt ; vis[nx][ny] = 1 ;
        lx = x , ly = y ; 
        x = nx , y = ny ; 
        cnt ++ ; 
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= n ; j ++ ) {
            cout << grid[i][j] << ' ' ;  
        }
        cout << endl ;
    }    

    vis.clear() ; grid.clear() ; 

}

signed main() {


    std :: ios :: sync_with_stdio(false) ; std :: cin.tie(nullptr) ; std :: cout.tie(nullptr) ;

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

