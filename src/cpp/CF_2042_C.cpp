// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , k ; cin >> n >> k ; 
    string str ; cin >> str ; 

    int cnt1 = 0 , cnt0 = 0 ; vector<int> suff(n + 2) ;
    for ( int i = n ; i > 0 ; i -- ) {
        int p = i - 1 ; 
        cnt0 += (str[p] == '0') ; 
        cnt1 += (str[p] == '1') ;
        // cout << "0: " << cnt0 << ' ' << "1: " << cnt1 << endl ;
        suff[i] = cnt1 - cnt0 ; 
    }

    int cnt_f_0 = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) if(str[i] == 0) {
        cnt_f_0 += (str[i] == '0') ; 
    } else break ;  

    for ( int i = 1 ; i <= cnt_f_0 ; i ++ ) suff[i] = 0 ; 

    // for ( int i = 1 ; i <= n ; i ++ ) cout << suff[i] << ' ' ; 
    // cout << endl ;

    suff[1] = 0 ; 
    suff.pop_back() ; 
    sort(suff.begin() + 1 , suff.end() , greater<int>()) ; 
    
    // cout << suff.size() << endl ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        suff[i] += suff[i - 1] ; 
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( suff[i] >= k ) {
            cout << i + 1 << endl ; 
            return ; 
        }
    }

    cout << -1 << endl ; 
 
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

 
