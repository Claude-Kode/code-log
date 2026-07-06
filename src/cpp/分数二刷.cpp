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
int gcd ( int a , int b ) { return a ? gcd ( b , a % b ) : b ; }
int fp ( int base , int exp ) {
    int ans = 1 ;
    while ( exp ) {
        if ( exp & 1 ) ans *= base ;   
        exp >>= 1 ;
        base *= base ; 
    }
    return ans ;
}
void solve () {
        double n ; cin >> n ; 
        // if ( n == 0 ) { cout << "0/0" < endl ; return ; }
        int num = round ( n * 1000000 ) ;
        int res = gcd( num , 1000000 ) ; 
        cout << num / res << '/' << 1000000 / res << endl ;
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
