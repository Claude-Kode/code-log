// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , sum = 0 ; cin >> n ; 
    vector<int> vec(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ; 
    }

    sum = accumulate(vec.begin() , vec.end() , 0LL) ; 

    vector<int> dp(sum + 1) ; dp[0] = 1 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        int w = vec[i] ; 
        for ( int j = sum ; j >= 0 ; j -- ) {
            if (w + j <= sum) {
                dp[w + j] += dp[j] ; 
                if (dp[j]) cout << j << ' ' << w << ' ' << j + w << endl ; 
            }
            if (j - w >=  0 ) {
                dp[j - w] += dp[j] ;
                if (dp[j]) cout << j << ' ' << w << ' ' << j - w << endl ; 
            }
        }
    }

    int cnt = 0 ;
    for ( int i = 1 ; i <= sum ; i ++ ) {             
        cnt += (dp[i] != 0) ; 
    }

    cout << cnt << endl ; 

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

    solve() ;
    
    return 0 ;
}