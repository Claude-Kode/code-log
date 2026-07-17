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

int tt ; 


// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }



void solve() {
    
    int n , x ; cin >> n >> x ;
    vector<int>  a(n + 1) , b(n + 1) , c(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i] >> b[i] >> c[i] ; 
    } 

    bool can = false ; 
    int sum1 = 0 , sum2 = 0 ; 
    vector<int> arr( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        sum1 += a[i] * (b[i] - 1) ;  
        sum2 = max( sum2 , a[i] * b[i] - c[i] ) ; 
        if ( sum1 >= x || a[i] * b[i] - c[i] > 0 ) can = true ;
    }

    if ( !can ) { cout << -1 << endl ; return ; }

    if ( x <= sum1 ) { cout << 0 << endl ; return ; }

    x -= sum1 ; 
    cout << (x + sum2 - 1) / sum2 << endl ;

}

// ========================== Idea =============================================
/*

这道题就是贪心 , 我们要求凑出 x ， 还要尽可能好少的付出代价
所以在不花费代价的前提下 ， 我们直接尽可能凑出所有的能凑出的 ， 剩下的部分实在不行再付出代价搞出来
防止你凑不出来 ， 所以给你留了一手 ， 对于每个 a[i] 你可以自己选值

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> tt ; 
    while ( tt -- ) {
        solve() ; 
    }
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/

