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
vector<int> tree ; 
int n , m ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }


void update( int pos , int val ) {
    for( int i = pos ; i <= n ; i += (i & -i) ) 
        tree[i] += val ;
}

int query( int q ) {
    return calRangeSum( q ) ;
}

int calRangeSum( int l , int r ) {
    int suml = 0 , sumr = 0 ;
    // 这里计算的逻辑写错了 是 i > 0 
    // 计算查询的时候是从大到小 所以是 i > 0 
    for ( int i = l ; i > 0 ; i -= (i & -i) )     
        suml += tree[i] ;
    for ( int i = r ; i > 0 ; i -= (i & -i) ) 
        sumr += tree[i] ;
    return sumr - suml ;  
}

void solve() {
    

    
}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
    cin >> n >> m ; 
    vector<int> arr( n + 1 ) ;
    tree.resize( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] , update( i , arr[i] ) ;

    }    
    // for( auto &a : tree ) cout << a << ' ' ;
    while ( m -- ) {
        int op ; cin >> op ;
        if ( op == 1 ) {
            int x , y , k ; cin >> x >> y >> k ;
            update( x , k ) ; 
            if ( y + 1 <= n ) 
                update( y + 1 , k ) ;
        } 
        if ( op == 2 ) {
            int q ; cin >> q ; 
            cout << calRangeSum( q ) << endl ; 
        }
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
