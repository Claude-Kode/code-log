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
    vector<int> arr( n + 1 ) ;
    int mx = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
        mx = max( mx , arr[i] ) ;
        if ( i % 2 == 0 ) 
            arr[i] = mx ; 
    }
    int cnt = 0 ; 
    arr[0] = INT_MAX ; arr.push_back( INT_MAX ) ;
    for ( int i = 1 ; i <= n ; i += 2 )
        if ( arr[i - 1] <= arr[i] || arr[i] >= arr[i + 1] )
            cnt += arr[i] - min( arr[i - 1] , arr[i + 1] ) + 1 ; 
    cout << cnt << endl ; 
}

// ========================== Idea =============================================
/*

如果一个奇数位置的数字大于大后面的数字
就应该执行操作 1 同时 cnt ++ 

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    // int tt ; cin >> tt ; 
    // while ( tt -- ) solve() ; 

    stringstream ss ; 
    string str ; 
    ss >> str ; 
    ss << str ; 
    return 0 ;
}
// ========================== Question =========================================
/*

*/
