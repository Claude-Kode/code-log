/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream> 
#include <utility>
#include <bitset>
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <deque> 
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define TUP tuple<int , int , int>
#define ull unsigned int int
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD2 = 998244353 ; 
const int MOD = 1e9 + 7 ; 
const ll LINF = 1e18 ;

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;



// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

int gcd( int a , int b ) { return b == 0 ? a : gcd( b , a % b ) ; }

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int n , m ; cin >> n >> m ; 
    vector<int> arr( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ; 
    int exp = __lg(n) ;
    vector<vector<int>> st( exp + 1 , vector<int>(n + 1) ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        st[0][i] = arr[i] ; 
    } 
    for ( int j = 1 ; j <= exp ; j ++ ) {
        for ( int i = 1 ; i + (1 << j) - 1 <= n ; i ++ ) {
            st[j][i] = gcd( st[j - 1][i] , st[j - 1][i + (1 << (j - 1))] ) ;  
        }
    }
    
    while ( m -- ) {
        int l , r ; cin >> l >> r ;
        int j = __lg( r - l + 1 ) ; 
        cout << gcd( st[j][l] , st[j][r - (1 << j) + 1] ) << endl ;  
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/
