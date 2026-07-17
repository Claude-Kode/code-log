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

int n ;

struct edge { int v ; int w ; } ;
 
// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void DFS( int v , int w , vector<vector<edge>> &adj , vector<int> &ans , vector<int> &vis ) {

    // 因为存的是无向边 , 判断根节点的特征就是度数为 1 即可
    // 这里还要判断一下是不是根节点 1
    // 如果图是 1 --> 2 的话 , 1 会被判断成叶子节点 , 这样最小的距离是 0 , 是错误的
    if ( adj[v].size() == 1 && v != 1) {
        ans.push_back( w ) ;  
        return ; 
    }

    for( auto &[vv , ww] : adj[v] ) {
        if ( !vis[vv] ) {
            vis[vv] = 1 ;  
            DFS( vv , ww + w , adj , ans , vis ) ;  
            // 这道题不用回溯标记状态 , 只要避免重复访问就可以
            // 因为一个节点的路径 只有一条 , 也不会有更优解 , 访问完了就是访问完了
        }
    }

}

void solve() {
     


}

// ========================== Idea =============================================
/*

一开始写的时候 我首先是想写 BFS , 然后写一个 dp 数组之后递推 , 后面直接取数组的最大值最小值记录即可
其实这个方法也能写 , 但是要提前记录叶子节点 , 而且没有必要 , 因为 这一一棵树 , 没有环 , 任意两点只有一条路径
所以 DFS + 回溯是最适合的方法

第一 , 我一开始没有加vis 数组进行标记
第二 , 我一开始存的是无向边 , 
第三 , 我的递归边界判断错误 , 
第四 , 对于只有一个单一的节点我没有特判

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt -- ) {

        cin >> n ; 
        
        if ( n == 1 ) { cout << 0 << endl ; continue ; }
        
        vector<int> ans ; 
        vector<int> vis( n + 1 ) ; 
        vector<vector<edge>> adj( n + 1 );  
        
        for ( int i = 1 ; i <= n - 1 ; i ++ ) {
            int u , v , w ; cin >> u >> v >> w ; 
            // 为什么要存无向边 , 因为其实很简单 , 树是具有无根性的
            // 每个阶段都可以作为根节点 , 如果你存有向边 , 在一条路径中有一个节点的边给你是反着给的
            // 就像这样 1 --> 2 --> 3 <-- 4 , 这你不炸了吗
            adj[u].emplace_back( edge{ v , w } ) ;
            adj[v].emplace_back( edge{ u , w } ) ;
        }  

        vis[1] = 1 ;   
        DFS( 1 , 0 , adj , ans , vis ) ; 

        int mx = LLONG_MIN ; 
        int mn = LLONG_MAX ; 

        for ( auto &a : ans ) {
            mx = max( mx , a ) ;
            mn = min( mn , a ) ;
        }

        cout << mx - mn << endl ; 

    }
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/

