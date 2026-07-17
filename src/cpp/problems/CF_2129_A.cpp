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
    vector<pair<int, int>> vec( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i].first >> vec[i].second ; 
    }

    sort( vec.begin() , vec.end() ) ; 

    int f = 0 , l = vec[1].first , r = vec[1].second ; 
    for ( int i = 0 ; i <= n ; i ++ ) {
        if ( vec[i].first > vec[i - 1].second ) {
            f += r - l ;
            r = vec[i].second ;
            l = vec[i].first ; 
            continue ;
        } 
        l = min( l , vec[i].first ) ; 
        r = max( r , vec[i].second ) ; 
    }

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