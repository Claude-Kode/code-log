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

unordered_map<int , int> fri ;

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

int Find( int a ) {
    return a == fri[a] ? a : fri[a] = Find( fri[a] ) ;
}

void merge ( int a , int b ) {
    int pa = Find(a) , pb = Find(b) ; 
    if ( pa == pb ) return ; 
    fri[pa] = pb ;

}

bool isSame( int a , int b ) {
    return Find(a) == Find(b) ; 
}

void solve() {
    
    fri.clear() ;
    int n ; cin >> n ; 
    deque<TUP> Data ; 
    for ( int k = 0 ; k < n ; k ++ ) {
        int i , j , e ; cin >> i >> j >> e ; 
        fri[i] = i , fri[j] = j ; 
        e == 1 ? Data.emplace_front( i , j , e ) : Data.emplace_back( i , j , e ) ; 
    }
    for ( auto &[i , j , e] : Data ) {
        if ( e == 1 ) {
            merge( i , j ) ; 
        } else if ( isSame(i , j) ) {
            cout << "NO" << endl ; 
            return ; 
        }
    }
    cout << "YES" << endl ; 

}

// ========================== Idea =============================================
/*

数据过大 要用哈希表 而且记得初始化 这一步可以在 cin 阶段实现
还有这里面不存在 敌人的敌人是朋友 这种传递关系
最重要的就是这个处理的先后顺序

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
