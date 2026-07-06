// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int dirs[4][2] = {{1, 0}, {-1, 0} , {0, 1} , {0, -1}} ; 

void solve() {

    int n , m ; cin >> n >> m ; 
    unordered_set<int> buckle(n * m + 1) ; 
    vector<vector<int>> vec(n + 1 , vector<int>(m + 1)) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            cin >> vec[i][j] ; 
            buckle.insert(vec[i][j]) ; 
        }
    }

    if ( buckle.size() == 1 ) {
        cout << 0 << endl  ;
        return ; 
    }

    auto c = [&](int x , int y) -> bool {
        return x >= 1 && x <= n & y >= 1 && y <= m ;
    }  ; 

    unordered_set<int> ss ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            for ( auto &[xx , yy] : dirs) {
                int nx = i + xx , ny = j + yy ; 
                if ( c(nx , ny) && vec[nx][ny] == vec[i][j] ) {
                    ss.insert(vec[i][j]) ; 
                    vec[i][j] = 0 ; break ; 
                }
            }
        }
    }

    int ans = buckle.size() - 1 + ss.size() - (ss.size() > 0) ; 
    cout << ans << endl ; 

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
