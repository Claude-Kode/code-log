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
    string str1 , str2 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        char temp ; cin >> temp ; 
        if ( temp == 'O'|| temp == '0' ) str1 += '0' ; 
        else if ( temp == '1' || temp == 'l' || temp == 'I' ) str1 += '1' ; 
        else str1 += temp ; 
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        char temp ; cin >> temp ; 
        if ( temp == 'O'|| temp == '0' ) str2 += '0' ; 
        else if ( temp == '1' || temp == 'l' || temp == 'I' ) str2 += '1' ; 
        else str2 += temp ; 
    }

    // cout << str1 << ' ' << str2 << endl ; 

    cout << (str1 == str2 ? "YES" : "NO") << endl ; 

}

/*

*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    
    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
    
*/