// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int n , m , k ; cin >> n >> m >> k ;

    set<int> vals ; vector<int> ans( n ) ;
    
    int sum = 0 ; 
    for ( int i = 1 ; i <= m ; i ++ ) {
        vals.insert( i ) ; sum += i ;
    } 

    if ( sum < k ) {
        cout << "NO" << endl ; 
        return ;
    }

    cout << "YES" << endl ; 

    int cursum = 0 ; 
    for ( int i = 1 ; i <= n - 1 ; i ++ ) {
        ans[i] = i ; cursum += ans[i] ; 
    } 

    int rem = k - cursum ; int p = n ; 
    while ( rem > 0 ) {
        int temp = ans[p] ; 
        if ( rem > p - ans[p] ) ans[p] = p ; 
        else ans[p] += rem - ans[p] ; 
        rem -= ans[p] - temp ; 
    }

    for ( int i = 1 ; i <= n - 1 ; i ++ ) vals.erase( ans[i] ) ;

    for ( int i = 1 ; i <= n - 1 ; i ++ ) {
        cout << i << ' ' << i + 1 << ' ' << ans[i] << endl ; 
    }
    
    m -= n - 1 ;
    for ( int i = 1 ; i <= n - 2 ; i ++ ) {
        for ( int j = i + 2 ; j <= n ; j ++ ) {
            if ( m ) {
                cout << i << ' ' << j << ' ' << *vals.rbegin() << endl ; 
                vals.erase( *vals.rbegin() ) ; 
                m -- ; 
            } else {
                break ; 
            }

        }
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


