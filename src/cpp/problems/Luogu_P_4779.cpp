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

int n , m , s ; 

struct edge { 
    int h ; 
    int w ;
    bool operator< ( const edge& other ) const {
        return w > other.w ; 
    }
} ; 

vector<int> dis ; 
vector<int> vis ;
vector<vector<edge>> adj ; 
priority_queue<edge> q ; 

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
    

    cin >> n >> m >> s ;
    dis.resize( n + 1  , INT_MAX ) ; 
    vis.resize( n + 1 , 0 ) ; 
    adj.resize( n + 1 ) ; 
    while ( m -- ) {
        int u , v , w ; cin >> u >> v >> w ; 
        adj[u].push_back( edge{v , w} ) ;
        // adj[v].push_back( edge{u , w} ) ;
    } 

    dis[s] = 0 ; 
    q.emplace( edge{s , 0} ) ; 
    while ( !q.empty() ) {
        auto [t , w] = q.top() ; q.pop() ; 
        if ( vis[t] ) continue ; 
        vis[t] = 1 ;
        for ( auto &[tt , ww] : adj[t] ) {
            if ( dis[tt] > dis[t] + ww ) {
                dis[tt] = dis[t] + ww ; 
                q.emplace( edge{tt , dis[tt]} ) ; 
            }
        }
    } 

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << dis[i] <<  ' ' ;
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/


