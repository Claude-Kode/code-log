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

int n , k ; 

vector<int> arr ;

bool sign = false ; 

int sumxc = 0 ; 
int sum = 0 ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void DFS( int i , int taken , int takenxc , int takensum ) {
    if ( sign ) return  ; 
    if ( taken == k ) {
        if ( sum * (sumxc - takenxc ) == (sum - takensum ) * sumxc ) sign = true ; 
        // cout << takenxc << ' ' << takensum << endl ; 
        return ; 
    }

    if ( i == n + 1 ) return ; 

    // 被拿走了
    DFS( i + 1 , taken + 1 , takenxc + arr[i] * i , takensum + arr[i] ) ;  
 
    // 没被拿走
    DFS( i + 1 , taken , takenxc , takensum ) ; 
}

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n >> k ; 
    arr.resize( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
        sum += arr[i] ; 
        sumxc += arr[i] * i ;
    }

    DFS( 1 , 0 , 0 , 0 ) ;

    sign ? cout << "Yes" << endl : cout << "No" << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/

