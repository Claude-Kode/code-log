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
int res = 0 ; 
vector<int> memo ; 
vector<int> indegree ; 
vector<int> outdegree ; 
vector<vector<int>> adj ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void solve() {
     


}

int DFS ( int cur ) {

    // 递归边界这一点没搞清楚 一开始还随身携带 sum 了
    if ( outdegree[cur] == 0 ) {
        // return 1 但是没有赋值给 memo 
        // 后果是什么 ? 
        return memo[cur] = 1 ; 
    }

    if ( memo[cur] != -1 ) {
        return memo[cur] ;
    }

    int cnt = 0 ; 
    for ( auto &hunter : adj[cur] ) {
        // 一开始写成 memo[hunter] = DFS( i , sum + 1 )
        // 后来又改错了 改成 memo[hunter] = DFS( i ) ; 
        cnt += DFS( hunter ) % MOD ;
        // memo[cur] += 
    }

    // 这里没写返回值
    return memo[cur] = cnt ; 

}


// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n >> m ; 
    adj.resize( n + 1 ) ;
    // 为啥要初始化 -1
    memo.resize( n + 1 , -1 ) ; 
    indegree.resize( n + 1 ) ; 
    outdegree.resize( n + 1 ) ;

    // directed edge from prey to hunter 
    // 
    while( m -- ) {
        int prey , hunter ; 
        cin >> prey >> hunter ; 

        indegree[hunter] ++ ; 
        outdegree[prey] ++ ; 
        adj[prey].push_back( hunter ) ;

    }
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( indegree[i] == 0 ) {
            res += DFS( i ) % MOD ; 
        }
    }

    cout << res % MOD ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/



// void DFS ( int cur , int sum ) {

//     // 递归边界这一点没搞清楚 一开始还随身携带 sum 了
//     if ( outdegree[cur] == 0 ) {
//         return sum ; 
//     }

//     if ( memo[cur] ) {
//         return memo[cur] ;
//     }

//     int cnt = 0 ; 
//     for ( auto &hunter : adj[cur] ) {
//         return DFS( hunter , sum + 1 ) ; 
//     }

// }

// vector<int> arr ; 
// vector<int> ans ; 
// // 这种填充答案型经常要搭配去重操作
// vector<bool> ele ; 
// vector<vector<int>> res ; 
// void DFS( int step , vector<int> ans ) {
//     // 递归边界
//     if ( step == n ) {
//         res.push_back( ans ) ; 
//         return ; 
//     }

//     for ( auto &a : arr ) {
//         if ( ele[a] != false ) {
//             // 填充答案 + 去重标记
//             ans.push_back( a ) ; 
//             ele[a] = true ; 

//             DFS( step + 1 , ans ) ; 

//             // 还原现场 既然这个位置不选 a 了 , 那么后面的位置是可以选 a 的
//             ans.pop_back() ;
//             ele[a] = false ;  
//         }
//     }
// }


// if ( ans 不符合条件 ) {
// 	return ;  
// }


// vector<int> questions ; 
// int DFS( int q ) {
//     // 如果 q 的规模是边界
//     if ( q == limit ) {
//         // return 边界的答案
//         return 1 ; 
//     }

//     if ( memo[q] != -1 ) {
//         return memo[q] ; 
//     }

//     for ( auto & subQuestion : questions[q] ) {
//         memo[q] += DFS( subQuestion ) ; 
//     }
    
//     return memo[q] ; 
    
// }