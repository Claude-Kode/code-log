// // /*
// //  * @Author: GoryK
// //  * @Date: Doomsday
// //  * @Description: TEMPLATE
// //  */

// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")

// // // ========================== Header Files =====================================
// // #include <unordered_map>
// // #include <unordered_set>
// // #include <algorithm>
// // #include <iostream>
// // #include <cstdlib>
// // #include <cstring>
// // #include <iomanip>
// // #include <numeric>
// // #include <sstream> 
// // #include <utility>
// // #include <bitset>
// // #include <chrono>
// // #include <random>
// // #include <string>
// // #include <vector>
// // #include <array>
// // #include <cmath>
// // #include <deque> 
// // #include <queue>
// // #include <stack>
// // #include <list>
// // #include <map>
// // #include <set>

// // // ========================== Namespace ========================================
// // using namespace std ;
// // // using namespace ranges ;

// // // ========================== Macro Definitions ================================
// // #define TUP tuple<int , int , int>
// // #define ull unsigned int int
// // #define PII pair<int , int>
// // #define int long long
// // #define ll long long
// // #define endl '\n'

// // // ========================== Constants ========================================
// // const int INF = 0x3f3f3f3f3f3f3f3f ;
// // const int MOD2 = 998244353 ; 
// // const int MOD = 1e9 + 7 ; 
// // const int maxn = 1e9 ; 

// // // ========================== Global Variables / Arrays ========================

// // // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // // unordered_set<int> st ;



// // // ========================== Functions ========================================


// // // int rand_num( int l , int r, bool unique = false) {
// // //     while (1) {
// // //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// // //         if ( !unique || st.insert(x).second ) return x ;
// // //     }
// // // }

// // void solve() {
     


// // }

// // // ========================== Idea =============================================
// // /*



// // */
// // // ========================== Main Function ====================================
// // signed main() {
// //     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

// //     int n , m , q ; cin >> n >> m >> q ; 
// //     int exp = __lg( m ) ; 
// //     vector<vector<vector<int>>> st( exp + 1 , vector<vector<int>>( n , vector<int>( m ))) ;
// //     for ( int i = 0 ; i < n ; i ++ ) {
// //         for ( int j = 0 ; j < m ; j ++ ) {
// //             cin >> st[0][i][j] ;
// //         }
// //     }

// //     for ( int row = 0 ; row < n ; row ++ ) {
// //         for ( int e = 1 ; e <= exp ; e ++ ) {
// //             for ( int col = 0 ; col + (1 << e) - 1 < m ; col ++ ) {
// //                 // st[e - 1][row][col - (1 << exp) + 1]
// //                 st[e][row][col] = min( st[e - 1][row][col] , st[e - 1][row][col + (1 << (e - 1))] ) ; 
// //             }
// //         }
// //     }


// //     auto check = [&]( int test ) -> bool {
// //         // cout << "test : " << test << endl ; 
// //         int limRow = n - test ; 
// //         int limCol = m - test ; 
// //         int exp = __lg( test ) ; 
// //         // cout << "正方形的长度是 : " << test << endl ;  
// //         // row of the start
// //         for ( int i = 0 ; i <= limRow ; i ++ ) {
// //             // col of the start
// //             for ( int j = 0 ; j <= limCol ; j ++ ) {
// //                 // cout << "起点是 : " << i << ' ' << j << endl ;  
// //                 // 到这里是枚举正方形的左上角 接下来枚举正方形的所有横行
// //                 int mn = INF ; 
// //                 // cout << "666 : " << mn << endl ; 
// //                 // rows of the grid 
// //                 for ( int ii = i ; ii <= i + test - 1 ; ii ++ ) {
// //                     mn = min({ mn , st[exp][ii][j] , st[exp][ii][j + test - 1 - (1 << exp) + 1] }) ; 
// //                     // cout << "最小值是 : " << mn << endl ; 

// //                 }
// //                 // cout << "最小值是 : " << mn << endl ; 

