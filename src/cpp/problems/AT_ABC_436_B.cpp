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



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int n ; cin >> n ; 
    vector<vector<int>> grid( n , vector<int>( n ) ) ; 
    int x = 0 , y = ( n - 1 ) / 2 , val = 1 ; 
    grid[x][y] = val ; 
    for ( int i = 0 ; i < n * n - 1 ; i ++ ) {
        int xx = ( x - 1 + n ) % n , yy = ( y + 1 + n ) % n ;
        val ++ ; 
        if ( grid[xx][yy] == 0 ){
            grid[xx][yy] = val ; 
        }    
        else 
            xx = ( x + 1 + n ) % n , yy = y , grid[xx][yy] = val ;
        x = xx , y = yy ; 
    }
    for ( int i = 0 ; i < n ; i ++ ){
        for ( int j = 0 ; j < n ; j ++ ) 
            cout << grid[i][j] << ' ' ; 
        cout << endl ; 
    }        
    return 0 ;
}
// ========================== Question =========================================
/*

*/
