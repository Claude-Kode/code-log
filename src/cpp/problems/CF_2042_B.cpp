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
    unordered_map<int, int> ump ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> vec[i] , ump[vec[i]] ++ ; 

    int s = 0 , m = 0 ; 
    for (const auto& [v , c] : ump) {
        c == 1 ? s ++ : m ++ ; 
    }

    int ans = (s + 1) / 2 * 2 + m ; 
    
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

