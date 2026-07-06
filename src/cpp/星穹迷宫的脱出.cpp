// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int dirs[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} } ;

struct tup{int z ; int x ; int y ; } ; 
struct infor{int z ; int x ; int y ; int cost ; } ; 

void solve() {

    int l , n , m ; cin >> l >> n >> m ; 

    int sx , sy , sz , tx , ty , tz ; 
    unordered_map<char, vector<tup>> ump ; 
    vector<vector<vector<char>>> grid(l + 1 , vector<vector<char>>(n + 1 , vector<char>(m + 1))) ; 
    for ( int i = 1 ; i <= l ; i ++ ) {
        for (int j = 1 ; j <= n ; j ++ ) {
            for (int k = 1 ; k <= m ; k ++ ) {
                cin >> grid[i][j][k] ;
                if ( grid[i][j][k] >= 'A' && grid[i][j][k] <= 'Z' ) 
                    ump[grid[i][j][k]].push_back(tup{i , j ,k}) ; 
                if (grid[i][j][k] == '@') sx = j , sy = k , sz = i ; 
                if (grid[i][j][k] == '=') tx = j , ty = k , tz = i ; 
            }
        }
    }

    auto c = [&](int z , int x , int y ) -> bool {
        return z >= 1 && z <= l && x >= 1 && x <= n && y >= 1 && y <= m ;
    } ; 

    queue<infor> q ; q.push(infor{sz , sx , sy , 0}) ; 
    while ( !q.empty() ) {
        auto [z , x , y , c] = q.front() ; q.pop() ; 

        if ( z == tz && x == tx && y == ty ) {
            cout << c << endl ;
            return ; 
        }

        if ( !ump[grid[z][x][y]].empty() ) {
            tup temp = {z , x , y} ; 
            if ( temp == ump[grid[z][x][y]][0] )  ;
            else z = ;
        }
        
        for (auto [dx , dy] : dirs) {
            int nx = x + dx , ny = y + dy , nc = c + 1 ; 
            if ( c(z , x , y) ) {
                q.push(tup{z , nx , ny , nc}) ; 
            }
        }
    }
    

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
