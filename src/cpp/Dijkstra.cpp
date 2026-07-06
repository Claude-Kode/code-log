// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void Dijkstra(int sx , int sy , int tx , int ty , vector<vector<pair<int, int>>>& adj) {

    struct tup {int x ; int y ; int w ;
        bool operator< ( tup other ) const {
            return w < other.w ; 
        } 
    } ;
    priority_queue<tup> pq ; 
    
    auto cal = [&](int x , int y , int tx , int ty ) -> int {
        return abs(x - tx) + abs(y - ty) ; 
    } ;     

    

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

    // cout << fixed << setprecision(6) ;

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}

