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

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ; 
int ans = 0 ; 
int sum = 0 ; 

vector<int> dis ;
vector<int> vis ;
vector<vector<PII>> adj ; 

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
    dis.resize(n + 1 , INF) ;
    vis.resize(n + 1) ;
    adj.resize(n + 1) ; 

    int sum = 0 ; 
    while ( m-- ) {
        int u , v , w ; 
        cin >> u >> v >> w ; 
        sum += w ; 
        adj[u].emplace_back( v , w ) ;
        adj[v].emplace_back( u , w ) ; 
    } 

    int cnt = 1 , now = 1 ; vis[1] = 1 ; dis[1] = 0 ; 
    for ( auto &[v , w] : adj[1] ) {
        dis[v] = min( dis[v] , w ) ; 
    }
    while ( cnt < n ) {
        int min_dis = INF ; 
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( !vis[i] && min_dis > dis[i] ) {
                now = i ; 
                min_dis = dis[i] ;
            }
        } 

        vis[now] = 1 ; 
        ans += min_dis ;
        cnt++ ; 

        for ( auto &[v , w] : adj[now] ) {
            dis[v] = min( dis[v] , w ) ; 
        }

    }

    cout << sum - ans << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/
