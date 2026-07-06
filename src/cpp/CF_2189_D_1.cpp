/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

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

int tt ; int n ; int c ; 

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

如果字符串的第 i 位置是 0 的话 , 在你新构造的排列里面 没有任何一个区间的 MEX 是 i
如果字符串的第 i 位置是 0 的话 , 在你新构造的排列里面 至少存在一个区间的 MEX 是 i

MEX 是未出现最小非负数

就不存在有
就这个区间至少有 1 --> i-1 的所有数 , 而且一定没有 i 
那这个区间的长度至少是 i , 所以直接 i 长度的滑动窗口相当于 , 
但其实也不对 , 因为只要区间满足 长度 >= i , 而且 i 不出现 , 1 --> i - 1 都出现了  

对于 w1 = 0 , 要求任何的长度为 1 的区间的 MEX 都不是 1 
这显然不可能 , 因为一定会有一个 0 
对于任何的 w1 = 1 , 很显然这个是可以的 , 肯定是有一个区间 MEX == 1 
那什么排列情况下 不行呢
我们只要保证 1 -> i - 1 的任意元素有出现在 i 的左右分别两侧 , 
保证任意一个区间只要包含了 1 -> i - 1 , 就一定会包含 i 这样就构造不出来了
或许这个计数就是用排列的数量减去这个  



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> tt ; 
    while ( tt -- ) {
        cin >> n >> c ;   
        string s ; cin >> s ; 
        for ( auto &a : s ) {
            if ( a == '0' ) {
                
            }
            if ( a == '1' ) {

            }
        }   
    }
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/

