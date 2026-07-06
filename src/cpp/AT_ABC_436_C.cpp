/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

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
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned int int
#define PII pair<int , int>
#define TUP tuple<int , int , int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const ll LINF = 1e18 ;
const int MOD = 1e9 + 7 ;
const int MOD2 = 998244353 ;
const int BASE = 1e9 + 7 ; // 基数，大于 y 的最大可能值（1e9）

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

inline int hash_pair( int x , int y ) {
    return x * BASE + y ;
}

void solve() {
    
}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;

    int n , m ; cin >> n >> m ;
    int res = 0 ; 
    unordered_set<int> placed ; // 直接存打包后的整数，无需自定义哈希

    // 检查能否放置：周围 3x3 无已放置的方块
    auto check = [&]( int x , int y ) -> bool {
        for ( int dr = -1 ; dr <= 1; dr ++ ) {
            for ( int dc = -1 ; dc <= 1 ; dc ++ ) {
                int nx = x + dr ;
                int ny = y + dc ;
                if ( placed.count( hash_pair(nx, ny) ) ) {
                    return false ; 
                }
            }
        }
        return true ; 
    } ; 

    while ( m -- ) {
        int r , c ; cin >> r >> c ;
        if ( check(r , c) ) {
            placed.insert( hash_pair(r , c) ) ;
            res ++ ;
        }
    }

    cout << res << endl ;
    return 0 ;
}
// ========================== Question =========================================
/*

*/
