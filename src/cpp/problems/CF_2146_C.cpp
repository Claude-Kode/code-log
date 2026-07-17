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

就是让二分的中间值 m 变成 l 或者 r 里面随机一个数
然后最后要保证 一定能收缩到 m 这个数字 
那二进制字符串是干啥的
1 和 0 代表是不是稳定的
就是这个 $$位置$$对应的值 的数字能不能被搜到
si 就是搜 i 
1 的数量是 0 或者 奇数 那么是可以被搜到的
如果 1 的数量是偶数 是不能生成答案的 ? 


*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n ; cin >> n ; 
        string str ; cin >> str ; 
        int cnt = 0 ; 
        for ( auto &a : str ) cnt += a - '0' ;
        if ( cnt != 0 && cnt % 2 == 0 ) 
            { cout << "NO" << endl ; continue ; }
        
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
