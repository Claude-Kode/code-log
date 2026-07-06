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
#include <utility>
#include <bitset>
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
#define ull unsigned long long
#define PII pair<int , int>
#define TUP tuple<int , int , int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const ll LINF = 1e18 ;
const int MOD = 1e9 + 7 ;
const int MOD2 = 998244353 ;

// ========================== Global Variables / Arrays ========================


// ========================== Functions ========================================

void solve() {
    int n , q ; cin >> n >> q ;
    string s ; cin >> s ;
    int b = count( s.begin() , s.end() , 'B' ) ;
    while ( q -- ) {
        int qq , ans = 0 ; cin >> qq ; 
        if ( b == 0 )   
            { cout << qq << endl ; continue ; }
        while ( qq ){ 
            for ( int i = 0 ; i < n && qq ; i ++ , ans ++ ) 
                s[i] == 'A' ? qq -- : qq >>= 1 ; 
        }         
        cout << ans << endl ; 
    }
}

// ========================== Idea =============================================
/*

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
