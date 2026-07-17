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
#include <utility>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

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
int BFS ( int n , int m ) {
    int dirs[4][2] = { { 1 , 0 } , { -1 , 0 } , { 0 , 1 } , { 0 , -1 } } ;
    queue<tuple<int , int , int>> q ; 
    while ( !q.empty() ) {
        auto [x , y , z] = q.front() ; q.pop() ; 
        if ( x == n - 1 && y == n - 1 ) return z ; 
        for ( auto &dir : dirs ) {
            int nx = x + dir[0] , ny = y + dir[1] ;
            if ( nx >= 0 && nx < n && ny >= 0 && ny < n ) q.emplace( nx , ny , z + 1 ) ;
        }
    }
    return -1 ; 
}

// ========================== Idea =============================================
/*

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int l , n , k ; cin >> l >> n >> k ;
    vector<int> arr ( l ) ;
    for ( auto &a : arr ) cin >> a ;
    vector<int> arr ( n ) ;
    for ( auto &a : arr ) cin >> a ; 

    return 0 ;
}
// ========================== Question =========================================
/*
    QQ
*/
