// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , x , y ; cin >> n >> x >> y ; 
    vector<int> vec(n + 1) ;
    for (int i = 1 ; i <= n ; i ++ ) cin >> vec[i] ; 

    deque<int> dq1 , dq2 , dq3 ; 
    for ( int i = 1 ; i < x ; i ++ ) dq1.push_back( vec[i] ) ; 
    for ( int i = x ; i < y ; i ++ ) dq2.push_back( vec[i] ) ; 
    for ( int i = y ; i <= n ; i ++ ) dq3.push_back( vec[i] ) ; 

    while ( !dq1.empty() && dq1.back() > dq2.back()  ) {
        dq2.push_back(dq1.back()) ; 
        dq1.pop_back() ; 
    }

    while ( !dq1.empty() && dq3.front() < dq2.front() ) {
        dq1.push_back(dq3.front()) ; 
        dq2.pop_front() ; 
    }

    for ( const auto &a : dq1 ) cout << a << ' ' ;
    for ( const auto &a : dq2 ) cout << a << ' ' ;
    for ( const auto &a : dq3 ) cout << a << ' ' ;

    cout << endl ; 

    // while ( dq2.front())

}

/*
这应该是个模拟题 
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

