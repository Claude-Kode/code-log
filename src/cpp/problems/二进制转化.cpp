// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int n ; cin >> n ;
    string str , str1 ; cin >> str1 ; 
    str += "0" ; str += str1 ; 
    int l , r ; cin >> l >> r ; 
    if ( (n & 1) == 0 ) { cout << "No" << endl ; return ; }

    if ( l == 1 ) str[0] = str[n] == '1' ? '0' : '1' ; 

    for ( int i = l ; i <= r ; i ++ ) {
        str[i] = str[i - 1] == '1' ? '0' : '1' ;  
    }

    for ( int i = 2 ; i <= n ; i ++ ) {
        if ( str[i] == str[i - 1] ) { cout << "No" << endl ; return ; }
    }

    // cout << str << endl ; 

    cout << "Yes" << endl ; 

}

signed main() {


    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

