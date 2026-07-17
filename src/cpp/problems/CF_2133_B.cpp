// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ;cin >> n ; 
    vector<int> vec(n + 1) ;
    priority_queue<int> pq ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ; pq.push( vec[i] ) ;
    } 

    int cost = 0 ;
    while (pq.size() >= 2) {
        int a = pq.top() ; pq.pop() ; 
        int b = pq.top() ; pq.pop() ; 

        cost += max(a , b) ; 

        pq.push( 0 ) ; 

    }

    cout << cost << endl ; 

    // 核心在于通过交易变小脾

    
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