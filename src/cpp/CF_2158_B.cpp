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
可能对于普通情况来说 没中元素只占据一个位置在一个函数是最优解
但是如果元素不能满足呢 还是挨个填充吗
换个想法 如果不是一个的话 需要至少两个空间来贡献一个 + 1 
最大的答案就是 2 * n 了
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n ; cin >> n ;
        unordered_map<int, int> mp ;
        for ( int i = 0 ; i < 2 * n  ; i ++ ) {
            int temp ; cin >> temp ; 
            mp[temp] ++ ; 
        }
        int cnt_odd = 0 , cnt_2_mod4 = 0 , cnt_0_mod4 = 0 ;
        for ( auto &[_ , cnt] : mp ) {
            if ( cnt % 2 == 1 ) cnt_odd ++ ; 
            if ( cnt % 4 == 2 ) cnt_2_mod4 ++ ; 
            if ( cnt % 4 == 0 ) cnt_0_mod4 ++ ;
        }
        // mod4 == 2 的怎么拆都不影响
        // 由于总共的cnt一定是偶数 所以不可能出现 出现次数是奇数的元素的数量是奇数
        // mod4 == 0 的数字可以拆成 k + 1 和 k - 1 但是如果他的出现次数是奇数 
        // 就要牺牲掉一组变成两个偶数来保证平衡
        // 但是还要考虑 奇数次的一定是偶数 所以是可以腾出一组来帮 cnt_0_mod4补的
        // 卧槽这题
        // 把数据进行分类 通过数据的贡献 和 数据对分配产生影响的情况的贡献(总是相互抵消最后只能是 1 或者 2 )
        // 然后分类讨论进行计算
        cout << cnt_odd + 2 * cnt_0_mod4 + 2 * cnt_2_mod4 - 2 * (cnt_0_mod4 % 2 == 1 && cnt_odd == 0) << endl ;
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
