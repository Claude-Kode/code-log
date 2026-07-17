// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ;
    vector<int> vec(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ;
    }
    
    vector<int> num(n + 1) ; 
    iota(num.begin() + 1 , num.end() , 1LL) ; 
    sort(num.begin() + 1 , num.end() , [&](int a , int b) {
        if ( vec[a] != vec[b] ) return vec[a] > vec[b] ; 
        else return a > b ; 
    }) ;
    
    int mn = INT_MAX , ans = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) if ( mn > num[i] ) {
        mn = num[i] , ans ++ ; 
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

    // cout << fixed << setprecision(6) ;

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}

