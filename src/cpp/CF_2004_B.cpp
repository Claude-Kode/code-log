// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int l , r ;  cin >> l >> r ;
    int L , R ; cin >> L >> R ;
    int mx = max(l , L ) ;
    int mn = min(r , R ) ;
    int ans = 0 ;
    ans += max(0LL , mn - mx ) ;
    if (mn - mx < 0) {
        cout << 1 << endl ;
        return ;
    }
    if ( l != L ) {
        ans ++ ;
    }
    if ( r != R ) {
        ans ++ ;
    }

    cout<< ans << endl ;
    
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

// Functions : 

int fp( int x , int p , int mod) {
    int res = 1 , base = x ; 
    while ( p ) {
        if ( p & 1 ) (res *= base) %= mod ; 
        (base *= base) %= mod ; 
        p >>= 1 ;
    }
    return res ; 
}

int lcm(int a , int b) { return a / gcd(a , b) * b  ; } 

int inv (int x , int mod) { return fp(x , mod - 2 , mod ) ; }

void dedup(vector<int>& vec ) { 
    sort(vec.begin() + 1 , vec.end()) ;
    vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}

