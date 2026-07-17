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
unordered_map<string , string> father ;
// unordered_map<string , int> ranks ;  

// ========================== Functions ========================================

string ufind ( string a ) {
    if ( father[a] == a ) return a ;
    return father[a] = ufind( father[a] ) ; 
}

// ========================== Idea =============================================
/*
这道题没有具体的数字 要自己建立映射关系
感觉可以用 ump 写 
key == name , value = fahter 
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    string temp , fa ; 
    char ch ; 
    while ( cin >> ch >> temp ) {
        // father 
        if ( ch == '#' ) 
            if ( father.count( temp ) == 0 ) 
                 father[temp] = temp , fa = temp ;
            else 
                fa = temp ; 
        // son
        if ( ch == '+' ) 
            father[temp] = fa ;
        // query
        if ( ch == '?' )
            cout << temp << ' ' << ufind( temp ) << endl ;

    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
