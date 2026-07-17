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
新元素会加在之前所有的组合上
所以 b[i + 1] - b[i] = i + 1
就要push一个新元素
如果 b[i + 1] - b[i] = 1 
要 push 一个和上一个元素相同的元素 因为只会增加一个 自己这个子数组
所以 最小增量就是 1 最大增量就是 i 
那增量是别的大小应该怎么办呢
按理来说 增量就是 自己这一项加上前面的所有结果 
这怎么像 dp 了
如果增量是 i - 1 这一位应该是和上上个相等的
如果增刊
 

对于前面的数组来说 如果新添加一个从来没出现过的元素 增量是前面数组的长度 + 1 
吗 ?   是的
如果新添加的元素 在之前的数组里面出现过 x 次会怎么样
首先我们假设 顺序和最后的值是没有关系的 尝试证明一下
好吧 其实是有关系的 TwT
是不是只要当前元素在前面出现过 其实好像是没什么影响的 ? 
对于 b[i] - b[i - 1] == i 来说 直接赋值 i 是个不错的选择
或者说直接用下标赋值是一种很好的手段
所以说我每一次的赋值直接跟下标关联起来就好了
对于 b[i] - b[i - 1] < i 的项来说是怎么赋值的呢
而且对于这个 b[i] 来说他一定是递增的 也就是其实这个赋值我更倾向于是一个递推式子
样例中的相邻项相等和隔项相等是 ? 
如果是隔项相等 他的增量 就是 2 
等一下卧槽 !!!!1
我懂了 卧槽尼玛的
卧槽  
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n ; cin >> n ; 
        vector<int> arr ( n ) ;
        for ( auto &a : arr ) cin >> a ; 
        // 把下标整体移位一位 ? 
        vector<int> ans ( n , 1 ) ;
        for ( int i = 1 ; i < n ; i ++ ) {
            int diff = arr[i] - arr[i - 1] ;
            // cout << i - diff << ' ' ;  
            diff != i + 1 ? ans[i] = ans[i - diff] : ans[i] = i + 1; 
        }
        for ( auto &a : ans ) cout << a << ' ' ;
        cout << endl ; 
    } 
    return 0 ;
}
// ========================== Question =========================================
/*

*/