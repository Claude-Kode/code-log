
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



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int n , m ; cin >> n >> m ; 
    int sx , sy , tx , ty ; 
    vector<vector<int>> maze( n + 1 , vector<int>( m + 1 ) ) ;
    unordered_map<PII , PII> mp ; 
    for( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            char temp ; cin >> temp ; 
            if ( temp == '#' ) 
                maze[i][j] = 0 ; 
            if ( temp == '@' ) 
                sx = i , sy = j ;
            if ( temp == '=' ) 
                tx = i , ty = j ;
            if ( temp == '.' ) 
                maze[i][j] = 1 ;
            if ( temp >= 'A' && temp <= 'Z' ) 
            
        }
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/
