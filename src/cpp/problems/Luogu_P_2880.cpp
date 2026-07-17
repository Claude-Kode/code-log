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
const int maxn = 1e9 ; 

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

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
    int n , q ; cin >> n >> q ; 

    vector<int> arr( n ) ; 
    for ( auto &a : arr ) {
        cin >> a ; 
    } 

    int exp = __lg( n ) ; 
    vector<vector<int>> mx_st( exp + 1 , vector<int>( n )) ; 
    vector<vector<int>> mn_st( exp + 1 , vector<int>( n )) ; 
    
    for ( int i = 0 ; i < n ; i ++ ) {
        mx_st[0][i] = arr[i] ; 
        mn_st[0][i] = arr[i] ; 
    }

    for ( int j = 1 ; j <= exp ; j ++ ) {
        for ( int i = 0 ; i + (1<<j) - 1 < n ; i ++ ) {
            mx_st[j][i] = max( mx_st[j - 1][i] , mx_st[j - 1][i + ( 1 << (j - 1) )] ) ; 
            mn_st[j][i] = min( mn_st[j - 1][i] , mn_st[j - 1][i + ( 1 << (j - 1) )] ) ; 
        }
    }

    while ( q -- ) {
        int l , r ; cin >> l >> r ;
        l -- ; r -- ; 
        int exp = __lg( r - l + 1 ) ; 
        int mx = max( mx_st[exp][l] , mx_st[exp][r - (1<<exp) + 1] ) ; 
        int mn = min( mn_st[exp][l] , mn_st[exp][r - (1<<exp) + 1] ) ; 
        cout << mx - mn << endl ;
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/
