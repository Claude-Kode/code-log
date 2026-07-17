// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ,k ; cin >> n >> k ;
    vector<int> vec(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ; 
    }  
    
    sort(vec.begin() + 1 , vec.end() , greater<int>()) ; 
    auto pre = vec ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        pre[i] += pre[i - 1] ; 
    }

    auto it = lower_bound(pre.begin() + 1 , pre.end() , k) ;
    
    if ( it != pre.end() ) {
        if (*it == k) cout << 0 << endl ; 
        else cout << k - *(it - 1) << endl ; 
    } else cout << k - pre[n] << endl ; 

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

