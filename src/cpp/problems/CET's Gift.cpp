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

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ;
    while( tt -- ) {
        int n , q ; cin >> n >> q ; 
        string str ; cin >> str ; 
        vector<int> digits ; 
        while ( q -- ) {
            string quest ; cin >> quest ; 
            int l = 0 , r = 0 ; 
            while ( l <= n - 1 && r <= quest.size() - 1 ) {
                if ( str[l] == quest[r] ) {
                    l ++ , r ++ ; 
                } else {
                    l ++ ; 
                }
            }
            digits.push_back( r == quest.size() ) ; 
        }
        int res = 0 , base = 1 ; 
        for ( auto &a : digits ) {
            if ( a ) 
                res += base ; 
            base *= 2 ; 
        }
        cout << res << endl ; 

    }
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/
