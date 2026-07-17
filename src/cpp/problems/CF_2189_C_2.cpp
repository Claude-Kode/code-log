/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
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
#define ull unsigned long long
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD1 = 998244353 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

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
     
    int n ; cin >> n ; 
    if ( 1 << __lg(n) == n ) { cout << -1 << endl ; return ; }
    vector<int> arr( n + 1 ) , vis( n + 1 ) ;
    arr[n] = 1 ; vis[1] = 1 ;
    for ( int i = 2 ; i <= n - 1 ; i ++ ) {
        if ( i & 1 ) arr[i] = i - 1 ;
        else arr[i] = i + 1 ; 
        vis[arr[i]] = 1 ;
    }
    for ( int i = 1 ; i <= n ; i ++ ) if ( !vis[i] ) { arr[1] = i ; break ; }
    if ( !(n & 1) ) {
        int a = arr[1] ;
        for ( int i = 2 ; i < n ; i += 2 ) {
            if ( (a ^ i) <= n && (a ^ i) != (i + 1) ) {
                swap( arr[i] , arr[1] ) ; break ; 
            }
        }
    }

    for ( int i = 1 ; i <= n ; i ++ ) cout << arr[i] << ' ' ;

    cout << endl ; 

}

// ========================== Idea =============================================
/*

奇偶性不同的数异或出来是奇数

2的i次幂 ^ 2的i次幂 + 1 , 一定等于 1 

偶数 + 1 ^ 奇数一定等于 1 卧槽接替关键就在这里

一般来说第一位都是 n ， 对于 n & 1 == 1 来说 ， n ^ 1 == n - 1 ， 这个没问题
但是 n & 1 == 0 来说 ， n ^ 1 == n + 1 , 这种是不存在的

如果 n 是 2 的次幂 , 那么它异或 n 以内的任何数都等于 n + 这个数 , 是不成立的
如果是

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


