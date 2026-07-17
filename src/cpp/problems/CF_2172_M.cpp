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
#include <utility>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

// ========================== Namespace ========================================
using namespace std;
// using namespace ranges;

// ========================== Macro Definitions ================================
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int, int>
#define TUP tuple<int, int, int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

// ========================== Global Variables / Arrays ========================


// ========================== Functions ========================================



// ========================== Idea =============================================
/*
最后遍历 dis 数组
ans[mp[i]] = min ( ans[mp[i]] , dis[i] )
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int n , m , k ; cin >> n >> m >> k ; 
    vector<int> dis ( n + 1 , INT_MAX / 2 ) , vis ( n + 1 ) , ans ( k + 1 , -1 ) ;
    vector<vector<int>> adj ( n + 1 ) ;
    unordered_map<int , int> mp ;
    for ( int i = 1 ; i <= n ; i ++ ) { int temp ; cin >> temp ; mp[i] = temp ; }
    for ( int i = 1 ; i <= m ; i ++ ) {
        int temp1 , temp2 ; cin >> temp1 >> temp2 ; 
        adj[temp1].push_back( temp2 ) ; adj[temp2].push_back( temp1 ) ; 
    }
    // BFS
    queue<PII> q ; q.emplace( 1 , 0 ) ;
    dis[1] = 0 ; vis[1] = 1 ;
    while ( !q.empty() ) {
        auto [t , cnt] = q.front() ; q.pop() ;
        for ( auto &a : adj[t] ) {
            // 入队检查 cnt计算 vis标记 dis记录
            if ( !vis[a] && cnt + 1 < dis[a] ) { 
                q.emplace( a , cnt + 1 ) ;
                dis[a] = cnt + 1 ; vis[a] = 1 ;
            }    
        }
    }
    for ( int i = 1 ; i <= n ; i ++ ) ans[mp[i]] = max ( ans[mp[i]] , dis[i] ) ;
    for ( int i = 1 ; i <= k ; i ++ ) cout << ans[i] << ' ' ;
    return 0;
}
// ========================== Question =========================================
/*
1 号城市生产的东西没有正确计算
*/
