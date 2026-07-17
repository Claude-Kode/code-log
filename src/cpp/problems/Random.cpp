// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b) ; }

void solve() {

    int n ; cin >> n ; 
    vector<int> arr( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ; 

    for ( int i = 1 ; i < n ; i ++ ) {
        for ( int j = i + 1 ; j <= n ; j ++ ) {
            if ( gcd(arr[i] , arr[j] ) > 1 ) {
                cout << arr[i] << ' ' << arr[j] << endl ; 
                return ; 
            } 
        }
    }

    cout << -1 << endl ; 

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