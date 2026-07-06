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
    int n , k ; cin >> n >> k ; 
    if ( n * n - k == 1  ) { cout << "NO" << endl ; return ; }
    cout << "YES" << endl ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( k --> 0 )
                cout << 'U' ;
            else if ( i == n - 1 && j == n - 1 )
                cout << 'L' ;
            else if ( i == n -1 ) 
                cout << 'R' ;
            else 
                cout << 'D' ; 
        }
        cout << endl ; 
    }
}

// ========================== Idea =============================================
/*

这道题不会存在少于 k 的情况 只有可能多

三个样例分别对应 全部 一半 剩一个

好像可以证明只有 剩下的只有一个的时候才能会输出 NO

代码写不明白啊好fw 

还是策略没捋清楚 不够同一性 就是不能一直执行下去那种

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
