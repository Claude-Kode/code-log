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
    string s ; cin >> s ; 
    int cnt1 = 0 , cnt2 = 0 ; 
    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( s[i] == '<' ) cnt1 ++ ; 
        if ( s[i] == '>' ) cnt2 ++ ; 
        if ( i < s.size() - 1 && s[i] != '<' && s[i + 1] != '>' ) { cout << -1 << endl ; return ; }
        // if ( s[i] == '*' && ( s[i + 1] == '*' || s[i + 1] == '<' ) ) {
        //     cout << -1 << endl ; return ; 
        // }
        // else if ( s[i] == '>' && ( s[i + 1] == '*' || s[i + 1] == '<' ) ) {
        //     cout << -1 << endl ; return ; 
        // }
    } 

    // cout << cnt1 << ' ' << cnt2 << endl ;
    // 错误的地方在最后的 res 计算这里 
    // 我的原本是
    // int res = max ( cnt , (int)(s.size() - cnt1) ) cnt 是 左括号的数量
    // 这样的错误就是 <<<<<<<<*> 的时候 八个左括号漏掉了中间的 * 
    int res = max ( (int)(s.size() - cnt1) , (int)(s.size() - cnt2) ) ;
    cout << res << endl ;
}

// ========================== Idea =============================================
/*

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
