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

这道题就是判断一个 n 个数经过变换之后不互质
k 为偶数的时候想不到 trick 了
14min
我想到的思路就是 通过直接找到那个 g 来验证 但是没有单调性 所以不能通过二分枚举
感觉思路还是有提升的 正面没找就用反面 从答案枚举再验证

学到了一个特殊的 trick
对于一个数 x 和一个目标因子 g 
x 可以看作由 被 g 整除的部分 加上 % g 的部分
如果要好多份 x 凑出被 g 整除 
直接把 % g 的部分给凑出 g 份出来 这样一定就可以整除了


*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ;
    while ( tt -- ) {
        int n , k ; cin >> n >> k ; 
        for ( int i = 0 , temp  ; i < n ; i ++ ) 
            cin >> temp , cout << temp + ( temp % ( k + 1) ) * k << ' ' ; 
        cout << endl ; 
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
