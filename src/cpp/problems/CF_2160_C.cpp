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
using namespace std;
// using namespace ranges;

// ========================== Macro Definitions ================================
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int, int>
#define TUP tuple<int, int, int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

// ========================== Global Variables / Arrays ========================


// ========================== Functions ========================================

void solve () {
    int n ; cin >> n ; 
    if ( n == 0 ) { cout << "YES" << endl ; return ; }
    int bit = 32 - __builtin_clz( n ) ; 
    int back_0 = 0 ; 
    vector<int> num ;
    for ( int i = 0 ; i < 32 ; i ++ ) {
        if ( ( n >> i & 1 ) == 1 ) break ; 
        else back_0 ++ ; 
    }    
    for ( int i = 0 ; i < bit ; i ++  ) num.push_back( n >> i & 1 ) ;
    // Debug
    // for ( auto &a : num ) cout << a << ' ' ;
    for ( int i = 0 ; i < back_0 ; i ++ ) num.push_back( 0 ) ; 
    // for ( auto &a : num ) cout << a << ' ' ;
    // cout << endl << bit << ' ' << back_0 ; 
    // cout << endl << num[(bit + back_0 + 1) / 2 - 1] ;
    int l = 0 , r = num.size() - 1 ;
    while ( l < r ) {
        if ( num[l] == num[r] ) { l ++ ; r -- ; } 
        else { cout << "NO" << endl ; return ; }
    }
    if ( (bit + back_0) % 2 == 1 && num[(bit + back_0 + 1) / 2 - 1] == 1 ) cout << "NO" << endl ;
    else cout << "YES" << endl ;
}
// ========================== Idea =============================================
/*
n 是 1 的位置 x 和 fx 要长得不一样
x 的长度是要和 n 是一样的 
不仅仅是有个前导 0 的问题 还有个后导 0 的问题
再来总结一下 n 是 1 位置 , 假设就是第 k 位
所以 x 的第 k 位和 fx 的第 k 位要不相同
fx 的第 k 位是 x 的第 bit(x) - k 位
x ^ fx 的结果是个回文串
所以 n 也是个回文串
但是这里有个问题就是 如果 n 的后面都是 0 的话 由于 x 去掉了前导 0
会有漏算 比如 n = 100 的话 不是回文串 但是 00100是啊
还有一点就是 1000是不合法的 因为这里的 1 对应的 k 和 bit(x) - k 是相等的
"我和我自己不相同" 肯定是不合法的 还要特判一下
另外 __builtin_clz( 0 ) 是 RE 行为

这道题我在写的时候 根本就没有想到回文这一点 只是有大概的感觉 应该回来再看看
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) solve() ;  
    return 0;
}
// ========================== Question =========================================
/*

*/
