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
#define int double
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD2 = 998244353 ; 
const int MOD = 1e9 + 7 ; 
const ll LINF = 1e18 ;
const int maxn = 2e5 + 5 ;

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ; 

vector<int> parent( maxn ) , siz( maxn , 1 ) , weight( maxn ) ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    for ( int i = 1 ; i <= n ; i ++ ) 
        cin >> weight[i] , parent[i] = i ; 
}

int Find( int a ) {
    return parent[a] == a ? a : parent[a] = Find( parent[a] ) ;
}

void merge( int a , int b ) {
    int pb = Find(b) ;
    for ( int i = a ; i < b ; i ++ ) {
        int pa = Find( i ) ;
        if ( pa == pb ) break ;
        parent[pa] = pb ; 
        weight[pb] += weight[pa] ;
        siz[pb] += siz[pa] ;
        i = Find(pa + 1) ;
    }
}

void solve() {
     


}

// ========================== Idea =============================================
/*

带权并查集

*/
// ========================== Main Function ====================================
signed main() {
    cout << fixed << setprecision( 8 ) ;
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;

    cin >> n >> m ;
    init() ;
    while ( m --) {
        int op ; cin >> op ;
        if ( op == 1 ) {
            int l , r ; cin >> l >> r ;
            merge( l , r ) ;
        } else {
            int i ; cin >> i ;
            int die = Find(i) ;
            cout << weight[die] / siz[die] << endl ;
        }
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
