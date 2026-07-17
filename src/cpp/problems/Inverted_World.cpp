// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int cal_rev( string str ) {
    int sz1 = 0 , sz2 = 0 ;

    char ned = '0' ; 
    for ( const auto &c : str ) if ( c == ned ) {
        sz1 ++ ; ned = ((ned - '0') ^ 1) + '0' ;
    } 

    ned = '1' ; 
    for ( const auto &c : str ) if ( c == ned ) {
        sz2 ++ ; ned = ((ned - '0') ^ 1) + '0' ;
    } 

    return min( 1 + str.size() - sz1 , 1 + str.size() - sz2 ) ; 
}

void solve() {

    int n ; cin >> n ; 
    string str ; cin >> str ; 

    string ans1 , ans2 ; 
    for ( int i = 1 ; i <= n ; i ++ )  (i & 1) ? ans1 += '1' : ans1 += '0' ; 
    for ( int i = 1 ; i <= n ; i ++ )  (i & 1) ? ans2 += '0' : ans2 += '1' ; 

    int cost1 = 0 , cost2 = 0 , back0 = 0 , back1 = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) if ( str[i] != ans1[i] ) {
        if ( str[i] == '1' ) {
            if ( back0 ) back0 -- , back1 ++ ; 
            else cost1 ++ , back1 ++ ; 
        } else {
            if ( back1 ) back1 -- , back0 ++ ; 
            else cost1 ++ , back0 ++ ; 
        }
    } 

    back0 = 0 , back1 = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) if ( str[i] != ans2[i] ) {
        if ( str[i] == '1' ) {
            if ( back0 ) back0 -- , back1 ++ ; 
            else cost2 ++ , back1 ++ ; 
        } else {
            if ( back1 ) back1 -- , back0 ++ ; 
            else cost2 ++ , back0 ++ ; 
        }
    } 

    cout << min( cost1 , cost2 ) << endl ; 

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


// int money = 100 ; 
// while (1) if ( 京爷 ) {
//     money ++ ;
// }
// bool 京爷 = false ; 