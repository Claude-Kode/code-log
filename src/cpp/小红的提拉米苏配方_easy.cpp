/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
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
#include <list>
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define TUP tuple<int , int , int>
#define ull unsigned long long
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD1 = 998244353 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

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

贪心的想 , 一定要把能删掉的 1 删掉

如果一个 1 后面是 0 , 那么往后面找一个 1 变成 2 , 然后删除前面的 1 
如果一个 1 后面是 1 , 不用管 , 
如果一个 1 后面是 1 , 他不能被删掉

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
 
    int cnt1 = 0 ; 
    for ( auto &a : str ) { cnt1 += (a == '1' ) ; }

    if ( cnt1 & 1 ) {

        int change = cnt1 / 2 ;

        int stay1 = INT_MAX , stay2 = INT_MAX , stay3 = INT_MAX ;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( i < n - 1 && str[i] == '1' && str[i + 1] == '0' ) stay1 = min( stay1 , i ) ;
            if ( i < n - 1 && str[i] == '1' && str[i + 1] == '2' ) stay2 = min( stay2 , i ) ; 
            if ( i < n && str[i] == '1' ) stay3 = min( stay3 , i ) ; 
        } 

        int stay = min({ stay1 , stay2 , stay3 }) ; 

        for ( int i = n - 1 ; i >= 0 ; i -- ) {
            if ( change && i != stay && str[i] == '1' ) {
                str[i] = '2' ; 
                change -- ; 
            }
        }

        // cout << stay << ' ' ;

        for ( int i = 0 ; i < n ; i ++ ) {
            if ( str[i] == '1' && i != stay ) continue ;
            cout << str[i] ;
        }

    } else {
        int change = cnt1 / 2 ; 
        for ( int i = n - 1 ; i >= 0 ; i -- ) {
            if ( change && str[i] == '1' ) {
                str[i] = '2' ; 
                change -- ; 
            }
        }
        for ( auto &a : str ) {
            if ( a != '1' ) cout << a << ' ' ;
        } 
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/

