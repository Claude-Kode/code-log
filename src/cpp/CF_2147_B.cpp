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

1 是可以随意安排的
n 只能一个在中间 另一个在两侧
或者一个在一侧 另一个在另一侧
如果是两个数之间的距离是这个数的倍数 直接就去想想数轴
n n-1 n-2 .... 1 0 1 2 3 4 5
但是这里没有 0 怎么办 用 n 代替 最后把 n 放到两端即可

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ;
    while ( tt -- ) {
        int n ; cin >> n ;
        for ( int i = n ; i >= 1 ; i -- ) {
            cout << i << ' ' ;
        } 
        cout << n << ' ' ;
        for ( int i = 1 ; i < n ; i ++ ) {
            cout << i << ' ' ;
        } 
        cout << endl ; 
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
