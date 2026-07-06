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

}

// ========================== Idea =============================================
/*

这个题体现了我逃避分类讨论 情况判断的废物表现

可能是思路不好 我的思路总是偏向于一次性判断
但是题解的方式是迭代性判断 根据情况进行 加减

这题真你麻痹傻逼卧槽 
不会出别尼玛瞎出这傻逼题草泥马
随便想个情境就往上硬出 傻逼

最后的结果就是 
简单粗暴 能拆的全拆出来就好了


*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n ; cin >> n ; 
        vector<int> arr( n ) , odds , evens ; 
        for ( auto &a : arr ) {
            cin >> a ;
            a & 1 ? odds.push_back( a ) : evens.push_back( a ) ;
        }
        sort( odds.begin() , odds.end() , greater<int>() ) ; 
        sort( evens.begin() , evens.end() , greater<int>() ) ;

        vector<int> pre_evens ( evens.size() + 1 ) ; 
        for ( int i = 1 ; i <= evens.size() ; i ++ ) 
            pre_evens[i] = pre_evens[i - 1] + evens[i - 1] ; 

        if ( odds.empty() ) {
            for ( int i = 1 ; i <= n ; i ++ ) 
                cout << 0 << ' ' ; 
            cout << endl ; 
            continue ; 
        }

        if ( evens.empty() ) {
            for ( int i = 1 ; i <= n ; i ++ ) 
                i & 1 ? cout << odds.front() << ' ' : cout << 0 << ' ' ; 
            cout << endl ; 
            continue ; 
        }

        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( 1 + evens.size() > i ) 
                cout << odds.front() + pre_evens[i - 1] << ' ' ;
            else {
                int rem = i - 1 - evens.size() ; 
                int unusedOdds = odds.size() - 1 ; 
                if ( rem % 2 == 1 && unusedOdds >= rem + 1 ) 
                    cout << odds.front() + pre_evens[evens.size() - 1] << ' '  ;
                else if ( rem % 2 == 1 && unusedOdds < rem + 1 ) 
                    cout << 0 << ' ' ; 
                else 
                    cout << odds.front() + pre_evens.back() << ' ' ;
            }        
        }
        cout << endl ; 

    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/