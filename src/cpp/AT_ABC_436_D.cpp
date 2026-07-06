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
// #define int long long
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

int dirs[4][2] = { { 1 , 0 } , { -1 , 0 } , { 0 , 1 } , { 0 , -1 } } ;

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

    int a = 12 ; 
    cout << "12: " << endl ; 
    for ( int i = 0 ; i <= 30 ; i ++ ) 
    
        cout << ( a >> i & 1 ) << ' '  ; 
    cout << endl << "sign: " << (a >> 31 & 1) << endl ; 
    a = -a ; 
    cout << "-12: " << endl ; 
    for ( int i = 0 ; i <= 30 ; i ++ ) 
        cout << ( a >> i & 1 ) << ' ' ; 
    cout << endl << "sign: " << (a >> 31 & 1) << endl ; 

    a = 12 ; 
    cout << "前导零 " << endl ; 
    cout << __builtin_clz( a ) << endl ;
    cout << "数字二进制长度 " << endl ; 
    cout << __lg( a ) + 1 << endl ;   
    a = -a ; 
    cout << "负数二进制长度" << endl ;
    cout << __lg( a ) << endl ; 

    cout << endl << endl ;
    int x = 12 ;
    cout << (x - (x & ( x - 1 ))) << endl ; 
    cout << (x & -x) << endl ; 
    cout << (1 << __builtin_ctz( x )) ;

    // int i = 15 ; 
    // if ( -i == ~i + 1 )
    //     cout << "YES" << endl ;

    // int h , w ; cin >> h >> w ; 
    // vector<vector<int>> maze ( h + 1 , vector<int>( w + 1 ) ) ;
    // for ( auto &row : maze ) 
    //     for ( auto &a : row ) 
    //         cin >> a ;
    // // x , y , distance 
    // queue<tuple<int , int , int>> q ;
    // q.emplace( 1 , 1 , 0 ) ; 
    // while ( !q.empty() ) {
    //     auto [x , y , dis] = q.front() ; q.pop() ; 
    //     for ( auto &dir : dirs ) {
    //         int nx = x + dir[0] , ny = y + dir[1] ;
    //         if ( nx <= h && nx > 0 && ny <= w && ny > 0 && ) 
    //             if ( maze[nx][ny] == '')
    //     }
    // }
    return 0 ;
}
// ========================== Question =========================================
/*

*/

// void merge_sort( vector<int>& a , int l , int r ) {
//     if (l >= r) return ;
//     int m = (l + r) / 2 ;
//     merge_sort( a , l , m ) , merge_sort( a , m + 1 , r ) ;
//     vector<int> t ;
//     int i = l , j = m + 1 ;
//     while ( i <= m && j <= r ) t.push_back( a[i] <= a[j] ? a[i++] : a[j++] ) ;
//     while ( i <= m ) t.push_back( a[i ++] ) ;
//     while ( j <= r ) t.push_back( a[j ++] ) ;
//     for ( int k = 0 ; k < t.size() ; k ++ ) a[l + k] = t[k] ;
// }
// #include <bits/stdc++.h>
// #define endl '\n'
// #define int long long
// using namespace std ;
// signed main() {

//     // int l , r ; cin >> l >> r ; 
//     // int dis = r - l ; 
//     // vector<int> record ;
//     // int base = 1 ; 
//     // while ( dis ) {
//     //     if ( dis & 1 ) record.push_back( base ) ; 
//     //     dis >>= 1 ;
//     //     base <<= 1 ;
//     // }
//     // for ( auto &a : record ) {
//     //     cout << l << ' ' ;
//     //     l += a ;
//     //     cout << l << ' ' ;
//     //     cout << endl ; 
//     // }  

//     return 0 ; 
// }