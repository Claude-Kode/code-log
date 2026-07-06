// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <climits>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque> 
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int , int , int>
// #define ull unsigned long long
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD1 = 998244353 ; 
// const int MOD2 = 1e9 + 7 ; 
// const int maxn = 1e9 ; 

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// int n , p , k ; 
// int num ; 

// vector<int> head ;
// // mxw 代表到
// vector<int> mxw ; 
// vector<int> mncnt ; 

// struct edge{
//     int u ;
//     int v ; 
//     int w ; 
//     int nxt ;  
// } ; vector<edge> edges ; 

// struct infor {
//     // 当前点是啥
//     int v ; 
//     // 到起点的权值这条路径的权值最大值是多少
//     int w ;
//     // 到起点的边的数量
//     int cnt ;
// } ; 

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// inline void add ( int u , int v , int w ) {
//     num ++ ; 
//     edges[num].v = v ;
//     edges[num].w = w ;
//     edges[num].nxt = head[u] ; 
//     head[u] = num ;  
// }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*

// 矛盾是 第一我们要找尽可能少的路径 
// 如果不行 , 我们要找最大值最小

// 可以分两步来写 ? 第一部分直接 BFS 跑一边加个计数就成

// 然后这里面再来一个记录最大值的

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     cin >> n >> p >> k ; 
//     mxw.resize( n + 1 , INT_MAX ) ; 
//     mncnt.resize( n + 1 , INT_MAX ) ; 
//     head.resize( n + 1 ) ; 
//     edges.resize( 2 * p + 1 ) ; 
//     while ( p -- ) {
//         int u , v , w ; 
//         cin >> u >> v >> w ; 
//         add(u , v , w) ; 
//         add(v , u , w) ; 
//     }
    
//     queue<infor> q ;
//     q.emplace( infor{ 1 , 0 }) ;
//     mncnt[1] = 0 ; mxw[1] = 0 ; 
//     while ( !q.empty() ) {
//         auto [v , w , cnt] = q.front() ; q.pop() ; 
//         for ( int i = head[v] ; i ; i = edges[i].nxt ) {
//             int vv = edges[i].v ; 
//             int ww = edges[i].w ; 
//             if ( max( mxw[v] , ww) < mxw[vv] ) {
//                 mxw[vv] = max( mxw[v] , ww) ; 
//                 q.emplace( infor{ vv , mxw[vv] , mncnt[vv] }) ; 
//             }
//             if ( mncnt[vv] > mncnt[v] + 1 ) {
//                 mncnt[vv] = mncnt[v] + 1 ; 
//                 q.emplace( infor{vv , mxw[vv] , mncnt[vv] }) ; 
//             }  
//         }
//     }  

//     cout << (mncnt[n] == INT_MAX ? -1 : (mncnt[n] <= k ? 0 : mxw[n])) << endl ; 
        
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */



// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <climits>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque> 
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int , int , int>
// #define ull unsigned long long
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD1 = 998244353 ; 
// const int MOD2 = 1e9 + 7 ; 
// const int maxn = 1e9 ; 

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// int n , p , k ; 
// int num ; 

// vector<int> head ;
// // mxw 代表到
// vector<int> mxw ; 
// vector<int> mncnt ; 

// struct edge{
//     int u ;
//     int v ; 
//     int w ; 
//     int nxt ;  
// } ; vector<edge> edges ; 

// struct infor {
//     int v ; 
//     int cnt ;
// } ; 

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// inline void add ( int u , int v , int w ) {
//     num ++ ; 
//     edges[num].v = v ;
//     edges[num].w = w ;
//     edges[num].nxt = head[u] ; 
//     head[u] = num ;  
// }

// bool check(int test) {

//     vector<int> dp( n + 1 , INT_MAX ) ; // dp[i] 是从点 1 到点 i 路径上超过 test 的最小数目

//     queue<int> q ;
//     q.emplace( 1 ) ;
//     dp[1] = 0 ;
//     while ( !q.empty() ) {
//         auto v = q.front() ; q.pop() ; 
//         for ( int i = head[v] ; i ; i = edges[i].nxt ) {
//             int vv = edges[i].v ;
//             int ww = edges[i].w ; 
//             if ( dp[vv] > dp[v] + (ww > test) ) {
//                 dp[vv] = dp[v] + (ww > test) ; 
//                 q.emplace( vv ) ;
//             } 
//         }
//     } 

