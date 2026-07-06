// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

vector<int> mp = {0, 6, 5, 4, 3, 2, 1} ;

void solve() {

    int n ; cin >> n ; 
    vector<int> arr(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }

    int ans = 0 ;
    for ( int i = 1 ; i < n ; i ++ ) {
        if ( arr[i + 1] == mp[arr[i]] || arr[i + 1] == arr[i] ) ans ++ ; 
    }

    cout << ans << endl ; 

}

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
    
    return 0;
}