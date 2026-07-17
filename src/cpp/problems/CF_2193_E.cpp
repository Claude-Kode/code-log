/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
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
#define ull unsigned long long
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD1 = 998244353 ; 
const int MOD2 = 1e9 + 7 ; 
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
     
    int n ; cin >> n ; 
    vector<int> nums ; 
    vector<int> arr( n + 1 ) ;
    vector<int> ans( n + 1 , INT_MAX ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
        ans[arr[i]] = 1 ; 
    } 

    for ( int i = 1 ; i <= n ; i ++ ) if ( ans[i] ) nums.push_back( i ) ;  

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( auto &a : nums ) {
            if ( i * a > n ) break ; 
            ans[i * a] = min( ans[i * a] , ans[i] + ans[a] ) ; 
        } 
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( ans[i] == INT_MAX ) cout << -1 << ' ' ;
        else cout << ans[i] << ' ' ; 
    }

    cout << endl ; 

}

// ========================== Idea =============================================
/*

张记性了 , 下次纯暴力先来一发

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt -- ) solve() ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/
