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

int n , m ; 

vector<vector<int>> tree ;
vector<vector<int>> arr ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

int lowbit( int i ) { return i & -i ; }

void init() {
    tree.resize( n + 1 , vector<int>(n + 1)) ; 
    arr.resize( n + 1 , vector<int>(n + 1)) ; 
}

void update( int posx , int posy , int val ) {
    for ( int i = posx ; i <= n ; i += lowbit(i) ) {
        for ( int j = posy ; j <= n ; j += lowbit(j) ) {
            tree[i][j] += val ; 
        } 
    }
}

int query( int posx , int posy ) {
    int res = 0 ;
    for ( int i = posx ; i > 0 ; i -= lowbit(i) ) {
        for ( int j = posy ; j > 0 ; j -= lowbit(j) ) {
            res += tree[i][j] ; 
        }
    }
    return res ;
} 

void solve() {
     


}

// ========================== Idea =============================================
/*

二维的树状数组应该是往前存 lowbit(x) * lowbit(y) 这个面积的内部的元素和 

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n >> m ;
    init() ; 
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            cin >> arr[i][j] ; 
            update( i , j , arr[i][j] ) ; 
        }
    }
    
    while( m -- ) {
        int op ; cin >> op ; 
        if ( op == 1 ) {
            int x , y ; cin >> x >> y ; 
            update( x , y , arr[x][y] == 1 ? -1 : 1 ) ; 
            // 忘了更新数组
            arr[x][y] ^= 1 ; 
        }
        if ( op == 2 ) {
            int x1 , y1 ; cin >> x1 >> y1 ; 
            int x2 , y2 ; cin >> x2 >> y2 ; 
            cout << query( x2 , y2 ) - query( x2 , y1 - 1 ) - query( x1 - 1 , y2 ) + query( x1 - 1 , y1 - 1 ) << endl ; 
        }
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/
