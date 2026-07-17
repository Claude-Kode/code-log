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

如果答案是 奇数 那么他可以由其乘以 2 之后得到的偶数 经过一次操作 1 来得到

题解运用了正难则反的思想 逆向运算 我没有想到 完全想不到
如果把他转化成 2 那么就可以一直 * 2 累加上去 
如果是奇数 那你转换个 鸡八 如果是奇数 第一步直接 * 2 
也就是说 如果是奇数 那么最后一次操作一定是 1
他妈推到这里有个鸡八用啊
这个时候是不是一定能通过有限次的 操作 2 把他还原回去
卧槽 ? 
啊 ? 不对 如果是 16 里面 分配 10 和 6 就行不通

tmd 竟然是把这个操作串起来
既然是

首先 当个数字的定义都是 int 类型的 这道题里面直接就是 1 进行左移的时候会溢出了
还有就是这道题的思想 如果简单化的思考
首先是几乎所有的 ac 的人用的都是逆向思维
然后就是逆向思维的思考过程 如果简单化是飞航的简单粗暴
如果小于目标就变大 大于目标就变小 就尼玛这么简单
而我往往会觉得 会不会变小了以后要先增大 再两者之间传递一下值 再进行下一步缩小
自己写一下就知道了


*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ;
    while ( tt -- ) {
        int k , x ; cin >> k >> x ; 
        int target = ( 1LL << k ) ;
        // cout << target << endl ; 
        int y = target * 2 - x ;
        vector<int> ans ; 
        while ( x != target ) {
            if ( x <= target ) 
                ans.push_back( 1 ) , y -= x , x *= 2 ;
            else 
                ans.push_back( 2 ) , x -= y , y *= 2 ;
            // cout << x << endl ;
        }
        // cout << endl ; 
        cout << ans.size() << endl ; 
        while ( !ans.empty() )
            cout << ans.back() << ' ' , ans.pop_back() ; 
        cout << endl ; 
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/

