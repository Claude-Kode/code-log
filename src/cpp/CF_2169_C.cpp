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
#include <utility>
#include <bitset>
#include <string>
#include <vector>
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


// ========================== Idea =============================================
/*
这种题应该是判断哪个区间进行变换之后能提升值的大小
或许是排序之后 从小到大
目的就是最大化提升的量
可以离散化操作吗 每个数字小于他的下标的二倍直接进行替换 哦对是可以的 !!!
证明一下
有的情况下是对的但是 如果是一万个 1 排在一起 就不是最优解
最暴力的方式就是枚举 l 和 r 进行替换计算 + 比较
或许从这一点出发优化能做出来 ? 
或者说思考固定一个 L 找 r 或者固定一个 r 找 l ?
首先如果要让和尽可能的大 要让 l 和 r 各自更大 而且长度更长 ?
不对啊卧槽 第一个也是对的啊 
通过数学公式量化表达
牛逼 然后就变成哈希表枚举了
总结一下 这个题是属于 
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    // int tt ; cin >> tt ; 
    // while ( tt -- ) {
    //     int n ; cin >> n ; 
    //     vector<int> arr( n + 1 ) , pre( n + 1 ) , cal( n + 1 ); 
    //     for ( int i = 1 ; i <= n ; i ++ ) {
    //         cin >> arr[i] ;
    //         // cout << arr[i] ;
    //         pre[i] = pre[i - 1] + arr[i] ;
    //         cal[i] = i * i + i - pre[i] ;
    //     }
    //     // process
    //     // !!!!!这里的顺序枚举问题总是搞不懂
    //     // 突然想通了 是枚举右 维护左哈哈哈哈哈
    //     // 但是这里好像有个问题就是 l 是可以 == r 的但是
    //     // 方程里面是 f ( r ) - f ( l - 1 ) 也就是说最多就是 l - 1 == r 
    //     int ans = 0 , mn = INT_MAX  ; 
    //     // 这里有个问题 为啥 0 也要算上啊 ???? 
    //     // 因为公式枚举的是 f ( l - 1 )  l 是可以等于 1 的
    //     // 而且之前的问题 l == r 的时候更行的
    //     // 为啥不用考虑这个mn更新的时机呢
    //     // 如果 mn 放在前面进行更新的话 是 当前 r 和从 1 到 r 的所有里面的最小值
    //     // 如果放在后面就是 从 当前 r 到 从 1 到 r - 1 里面的所有的最小值
    //     // 也是一种手段
    //     for ( int i = 0 ; i <= n ; i ++ ) {
    //         ans = max ( ans , cal[i] - mn ) ;
    //         mn = min ( mn , cal[i] ) ; 
    //     }
    //     // for ( auto &a : pre ) cout << a << ' ' ;
    //     // cout << endl ; 
    //     // cout << pre[n] << ' ' << endl ; 
    //     cout << pre[n] + ans << endl ;
        int a = 0 ; for ( int i = 0 ; i < 1000000 ; i ++ ) cout << a << endl ; 
        // cout << R"(
        
        //  n
        //  m
        //  l
        //  g
        //  b
        
        // )" << endl ; 
        // cout << a ;
    // }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
