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
第一个是理解题意的问题 是对于所有符合条件的 a[i] 进行操作
这里 hjm 用了 map 自动排序 而且后面的3 * n 直接当数值用相当爽
但是时间不是很好
学吧
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n , k , ans = 0 , mx = 0 ; cin >> n >> k ; 
        vector<int> arr ( n ) ; 
        map<int , int> mp ; 
        for ( auto &temp : arr ) 
             cin >> temp , mp[temp] ++ ; 

        for ( int i = 0 ; i < 3 * n ; i ++ ) {
            ans = max ( ans , mx ) ;
            if ( mp[i] > k )  
                mx ++ , mp[i + 1] += mp[i] - 1 ;
            else 
                mx = 0 ;
        }  
        cout << ans << endl ;
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