//     return dp[n] <= k ;

// }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*

// 矛盾是 第一我们要找尽可能少的路径 
// 如果不行 , 我们要找最大值最小

// 可以分两步来写 ? 第一部分直接 BFS 跑一边加个计数就成

// 然后这里面再来一个记录最大值的

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     cin >> n >> p >> k ; 
//     mxw.resize( n + 1 , INT_MAX ) ; 
//     mncnt.resize( n + 1 , INT_MAX ) ; 
//     head.resize( n + 1 ) ; 
//     edges.resize( 2 * p + 1 ) ; 

//     int mxweight = INT_MIN ; 
//     while ( p -- ) {
//         int u , v , w ; 
//         cin >> u >> v >> w ; 
//         add(u , v , w) ; 
//         add(v , u , w) ; 
//         mxweight = max( mxweight , w ) ; 
//     }
    
//     int l = 1 , r = mxweight , ans = l ; 
//     while ( l <= r ) {
//         int mid = ( l + r ) / 2 ;
//         if ( check(mid) ) r = mid - 1 , ans = mid ; 
//         else l = mid + 1 ; 
//     }

//     cout << ans << endl ;
        
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */


// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <climits>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque> 
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int , int , int>
// #define ull unsigned long long
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD1 = 998244353 ; 
// const int MOD2 = 1e9 + 7 ; 
// const int maxn = 1e9 ; 

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// int n , p , k ; 
// int num ; 

// vector<int> head ;
// // mxw 代表到
// vector<int> mxw ; 
// vector<int> mncnt ; 

// struct edge{
//     int u ;
//     int v ; 
//     int w ; 
//     int nxt ;  
// } ; vector<edge> edges ; 

// struct infor {
//     int v ; 
//     int cnt ;
// } ; 

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// inline void add ( int u , int v , int w ) {
//     num ++ ; 
//     edges[num].v = v ;
//     edges[num].w = w ;
//     edges[num].nxt = head[u] ; 
//     head[u] = num ;  
// }

// bool check(int test) {

//     vector<int> dp( n + 1 , INT_MAX ) ; // dp[i] 是从点 1 到点 i 路径上超过 test 的最小数目

//     deque<int> dq ;
//     dq.emplace_back( 1 ) ;
//     dp[1] = 0 ;
//     while ( !dq.empty() ) {
//         auto v = dq.front() ; dq.pop_front() ; 
//         for ( int i = head[v] ; i ; i = edges[i].nxt ) {
//             int vv = edges[i].v ;
//             int ww = edges[i].w ;
//             int cost = (ww > test) ; 

//             if ( dp[vv] > dp[v] + (ww > test) ) {
//                 if ( cost == 0 ) {
//                     dq.emplace_front( vv ) ; 
//                 } else {
//                     dq.emplace_back( vv ) ; 
//                 }
//                 dp[vv] = dp[v] + (ww > test) ; 
//             }

//         }
//     } 

//     return dp[n] <= k ;

// }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*

// 矛盾是 第一我们要找尽可能少的路径 
// 如果不行 , 我们要找最大值最小

// 可以分两步来写 ? 第一部分直接 BFS 跑一边加个计数就成

// 然后这里面再来一个记录最大值的

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     cin >> n >> p >> k ; 
//     mxw.resize( n + 1 , INT_MAX ) ; 
//     mncnt.resize( n + 1 , INT_MAX ) ; 
//     head.resize( n + 1 ) ; 
//     edges.resize( 2 * p + 1 ) ; 

//     int mxweight = INT_MIN ; 
//     while ( p -- ) {
//         int u , v , w ; 
//         cin >> u >> v >> w ; 
//         add(u , v , w) ; 
//         add(v , u , w) ; 
//         mxweight = max( mxweight , w ) ; 
//     }
    
