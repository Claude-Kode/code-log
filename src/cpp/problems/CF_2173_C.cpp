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

void returnAns( vector<int> &ans ) {
    cout << ans.size() << endl ;
    for ( auto &a : ans ) 
        cout << a << ' ' ;
    cout << endl ; 
}

void solve() {
    int n , k ; cin >> n >> k ; 
    vector<int> arr( n ) , ans ; 
    set<int> myset ; 
    unordered_map<int , int> mp ; 
    for ( auto &a : arr ) cin >> a , myset.insert( a ) , mp[a] = 1 ; 
    int cnt = myset.size() , pre_cnt = cnt ; 
    for ( auto &a : myset ) {
        int value = a ; 
        bool mark = false ; 
        while ( value <= k ) {
            if ( mp[value] == 0 ) 
                { cnt = pre_cnt ; break ; }
            if ( mp[value] != -1 ) {
                mark = true ; 
                mp[value] = -1 ;
                cnt -- ; 
            }
            value += a ;
        } 
        if ( mark ) 
            ans.push_back( a ) ; 
        if ( cnt == 0 ) 
            { returnAns( ans ) ; return ; }
        pre_cnt = cnt ; 
    } 
    cout << -1 << endl ; 

}

// ========================== Idea =============================================
/*

" ALL positive multiples " means 
k == 8 , b[j] = 2 : 2 , 4 , 6 , 8 must appear in the a-array

1. find the divisor ? 
2. for each possible ans check it ? 
3. use binary search ? no monotonicity

the possible smallest len means maybe the ans-array filled one by one 

ohhh finding the smallest number of common divisors whose multiples can cover the a-array 

so it must be the ele in a-array because the 1 multipel of b[j] must appear in a-array

we can use set to check and if 

i lost one point --- sort 
the smaller ele always cover more ele 

原来我写出来了卧槽 !!! 哈哈哈哈哈哈哈哈哈

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
