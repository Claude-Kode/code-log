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
    string s , t ; cin >> s >> t ; 
    vector<int> buckle_s( 26 ) , buckle_t( 26 ) ; 
    for ( auto &a : t ) buckle_t[a - 'a'] ++ ; 
    for ( auto &a : s ){
        buckle_s[a - 'a'] ++ , 
        buckle_t[a - 'a'] -- ;
        if ( buckle_t[a - 'a'] < 0 ) {
            cout << "Impossible" << endl ; 
            return ; 
        }
    }
    string ans ;
    int l = 0 , i = 0 ; 
    // 谁更小输出谁 s输出完了就全输出 t 
    while ( i < 26 || l < s.size() )
        if ( l < s.size() && (i >= 26 || (s[l] - 'a') <= i) ) 
            ans.push_back(s[l++]);
        else if ( i < 26 && buckle_t[i] > 0 ) 
            ans.push_back( 'a' + i ) , buckle_t[i]--;
        else 
            i ++ ;
    cout << ans << endl ; 
    // sort( t.begin() , t.end() ) ;
    // for ( auto &a : s ) {
    //     auto it = t.find( a ) ; 
    //     if ( it == string :: npos )  
    //         { cout << "Impossible" << endl ; return ; }
    //     t.erase(it) ; 
    // }
    // map<char , int> mps , mpt ; 
    // for ( auto &a : t ) mpt[a] ++ ; 
//     for ( auto &a : s ) {
//         mps[a] ++ ; mpt[a] -- ; 
//         if ( mpt[a] < 0 ) { cout << "Impossible" << endl ; return ; }
//    }     
    // string ans ; 
    // int l = 0 ;
    // for ( int i = 0 ; i < t.size() ; i ++ ) {
    //     if ( t[i] < s[l] ) 
    //         ans.push_back( t[i] ) ;
    //     if ( t[i] >= s[l] && l < s.size() )   
    //         ans.push_back( s[l++] ) ;
    // } 
    // cout << ans << endl ;
    // // 如果相同 优先输出 t 的

}

// ========================== Idea =============================================
/*

sort then use two pointers to cout 
by cmp the value 

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