//     int l = 0 , r = mxweight , ans = -1 ; 
//     while ( l <= r ) {
//         int mid = ( l + r ) / 2 ;
//         if ( check(mid) ) r = mid - 1 , ans = mid ; 
//         else l = mid + 1 ; 
//     }

//     cout << ans << endl ;
        
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */


// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <climits>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque> 
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int , int , int>
// #define ull unsigned long long
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD1 = 998244353 ; 
// const int MOD2 = 1e9 + 7 ; 
// const int maxn = 1e9 ; 

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// int n , p , k ; 
// int num ; 

// vector<int> head ;

// struct edge{
//     int u ;
//     int v ; 
//     int w ; 
//     int nxt ;  
// } ; vector<edge> edges ; 

// struct infor {
//     int v ; 
//     int cnt ;
// } ; 

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// inline void add ( int u , int v , int w ) {
//     num ++ ; 
//     edges[num].v = v ;
//     edges[num].w = w ;
//     edges[num].nxt = head[u] ; 
//     head[u] = num ;  
// }

// bool check(int test) {

//     bool inq[n + 1] ; 
//     memset(inq , 0 , sizeof(inq)) ;
//     vector<int> dp( n + 1 , INT_MAX ) ; // dp[i] 是从点 1 到点 i 路径上超过 test 的最小数目

//     queue<int> q ;
//     q.emplace( 1 ) ;
//     dp[1] = 0 ; inq[1] = 1 ;
//     while ( !q.empty() ) {
//         auto v = q.front() ; q.pop() ; 
//         inq[v] = 0 ; 
//         for ( int i = head[v] ; i ; i = edges[i].nxt ) {
//             int vv = edges[i].v ;
//             int ww = edges[i].w ; 
//             if ( dp[vv] > dp[v] + (ww > test) ) {
//                 dp[vv] = dp[v] + (ww > test) ; 
//                 if ( !inq[vv] ) q.emplace( vv ) , inq[vv] = 1 ; 
//             } 
//         }
//     } 

//     return dp[n] <= k ;

// }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*

// 矛盾是 第一我们要找尽可能少的路径 
// 如果不行 , 我们要找最大值最小

// 可以分两步来写 ? 第一部分直接 BFS 跑一边加个计数就成

// 然后这里面再来一个记录最大值的

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
//     cin >> n >> p >> k ; 
//     head.resize( n + 1 ) ; 
//     edges.resize( 2 * p + 1 ) ; 

//     int mxweight = INT_MIN ; 
//     while ( p -- ) {
//         int u , v , w ; 
//         cin >> u >> v >> w ; 
//         add(u , v , w) ; 
//         add(v , u , w) ; 
//         mxweight = max( mxweight , w ) ; 
//     }
    
//     int l = 0 , r = mxweight , ans = -1 ; 
//     while ( l <= r ) {
//         int mid = ( l + r ) / 2 ;
//         if ( check(mid) ) r = mid - 1 , ans = mid ; 
//         else l = mid + 1 ; 
//     }

//     cout << ans << endl ;
        
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */

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

int n , p , k ; 

struct edge {
    int v ;
    int w ; 
} ; vector<vector<edge>> adj ; 

