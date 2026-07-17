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
    int n , k ; cin >> n >> k ; 
    string s ; cin >> s ; 
    vector<int> pos ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( s[i] == '1' ) pos.push_back( i + 1 ) ; 
    }
    // cout << "pos: " ; 
    // for ( auto &a : pos ) cout << a << ' ' ;
    if ( pos.empty() ) { cout << n << endl ; return ; }
    pos.push_back( n + 1 ) ; 
    int cnt = pos.front() - 1 ; 
    for ( int i = 1 ; i < pos.size() ; i ++ ) {
        if ( pos[i] - pos[i - 1] > k ) 
            cnt += pos[i] - pos[i - 1] - k - 1 ;
    }
    cout << cnt << endl ;
}

// ========================== Idea =============================================
/*

睡到第一个 1  
j - i - k + 1 是两节课能睡的时间
如果两节课之间的空间小于等于 k
那么睡不了 

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
