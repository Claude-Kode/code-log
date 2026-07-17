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

struct edge{
    int u ;
    int v ;
    int w ; 
} ; 

int n , m ; 
int ans = 0 ; 

vector<int> father ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

int Find( int a ) {
    return a == father[a] ? a : father[a] = Find( father[a] ) ;  
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
    //  init part 
    father.resize( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        father[i] = i ; 
    }

    vector<edge> edges( m ) ; 
    for ( auto &[u , v , w] : edges ) {
        cin >> u >> v >> w ; 
    }

    sort( edges.begin() , edges.end() , []( edge a , edge b ) {
        return a.w < b.w ; 
    }) ;    
    
    int cnt = 0 ; 
    for ( int i = 0 ; i < m ; i ++ ) {
        int fu = Find( edges[i].u ) ;
        int fv = Find( edges[i].v ) ; 
        if ( fu != fv ) {
            father[fu] = fv ;
            ans += edges[i].w ; 
            cnt++ ; 
        }
        if ( cnt == n - 1 ) {
            break ; 
        }
    }


    // if ( cnt < n - 1 ) {
    //     cout << "orz" << endl ; 
    //     return 0 ; 
    // }
    // 或者这样
    int setsCnt = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        setsCnt += Find( i ) == i ; 
    }
    if ( setsCnt != 1 ) {
        cout << "orz" << endl ; 
        return 0 ; 
    }

    cout << ans << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/