vector<int> mnCnt ; 
vector<int> mnMxW ; 

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
    

    cin >> n >> p >> k ; 
    adj.resize( n * (k + 1) ) ;
    mnMxW.resize( n * (k + 1) , INT_MAX) ; 
    mnCnt.resize( n * (k + 1) , INT_MAX) ; 
    while ( p -- ) {
        int u , v , w ; cin >> u >> v >> w ; 
        // 注意这里的点的编号是 0-based , 还有
        u -- ; v -- ; 
        adj[u].emplace_back( edge{v , w}) ;
        adj[v].emplace_back( edge{u , w}) ; 

        for ( int i = 1 ; i <= k ; i ++ ) {

            // 上一层的点
            int u0 = (i - 1) * n + u ; 
            int v0 = (i - 1) * n + v ; 
            // 下一层的点
            int u1 = i * n + u ;
            int v1 = i * n + v ; 

            // adj[u0].emplace_back(edge{v0, w});
            // adj[v0].emplace_back(edge{u0, w});

            // // 3. 当前层（i层）的同层原始边（非免费，无向）→ 位置不变，保留
            // adj[u1].emplace_back(edge{v1, w});
            // adj[v1].emplace_back(edge{u1, w});

            // // 4. 同节点跨层免费边（i-1层→i层，消耗1次免费，有向）→ 保留，逻辑合理
            // adj[u0].emplace_back(edge{u1, 0});
            // adj[v0].emplace_back(edge{v1, 0});

            // // 5. 跨节点跨层免费边（i-1层→i层，消耗1次免费，无向补全）→ 之前缺失反向
            // adj[u0].emplace_back(edge{v1, 0});
            // adj[v0].emplace_back(edge{u1, 0});

            // 同节点 分层免费边 , 用来直接跳层
            adj[u0].emplace_back( edge{u1 , 0}) ; 
            adj[v0].emplace_back( edge{v1 , 0}) ;

            // 不同层之间建 0 边
            adj[u0].emplace_back( edge{v1 , 0}) ; 
            adj[v1].emplace_back( edge{u0 , 0}) ; 
            adj[u1].emplace_back( edge{v1 , w}) ; 
            adj[v1].emplace_back( edge{u1 , w}) ; 

        }

    } 

    // 分层图就是 增加一个维度 , 如果这条边是免费的 , 就直接移动到下一层进行搜索
    // 如果不是免费的 , 就在这一层进行搜索
    // 另外我的这个写法里面在层和层之间是有向边即可 , 没不要建立无向边
    // 接下来直接 dp 就行了应该是
    deque<edge> dq ; 
    mnMxW[1] = 0 ; 
    dq.emplace_back( edge{0 , 0}) ; 
    while ( !dq.empty() ) {
        auto [v , w] = dq.front() ; dq.pop_front() ; 
        for ( auto &[vv , ww] : adj[v] ) {
            if ( mnMxW[vv] > max(mnMxW[v] , ww) ) {
                mnMxW[vv] = max(mnMxW[v] , ww) ; 
                if ( ww == 0 ) dq.emplace_front( edge{vv , mnMxW[vv]}) ; 
                else dq.emplace_back( edge{vv , mnMxW[vv]}) ; 
            }
        }
    } 
    
    cout << mnMxW[n * (k + 1) - 1] << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/


/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: 分层图 - 最小化路径最大边权（允许免费k条边）
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int INF = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int v, w;
};

int n, p, k;
vector<vector<Edge>> adj;
vector<int> dist;

void solve() {
    cin >> n >> p >> k;
    
    // 总节点数 = (k+1) * n
    int total_nodes = (k + 1) * n;
    adj.resize(total_nodes);
    
    // 读取所有边
    vector<tuple<int, int, int>> edges(p);
    for (int i = 0; i < p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = {u, v, w};
    }
    
    // 构建分层图
    for (const auto& [u, v, w] : edges) {
        for (int i = 0; i <= k; i++) {
            // 当前层的节点编号
            int u_cur = i * n + u;
            int v_cur = i * n + v;
            
            // 层内边：正常走（原权值）
            adj[u_cur].push_back({v_cur, w});
            adj[v_cur].push_back({u_cur, w});
            
            // 跨层边：免费走（权值为0），如果还有免费次数
            if (i < k) {
                int u_next = (i + 1) * n + u;
                int v_next = (i + 1) * n + v;
                
                // 使用免费边从当前层到下一层
                adj[u_cur].push_back({v_next, 0});  // u免费到下一层的v
                adj[v_cur].push_back({u_next, 0});  // v免费到下一层的u
            }
        }
    }
    
    // 0-1 BFS（边权只有0和w两种）
    dist.assign(total_nodes, INF);
    deque<int> dq;
    
    int start = 0;  // 第0层的起点0
    dist[start] = 0;
    dq.push_front(start);
    
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        
        for (auto [v, w] : adj[u]) {
            // 最小化路径上的最大边权：取max
            int nd = max(dist[u], w);
            
            if (nd < dist[v]) {
                dist[v] = nd;
                if (w == 0) {
                    // 免费边，权值为0，放在队首
                    dq.push_front(v);
                } else {
                    // 收费边，放在队尾
                    dq.push_back(v);
                }
            }
        }
    }
    
    // 在所有层的终点中找最小值
    int ans = dist[k * n + (n - 1)];
    // for (int i = 0; i <= k; i++) {
    //     ans = min(ans, dist[i * n + (n - 1)]);  // 第i层的终点n-1
    // }
    
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    
    return 0;
}

// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: 分层图 + 0-1 BFS 求解最大边权最小问题（允许k次免费通行）
//  */

// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <climits>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream>
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int, int, int>
// #define ull unsigned long long
// #define PII pair<int, int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD1 = 998244353;
// const int MOD2 = 1e9 + 7;

// // ========================== Global Variables / Arrays ========================
// int n, p, k;
// struct edge {
//     int v;
//     int w;
// };
// vector<vector<edge>> adj;  // 分层图邻接表：节点编号 0 ~ (k+1)*n - 1（0-based）
// vector<int> mnMxW;         // mnMxW[u]：到达分层节点u的路径中，最大边权的最小值

// // ========================== Functions ========================================
// void solve() {
//     cin >> n >> p >> k;
//     int total_nodes = (k + 1) * n;  // 分层图总节点数：k+1层，每层n个节点
//     adj.resize(total_nodes);
//     mnMxW.resize(total_nodes, INF);  // 初始化所有状态为无穷大

//     // 建图：原始边 + 分层边（0-based）
//     while (p--) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         u--;  // 转为0-based
//         v--;

//         // 1. 第0层（未使用免费机会）的原始边（非免费，边权w）
//         adj[u].emplace_back(edge{v, w});
//         adj[v].emplace_back(edge{u, w});

//         // 2. 第1~k层的边（已使用i次免费机会）
//         for (int i = 1; i <= k; ++i) {
//             int prev_layer = (i - 1) * n;  // 上一层（i-1次免费）的节点偏移量
//             int curr_layer = i * n;        // 当前层（i次免费）的节点偏移量

//             // 上一层的节点：u0 = 上一层u，v0 = 上一层v
//             int u0 = prev_layer + u;
//             int v0 = prev_layer + v;
//             // 当前层的节点：u1 = 当前层u，v1 = 当前层v
//             int u1 = curr_layer + u;
//             int v1 = curr_layer + v;

//             // 3. 同层原始边（非免费，边权w）：当前层内部的路径，不消耗免费机会
//             adj[u1].emplace_back(edge{v1, w});
//             adj[v1].emplace_back(edge{u1, w});

//             // 4. 同节点跨层免费边（消耗1次免费机会，直接跳层，边权0）
//             adj[u0].emplace_back(edge{u1, 0});
//             adj[v0].emplace_back(edge{v1, 0});

//             // 5. 跨节点跨层免费边（消耗1次免费机会走u→v，边权0）
//             adj[u0].emplace_back(edge{v1, 0});
//             adj[v0].emplace_back(edge{u1, 0});
//         }
//     }

//     // 0-1 BFS 求解：优先处理边权为0的边（队首），边权为w的边（队尾）
//     deque<int> dq;
//     int start = 0;  // 起点：第0层的原始起点（0-based）
//     mnMxW[start] = 0;
//     dq.push_back(start);

//     while (!dq.empty()) {
//         int u = dq.front();
//         dq.pop_front();

//         for (auto &e : adj[u]) {
//             int v = e.v;
//             int w = e.w;

//             // 核心松弛条件：更新到达v的最小最大边权
//             int new_max = max(mnMxW[u], w);  // 新路径的最大边权 = max(当前最大, 本条边权)
//             if (new_max < mnMxW[v]) {
//                 mnMxW[v] = new_max;
//                 if (w == 0) {
//                     // 免费边（0权）：加入队首，优先处理
//                     dq.push_front(v);
//                 } else {
//                     // 非免费边（w权）：加入队尾
//                     dq.push_back(v);
//                 }
//             }
//         }
//     }

//     // 终点：第k层的原始终点（0-based 原始终点是n-1）
//     int end = k * n + (n - 1);
//     if (mnMxW[end] != INF) {
//         cout << mnMxW[end] << endl;
//     } else {
//         cout << -1 << endl;
//     }
// }

