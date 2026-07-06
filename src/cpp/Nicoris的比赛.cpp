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
对于每一个同学 统计他的右侧比他高的就是他输掉的
统计他左侧的就是他赢得的
但是仔细想一下 比赛是相互的 所以其实就是直接排序 艹
查第一个等于他的元素的位置 查找第一个比他大的元素的位置
用hashmap存一下 元素数值的输赢数值 然后用 arr[i] 查
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n ; cin >> n ; 
        vector<int> arr ( n ) , cpy_arr ( n ) ;
        for ( int i = 0 ; i < n ; i ++ ) { cin >> arr[i] ; cpy_arr[i] = arr[i] ; }
        unordered_map<int , PII> ans ; 
        // ans < value , pair< win , lose>> 
        sort ( cpy_arr.begin() , cpy_arr.end() ) ;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( !ans.count( cpy_arr[i] ) ) {
                int start = lower_bound( cpy_arr.begin() , cpy_arr.end() , cpy_arr[i] ) - cpy_arr.begin() ;
                int end = cpy_arr.end() - lower_bound( cpy_arr.begin() , cpy_arr.end() , cpy_arr[i] + 1 ) ;
                ans[cpy_arr[i]] = { start , end } ; 
            }
        }
        for ( int i = 0 ; i < n ; i ++ ) cout << ans[arr[i]].first << ' ' ; 
        cout << endl ;
        for ( int i = 0 ; i < n ; i ++ )  cout << ans[arr[i]].second << ' ' ;  
        cout << endl ; 
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
