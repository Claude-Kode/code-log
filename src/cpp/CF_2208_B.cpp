// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , k , p , m ; cin >> n >> k >> p >> m ; 
    vector<int> vec(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ; 
    }  

    int cost = vec[p] ; vec[p] = -1 ;
    
    deque<int> dq ;
    priority_queue<int , vector<int> , greater<int>> pq ;

    for ( int i = k + 1 ; i <= n ; i ++ ) dq.push_back( vec[i] ) ;
    for ( int i = 1 ; i <= k ; i ++ ) pq.push( vec[i] ) ;

    int ans = 0 ;
    while ( m >= pq.top() ) {

        if ( pq.top() == -1  ) {
            if ( m >= cost ) {
                ans ++ ; m -= cost ;
            } else break ; 
        } else {
            m -= pq.top() ; 
        }

        dq.push_back(pq.top()) ; pq.pop() ; 
        pq.push(dq.front()) ; dq.pop_front() ;
        
    }

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
