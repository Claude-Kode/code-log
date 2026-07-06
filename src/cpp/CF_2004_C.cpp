// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , k ; cin >> n >> k ; 
    vector<int> vec(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ;
    }

    sort(vec.begin() + 1 , vec.end() , greater<int>()) ; 

    for ( int i = 2 ; i <= n ; i += 2 ) {
        if ( vec[i] < vec[i - 1] ) {
            int diff = vec[i - 1] - vec[i] ; 
            if ( k >= diff ) {
                vec[i] = vec[i - 1] ; 
                k -= diff ; 
            } else {
                vec[i] += k ;
                break ; 
            }
        }
    }
    
    int a = 0 , b = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( i & 1 ) a += vec[i] ; 
        else b += vec[i] ; 
    }

    cout << a - b << endl ; 

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

