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

vector<int> subsz ;      
vector<vector<int>> son ;      
vector<vector<int>> graph ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

int DFS( int u , int v , int sz ) {

    son[u].push_back( v ) ; 

    for ( auto &to : graph[v] ) {
        if ( to != u  )  { 
            sz += DFS( v , to , 1 ) ;
        } 
    }

    return subsz[v] = sz ; 

}

void solve() {
     
    int n ; cin >> n ; 

    son.clear() ;
    graph.clear() ;
    subsz.clear() ;

    son.resize( n + 1 ) ;
    graph.resize( n + 1 ) ;
    subsz.resize( n + 1 ) ; 

    for ( int i = 1 ; i < n ; i ++ ) {
        int u , v ; cin >> u >> v ; 
        graph[u].push_back( v ) ; 
        graph[v].push_back( u ) ;
    }

    DFS( 1 , 1 , 0 ) ; 

    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        bool perfect = true ; int in = n - 1 ;
        for ( auto &a : son[i] ) {
            if ( (subsz[a] & 1) == 0 ) { perfect = false ; break ; }
            in -= subsz[a] ; 
        }
        cnt += (perfect && (in & 1) || !in ) ; 
    } 

    cout << cnt << endl ; 

}

// ========================== Idea =============================================
/*

遍历节点 , 对该节点的子节点搜索
搜索这些子节点为根的子树大小

这种属于暴力 , 应该是不行的

我这个思路是很自然的 , 我们来看看能不能优化

首先这个图肯定要至少被遍历一次 , 
我们看看这个树 , 如果删掉一个节点 求剩余的联通分量的话
你会发现 , 这些个联通分量 , 有的是他的子树 , 有的是他的父节点上下的那个一坨
注意 , 那一坨是只有一坨,而且节点的数量是固定的, 也就是说我们求出=这一坨之外的所有部分 , 这一坨是多少我们也知道了

所以这个甚至不用优化 , 天然就符合一次便利出结果的想法

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt -- ) solve() ; 
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/

