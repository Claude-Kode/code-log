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
void solve() {
    int n ; cin >> n ; 
    vector<int> arr ; 
    int cnt = 0 , sum = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        int temp ; cin >> temp ; 
        if ( temp ) {  arr.push_back( temp ) ; sum += temp ; cnt ++ ; }
    } 
    while ( sum - cnt < n - 1 ) cnt -- ; 
    cout <<  cnt << endl ; 
}

// ========================== Idea =============================================
/*
如果大于 1 的个数大于 n 而且 sum 是大于 2 * n - 1 直接就是输出 cnt 
如果 sum 小于的话 直接就是 cnt - ( n - 1 )
现在有个问题就是 sum 正好差一次怎么办 就是第一次贪心直接cnt
但是后面剩余所有数字的和不够 n - 1 这个时候一定要缩短第一个区间
先试一下直接选
如果 sum - 最的元素 小于 n - 1 则直接输出 cnt 
否则 cnt -- 接着减去下一个
如果是 cnt 的话剩余的必须大于 n - 1 就是
否则 cnt -- 并 sum 减去最小项
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
