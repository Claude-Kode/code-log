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


// ========================== Idea =============================================
/*

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    // input part
    int n , k ; cin >> n >> k ;
    vector<int> arr ( n ) ; 
    for ( auto &a : arr ) cin >> a ;
    // silding window 
    int sum = 0 ; 
    vector<int> value ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        // new ele into window 
        sum += arr[i] ;
        // left edge 
        int l = i - k + 1 ;
        // invalid window , continue 
        if ( l < 0 ) continue ; 
        // push value 
        value.push_back( sum ) ;
        // the ele on the left edge leaves
        sum -= arr[l] ; 
    }
    // cal diff
    int len_value = value.size() ; 
    vector<int> diff ;
    for ( int i = 1 ; i < len_value ; i ++ ) {
        diff.push_back( value[i] - value[i - 1] ) ;
    }
    // cal res 
    int res = 0 ; 
    int len_diff = diff.size() ; 
    for ( int i = 0 ; i < len_diff ; i ++ ) {
        int left_rem = i + 1 ; 
        int right_rem = len_diff - i ;
        res += left_rem * right_rem * diff[i] ;
    }
    // output
    cout << res << endl ;
    return 0 ; 
}
// ========================== Question =========================================
/*

*/
