// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int fp(int x , int p) {
    int res = 1 , base = x ;
    while (p) {
        if ( p & 1 ) (res *= base) %= mod ; 
        (base *= base) %= mod ; 
        p >>= 1 ; 
    }
    return res ;
}

void solve() {

    int n ; cin >> n ; 
    vector<int> nn(n + 1) , kk(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> nn[i] ; 
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> kk[i] ; 
    }

    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     if ( kk[i] > nn[i] ) {
    //         cout << 0 << endl ; 
    //     } else if (nn[i] == kk[i] ) cout << 1 << endl ; 
    //     else cout << fp(2 , kk[i]) << endl ; 
    // }




    vector<vector<int>> f(100 , vector<int>(100 , 0)) ; 
    n = 10 ; 
    for (int i = 0; i< n ; i ++) { // loop over n from 0 to N-1 (inclusive)
        f[i][0] = 1;
        f[i][i] = 1;
        for (int k = 1; k < i ; k++) // loop over k from 1 to n-1 (inclusive)
            f[i][k] = (f[i][k - 1] % mod + f[i - 1][k - 1] % mod ) % mod  ;
    }

    for ( int i = 1 ; i <= 10 ; i ++ ) {
        for ( int j = 1 ; j <= 10 ; j ++ ) {
            cout << f[i][j] << ' ' ; 
        }
        cout << endl  ;
    }

    // int mxn = *max_element(nn.begin() + 1 , nn.end()) , mxk = *max_element(kk.begin() + 1 , kk.end()) ; 
    // for (int i = 0; i< n ; i ++) { // loop over n from 0 to N-1 (inclusive)
    //     f[i][0] = 1;
    //     f[i][i] = 1;
    //     for (int k = 1; k < i ; k++) // loop over k from 1 to n-1 (inclusive)
    //         f[i][k] = (f[i][k - 1] % mod + f[i - 1][k - 1] % mod ) % mod  ;
    // }

    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     cout << f[nn[i]][kk[i]] << endl ;
    // }

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

    solve() ;
    
    return 0 ;
}

