// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define endl '\n'
// #define int long long
// #define ll long long
// #define ull unsigned long long
// #define PII pair<int , int>
// #define TUP tuple<int , int , int>
// #define elif else if 
// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const ll LINF = 1e18 ;
// const int MOD = 1e9 + 7 ;
// const int MOD2 = 998244353 ;

// // ========================== Global Variables / Arrays ========================

// vector<int> fri ; 
// vector<int> ene ; 
// vector<int> ranks ; 

// // ========================== Functions ========================================

// void init ( int n ) {
//     fri.resize( n + 1 ) , ranks.resize( n + 1 ) , ene.resize( n + 1 ) ;
//     for ( int i = 1 ; i <= n ; i ++ ) 
//         ranks[i] = 1 , fri[i] = i , ene[i] = 0 ; 

// }

// int Find ( int a ) {
//     if ( fri[a] == a ) 
//         return a ; 
//     else 
//         return fri[a] = Find( fri[a] ) ;
// }

// bool isSame( int a , int b ) {
//     int ra = Find( a ) ;
//     int rb = Find( b )  ;
//     return ra == rb ; 
// }

// void join( int a , int b ) {
//     int ra = Find( a ) ; 
//     int rb = Find( b ) ;
//     if ( ra == rb ) return ; 
    
//     if ( ranks[ra] <= ranks[rb] ) 
//         fri[ra] = rb ; 
//     else 
//         fri[rb] = ra ;

//     if ( ranks[ra] == ranks[rb] ) 
//         ranks[rb] ++ ; 

// }  

// void solve() {
    
// }

// // ========================== Idea =============================================
// /*

// 如果是朋友直接把两个人进行合并 
// 如果是敌人 把 a 的根节点和 b 的敌人的根节点进行合并
// 那么敌人的根节点怎么表示的呢

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
//     int n ; cin >> n ; 
//     init( n ) ; 
//     int tt ; cin >> tt ; 
//     while ( tt -- ) {
//         int a , b ; string rel ; 
//         cin >> rel >> a >> b ;
//         if ( rel == "F" ) 
//             join( a , b ) ; 
//         else {
//             // 如果 a 没有敌人 那么 a 的敌人应该设置为 b 的朋友根节点
//             if ( ene[a] == 0 ) 
//                 ene[a] = Find( b ) ; 
//             // 如果 a 有敌人 那么对 b 来说 a 的敌人就是 b 的朋友
//             // 因为之前你添加进 ene 的元素都是朋友集合的根节点 也就是说 ene[a] 代表的是 a 的所有敌人的那个集合 的根节点
//             // 所以说 ene[a] 能代表 a 的所有敌人
//             // 根据敌人的敌人是朋友 先把 a 的敌人 跟 b 交朋友 也就是合并
//             else
//                 join( ene[a] , b ) ; 

//             if ( ene[b] == 0 )
//                 ene[b] = Find( a ) ;
//             else 
//                 join( ene[b] , a ) ; 

//         }
//     }
//     // 最后是要算 朋友集合有多少个人 遍历朋友集合 只要不是自己 就说明他有朋友
//     int cnt = 0 ;
//     for ( int i = 1 ; i <= n ; i ++ ) 
//         if ( fri[i] == i ) cnt ++ ; 
//     cout << cnt << endl ; 
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */

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
const ll LINF = 1e18 ;

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ; 
vector<int> fri ; 
vector<int> ene ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    ene.resize( n + 1 , 0 ) ; 
    fri.resize( n + 1 , 0 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) 
        fri[i] = i ; 
}

int Find( int a ) {
    a == fri[a] ? a : fri[a] = Find( fri[a] ) ; 
} 

void merge( int a , int b ) {
    int fa = Find( a ) , fb = Find( b ) ; 
    if ( fa == fb ) return ; 
    fri[fa] = fb ;
}
 
void solve() {
     
    char opt ; int a , b ; 
    cin >> opt >> a >> b ; 
    if ( opt == 'F' ) 
        merge( a , b ) ; 
    if ( opt == 'E' ) {
        ene[a] = Find( b ) ; 
        ene[b] = Find( a ) ; 
        if ( ene[a] != 0 ) 
            merge( Find(a) , b ) ;
        if ( ene[b] != 0 ) 
            merge( a , Find(b) ) ; 
    }

    int cnt = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cnt += fri[i] == i ; 
    }

    cout << cnt << endl ;

}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n >> m ; 
    while ( m -- ) solve() ; 
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/
