// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    string str ; cin >> str ; 
    int n = str.size() ;

    if ( n < 4 || (n & 1) ) { cout << "NO" << endl ; return ; }

    int lim = n / 2 - 1 ; 

    for ( int i = 1 ; i <= lim ; i ++ ) {
        int alen = i ;
        int blen = lim - i + 1 ;

        // cout << alen << ' ' << blen << endl ; 

        string pre1(str.begin() , str.begin() + alen ) ;
        string pre2(str.begin() + alen , str.begin() + 2 * alen ) ;

        // cout << "p1 " << pre1 << ' ' << "p2 " << pre2 << endl ;  

        if ( pre1 != pre2 ) continue ;

        string suff1( str.begin() + 2 * alen , str.begin() + 2 * alen + blen ) ;
        string suff2( str.begin() + 2 * alen + blen , str.begin() + 2*alen + 2 * blen ) ;

        // cout << "s1 " << suff1 << ' ' << "s2 " << suff2 << endl ; 

        if ( suff1 != suff2 ) continue ; 

        cout << "YES" << endl ;

        return ; 

    }

    // cout << endl ;

    cout << "NO" << endl ; 

}

signed main() {


    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