// //                 if ( mn >= q ) return true ; 
// //             }
// //         }

// //         return false ; 

// //     } ;

// //     int l = 1 , r = min( n , m ) , ans = l ;
// //     while ( l <= r ) {
// //         int mid = ( l + r ) / 2 ; 
// //         check(mid) ? l = mid + 1 , ans = mid : r = mid - 1 ; 
// //         // cout << endl << endl ; 
// //     }

// //     // if ( check(2) ) cout << "666" << endl ; 
    
// //     cout << ans << endl ; 

// //     return 0 ;
// // }
// // // ========================== Question =========================================
// // /*

// // */




/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

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
#include <list>
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define TUP tuple<int , int , int>
#define ull unsigned int int
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD2 = 998244353 ; 
const int MOD = 1e9 + 7 ; 
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



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int n , m , q ; cin >> n >> m >> q ; 
    int exp = __lg( m ) ; 
    vector<vector<vector<int>>> st( exp + 1 , vector<vector<int>>( n , vector<int>( m ))) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> st[0][i][j] ;
        }
    }

    for ( int row = 0 ; row < n ; row ++ ) {
        for ( int e = 1 ; e <= exp ; e ++ ) {
            for ( int col = 0 ; col + (1 << e) - 1 < m ; col ++ ) {
                st[e][row][col] = min( st[e - 1][row][col] , st[e - 1][row][col + (1 << (e - 1))] ) ; 
            }
        }
    }

    auto check = [&]( int test ) -> bool {
        int limRow = n - test ; 
        int limCol = m - test ; 
        int exp = __lg( test ) ; 
        for ( int i = 0 ; i <= limRow ; i ++ ) {
            for ( int j = 0 ; j <= limCol ; j ++ ) {

                int mn = INF ; 
                int r = j + test - 1 ;
                for ( int ii = i ; ii <= i + test - 1 ; ii ++ ) { 
                    mn = min({ mn , st[exp][ii][j] , st[exp][ii][r - (1 << exp) + 1] }) ; 
                } 
                if ( mn >= q ) return true ; 

            }
        }

        return false ; 

    } ;

    int l = 1 , r = min( n , m ) , ans = l ;
    while ( l <= r ) {
        int mid = ( l + r ) / 2 ; 
        check(mid) ? l = mid + 1 , ans = mid : r = mid - 1 ; 
    }

    
    cout << ans << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/


/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

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
#include <list>
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define TUP tuple<int , int , int>
#define ull unsigned int int
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD2 = 998244353 ; 
const int MOD = 1e9 + 7 ; 
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



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int n , m , k ; cin >> n >> m >> k ; 
    vector<vector<int>> arr( n + 1 , vector<int>( m + 1 )) ; 
    vector<vector<int>> pre( n + 1 , vector<int>( m + 1 )) ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            cin >> arr[i][j] ; 
            arr[i][j] = arr[i][j] >= k ;  
        }
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + arr[i][j] - pre[i - 1][j - 1]; 
            // cout << pre[i][j] << ' ' ; 
        }
        // cout << endl ; 
    }

    auto check = [&]( int test ) -> bool {
        int limRow = n - test + 1 ; 
        int limCol = m - test + 1 ; 
        for ( int i = 1 ; i <= limRow ; i ++ ) {
            for ( int j = 1 ; j <= limCol ; j ++ ) {
                int total = pre[i + test - 1][j + test - 1] - pre[i - 1][j + test - 1] - pre[i + test - 1][j - 1] + pre[i - 1][j - 1];
                // cout << "total : " <<  total << endl ; 
                if ( total == test * test ) return true ; 
            }
        }
        return false ; 
    } ; 

    int l = 1 , r = min( n , m ) , ans = 1 ;
    while ( l <= r ) {
        int mid = ( l + r ) / 2 ;
        check(mid) ? l = mid + 1 , ans = mid : r = mid - 1 ;
    }

    cout << ans << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/
