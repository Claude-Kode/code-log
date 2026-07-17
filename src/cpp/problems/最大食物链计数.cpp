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
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned int int
#define PII pair<int , int>
#define TUP tuple<int , int , int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const ll LINF = 1e18 ;
const int MOD = 80112002 ; 
const int MOD2 = 998244353 ; 


// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ;

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
    

    cin >> n >> m ; 
    queue<int> q ; 
    vector<vector<int>> adj( n + 1 ) ; 
    vector<int> indegree( n + 1) ; 
    vector<int> outdegree( n + 1 ) ; 
    vector<int> ans( n + 1 ) ; 
    // 按照 hunter -> prey 的顺序进行排序 图是逆向统计 indegree 的 所以图应该存的是 prey -> hunter
    // indegree[i] 表示 i 的 hunter 有几个
    for ( int i = 1 ; i <= m ; i ++ ) {
        int prey , hunter ; 
        cin >> prey >> hunter ; 
        adj[hunter].push_back( prey ) ;
        indegree[prey] ++ ; 
        outdegree[hunter] ++ ; 
    }
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( !indegree[i] ) {
            q.emplace( i ) ;  
            ans[i] = 1 ;
        }
    }
    
    while ( !q.empty() ) {
        auto cur = q.front() ; q.pop() ; 

        for ( auto &a : adj[cur] ) {
            ans[a] += ans[cur] ;
            ans[a] %= MOD ; 
            if ( !--indegree[a] ) {
                q.emplace( a ) ; 
  
            }
        }
    }

    int res = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( outdegree[i] == 0 ) {
            res += ans[i] ;
            res %= MOD ; 
        }
    }
    cout << res << endl ;
    return 0 ;
}
// ========================== Question =========================================
/*

*/
