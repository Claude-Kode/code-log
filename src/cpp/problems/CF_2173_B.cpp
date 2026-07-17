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

using recurrence thinking
i-th mx res can be cal by the i-1-th's mx or mn
as you can see , 
to cal the mx ,
you need to be as large as possible than a[i]
or as small as possible than b[i]
so the mx and mn in last turn should be used 

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n ; cin >> n ; 
        vector<int> a( n ) , b( n ) ;
        for ( auto &x : a ) cin >> x ; 
        for ( auto &x : b ) cin >> x ; 
        int pre_mx = 0 , pre_mn = 0 ; 
        int cur_mx = 0 , cur_mn = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) {
            cur_mx = max( pre_mx - a[i] , b[i] - pre_mn ) ; 
            cur_mn = min( b[i] - pre_mx , pre_mn - a[i] ) ;
            pre_mx = cur_mx ; pre_mn = cur_mn ; 
        }
        cout << cur_mx << endl ; 
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
