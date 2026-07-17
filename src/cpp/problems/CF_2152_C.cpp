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
    
    int n , q ; cin >> n >> q ; 
    vector<int> arr( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ;
    vector<int> pre( n + 1 ) , same( n + 1 ) , preSame( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        pre[i] = pre[i - 1] + arr[i] ;
        same[i] = arr[i] == arr[i - 1] ;
        preSame[i] = preSame[i - 1] + same[i] ;  
    }

    // debug
    // for ( auto &a : arr ) cout << a << ' ' ; 
    // cout << endl ;

    // for ( auto &a : pre ) cout << a << ' ' ; 
    // cout << endl ;
    
    // for ( auto &a : same ) cout << a << ' ' ; 
    // cout << endl ;
    
    // for ( auto &a : preSame ) cout << a << ' ' ; 
    // cout << endl ;
        int l , r ;

    while ( q -- ) {
        cin >> l >> r ;
        int len = r - l + 1 ;
        int cnt_1 = pre[r] - pre[l - 1] ;
        int cnt_0 = len - cnt_1 ;
        if ( len % 3 != 0 || cnt_1 % 3 != 0 ) {
            cout << -1 << endl ; continue ; 
        }

        int res = len / 3 ; 
        if ( preSame[r] == preSame[l] ) {
            res ++ ; 
        }            
        cout << res << endl ;

    }

}

// ========================== Idea =============================================
/* 

思路错了 还是要多画图不能想当然 
000 1 000 1 000 1 的最小低价并不是彻底消除某一方 其实是只要相邻直接消除就对了
这道题的 delete op 有后续性质 即删除后会造成原本不相邻的数字相邻
不过我的想法还是很有进步的 有点特殊到一般的那种感觉了 不错啊

从这以后题目的关键状态转化成相邻 直接讨论极端 有一对元素相邻和没有任何一对元素相邻
如果没有任何一对是相邻的 代价就是 len 


用 diff[i] 来表示 i 与之前一个是否相同 
然后用前缀和区间查询 这是一个很聪明的trick 
前缀和的作用是累加 然后区间查询 前缀和简直妙用无穷啊

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
