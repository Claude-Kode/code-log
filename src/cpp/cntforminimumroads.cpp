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
const int MOD1 = 100003 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ;
vector<vector<int>> adj ;
struct infor { int cnt ; int w ; } ;
// cnt , w
vector<infor> dp ; 
vector<int> vis ;

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    cin >> n >> m ; 
    adj.resize( n + 1 ) ; 
    dp.resize( n + 1 , infor{1 , INF} ) ; 
    while ( m -- ) {
        int t , h ; cin >> t >> h ; 
        adj[t].push_back( h ) ; 
        adj[h].push_back( t ) ; 
    }
    vis.resize( n + 1 ) ;
}

void solve() {
     


}

// ========================== Idea =============================================
/*

最短路计数的最短是怎么筛选出来的 ? 
状态转移是怎么转移的

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    init() ; 
    queue<PII> q ; 
    // 应该带一个权值 然后遍历
    q.emplace( 1 , 1 ) ;
    while ( !q.empty() ) {
        auto [v , w] = q.front() ; q.pop() ;
        int mnw = w + 1 ; 
        for ( auto &a : adj[v] ) {
            if ( !vis[a] ) {
                auto &[cnt , ww] = dp[a] ;  
                if ( ww == mnw ) cnt += dp[v].cnt ; cnt %= MOD1 ; 
                q.emplace( a , w + 1 ) ; 
                vis[a] = 1 ; 
            } 
        }
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << dp[i].cnt << endl ; 
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/



/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: 最短路计数（适配1e6节点+重边+自环）
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define PII pair<int, int>
#define int long long
#define endl '\n'

const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD1 = 100003;
const int MAXN = 1e6 + 10;  // 适配1e6节点规模

// 全局变量（避免栈溢出，1e6数组必须放全局）
int n, m;
vector<vector<int>> adj(MAXN);  // 邻接表
struct infor { int cnt; int w; } dp[MAXN];  // 数组比vector快，适配1e6规模
bool vis[MAXN];  // 标记是否入队（避免重复入队）

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    // 初始化dp：路径数0，距离INF（未访问）
    for (int i = 1; i <= n; ++i) {
        dp[i].cnt = 0;
        dp[i].w = INF;
    }
    // 起点初始化：路径数1，距离0
    dp[1].cnt = 1;
    dp[1].w = 0;
    vis[1] = true;

    // 读边（处理重边、自环）
    while (m--) {
        int x, y;
        cin >> x >> y;
        // 跳过自环（自环不影响最短路，只会增加无效计算）
        if (x == y) continue;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

signed main() {
    init();
    queue<PII> q;
    q.emplace(1, 0);  // 队列存(节点, 当前距离)，和dp[1].w一致

    while (!q.empty()) {
        auto [v, w] = q.front();
        q.pop();

        // 剪枝：如果当前节点的距离已经不是最短距离，直接跳过（避免重边导致的无效处理）
        if (w > dp[v].w) continue;

        int new_w = w + 1;  // 无向无权图，边权固定1
        for (auto &a : adj[v]) {
            auto &[a_cnt, a_w] = dp[a];

            if (new_w < a_w) {  // 找到更短路径：重置计数+入队
                a_w = new_w;
                a_cnt = dp[v].cnt;
                a_cnt %= MOD1;
                if (!vis[a]) {
                    vis[a] = true;
                    q.emplace(a, new_w);
                }
            } else if (new_w == a_w) {  // 找到等长最短路径：累加计数
                a_cnt = (a_cnt + dp[v].cnt) % MOD1;
            }
            // 新距离>当前距离：直接跳过（无效路径）
        }
    }

    // 输出结果（1~n每个节点的最短路数）
    for (int i = 1; i <= n; ++i) {
        cout << dp[i].cnt % MOD1 << endl;
    }

    return 0;
}



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
const int MOD1 = 100003 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ;
vector<vector<int>> adj ;
struct infor { int cnt ; int w ; } ;
// cnt , w
vector<infor> dp ; 
vector<int> vis ;

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    cin >> n >> m ; 
    adj.resize( n + 1 ) ; 
    dp.resize( n + 1 , infor{0 , INF} ) ; 
    while ( m -- ) {
        int t , h ; cin >> t >> h ; 
        adj[t].push_back( h ) ; 
        adj[h].push_back( t ) ; 
    }
    vis.resize( n + 1 ) ;
}

void solve() {
     


}

// ========================== Idea =============================================
/*

最短路计数的最短是怎么筛选出来的 ? 
状态转移是怎么转移的

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    init() ; 
    queue<PII> q ; 
    q.emplace( 1 , 0 ) ;  
    dp[1].cnt = 1 ;
    dp[1].w = 0 ;
    vis[1] = 1 ;   
    while ( !q.empty() ) {
        auto [v , w] = q.front() ; q.pop() ;
        int mnw = w + 1 ; 
        for ( auto &a : adj[v] ) {
            auto &[cnt , ww] = dp[a] ;  
            if ( mnw <= ww ) { 
                cnt = (cnt + dp[v].cnt) % MOD1 ; 
                if ( !vis[a] ) {  
                    q.emplace( a , mnw ) ;
                    vis[a] = 1 ; 
                }
            }
        }
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << dp[i].cnt % MOD1 << endl ; 
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/