// // ========================== Main Function ====================================
// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     solve();

//     return 0;
// }

// /*
//  * @Author: GoryK
//  * @Date: 2026-01-22
//  * @Description: 分层图最短路（允许k次免费通行，求最大边权最小的路径）
//  */

// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")

// // ========================== Header Files =====================================
// #include <algorithm>
// #include <iostream>
// #include <climits>
// #include <cstring>
// #include <queue>
// #include <vector>
// #include <utility>

// // ========================== Namespace ========================================
// using namespace std;

// // ========================== Macro Definitions ================================
// #define endl '\n'
// #define PII pair<int, int>
// #define int long long

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f;
// const int MAX_NODE = 110010;  // (k+1)*n，k最大10，n最大1e4 → 1.1e5
// const int MAX_EDGE = 200010 * 4;  // 原始边*2 + 分层边*2*k + 同层免费边*k

// // ========================== Global Variables / Arrays ========================
// int n, m, k;
// int s, t;  // 起点、终点
// vector<vector<PII>> adj;  // 邻接表：adj[u] = {{v, w}, ...}（v是邻点，w是边权）
// int dist[MAX_NODE];       // 距离数组：dist[u]表示到u的最小最大边权
// bool vis[MAX_NODE];       // 访问标记

// // ========================== Functions ========================================
// // Dijkstra算法（求最大边权最小的路径）
// void dijkstra() {
//     // 优先队列：{当前最大边权, 节点}，小根堆
//     priority_queue<PII, vector<PII>, greater<>> pq;
    
//     // 初始化距离数组和访问标记
//     memset(dist, 0x3f, sizeof(dist));
//     memset(vis, false, sizeof(vis));
    
//     dist[s] = 0;
//     pq.emplace(0, s);
    
//     while (!pq.empty()) {
//         auto [curr_max, u] = pq.top();
//         pq.pop();
        
//         if (vis[u]) continue;
//         vis[u] = true;
        
//         // 遍历所有邻边
//         for (auto [v, w] : adj[u]) {
//             // 新的最大边权 = max(当前路径最大边权, 本条边权)
//             int new_max = max(curr_max, w);
//             if (new_max < dist[v]) {
//                 dist[v] = new_max;
//                 pq.emplace(dist[v], v);
//             }
//         }
//     }
// }

// void solve() {
//     cin >> n >> m >> k;
//     s = 1;                          // 原始起点（第0层）
//     t = (k + 1) * n;                // 终点（第k+1层的原始终点）
//     adj.resize((k + 1) * n + 1);    // 节点编号：1~(k+1)*n
    
//     // 建图：原始边 + 分层边
//     while (m--) {
//         int x, y, z;
//         cin >> x >> y >> z;
        
//         // 1. 原始图的边（第0层）
//         adj[x].emplace_back(y, z);
//         adj[y].emplace_back(x, z);
        
//         // 2. 各分层的边（第1~k层）
//         for (int i = 1; i <= k; ++i) {
//             int u1 = i * n + x;  // 第i层的x
//             int v1 = i * n + y;  // 第i层的y
//             adj[u1].emplace_back(v1, z);
//             adj[v1].emplace_back(u1, z);
            
//             // 3. 跨层免费边（第i-1层→第i层，边权0，代表使用1次免费机会）
//             int u0 = (i - 1) * n + x;
//             int v0 = (i - 1) * n + y;
//             adj[u0].emplace_back(v1, 0);
//             adj[v0].emplace_back(u1, 0);
//         }
//     }
    
//     // 4. 同节点跨层免费边（不使用免费机会，直接跳到下一层）
//     for (int i = 1; i <= k; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             int u = (i - 1) * n + j;
//             int v = i * n + j;
//             adj[u].emplace_back(v, 0);
//         }
//     }
    
//     // 求解最短路
//     dijkstra();
    
//     // 输出结果
//     if (dist[t] != INF) {
//         cout << dist[t] << endl;
//     } else {
//         cout << -1 << endl;
//     }
// }

// // ========================== Main Function ====================================
// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
    
//     solve();
    
//     return 0;
// }

// // ========================== Algorithm Explanation ============================
// /*

// */