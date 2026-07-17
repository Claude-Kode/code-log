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
#define ull unsigned int int
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD1 = 100003 ; 
const int MOD2 = 998244353 ; 
const int maxn = 4e5 ;

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ; 
int num = 0 ; 

struct edge{ 
    int u ;
    int v ; 
    int w ; 
    int nxt ; 
} ;

struct Edge {
    int v ;
    int w ; 
    bool operator< ( const Edge& a ) const {
        return w > a.w ; 
    }
} ; 

vector<int> dis ; 
vector<int> vis ; 
vector<int> cnt ;
vector<int> head ;
vector<edge> edges ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

inline void add( int u , int v , int w ) {
    edges[num].u = u ;
    edges[num].v = v ; 
    edges[num].w = w ; 
    edges[num].nxt = head[u] ;
    head[u] = num ;
    num ++ ; 
} 

void Dijkstra ( int start ) {
    priority_queue<Edge> pq ;
    pq.emplace( Edge{start , 0} ) ;
    vis[start] = 1 ; dis[start] = 0 ; 
    while ( !pq.empty() ) {
        auto [v , w] = pq.top() ; pq.pop() ; 

        for ( int i = head[v] ; i != -1 ; i = edges[i].nxt ) {
            int vv = edges[i].v ; 
            int ww = edges[i].w ; 
            if ( !vis[vv] && dis[vv] > dis[v] + ww ) {
                dis[vv] = dis[v] + ww ; 
                vis[vv] = 1 ;
                pq.emplace( Edge{vv , dis[vv]} ) ; 
                cnt[vv] = cnt[v] ; 
            } else if ( dis[vv] == dis[v] + ww ) {
                cnt[vv] = (cnt[vv] + cnt[v]) % MOD1 ; 
            }
             
        }
    }
    
}

void solve() {
     


}

// ========================== Idea =============================================
/*

BFS , 每次到达一个节点记录路径长度和时间
可以看作每条边的权值都是 1 , 然后直接 Dijkstra 即可

计数是如何实现的呢 ? 
对于节点 y 来说 , 他相邻的节点假设是 x 
dp[dis[y]] = dp[dis[y] - 1]

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n >> m ; 
    vis.resize( n + 1 , 0 ) ; 
    // 这道题统计的是从起点出发的路径的数量 所以所有点先默认是 0 即可 不能是一
    cnt.resize( n + 1 , 0 ) ; 
    head.resize( n + 1 , -1 ) ; 
    edges.resize( 2 * m + 1 ) ; 
    dis.resize( n + 1 , INT_MAX ) ;
    while ( m -- ) {
        int u , v ; cin >> u >> v ; 
        add( u , v , 1 ) ; 
        add( v , u , 1 ) ;
    }

    cnt[1] = 1 ;
    Dijkstra( 1 ) ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << cnt[i] << endl ;
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/







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
int num ;
struct infor { int cnt ; int w ; } ;
vector<infor> dp ; 
vector<int> vis ;
vector<int> head ; 
struct edge {
    int u ;
    int v ; 
    int w ; 
    int nxt ;
} ;

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

inline void add( int u , int v , int w ) {
    num ++ ; 
    edges[num].u = u ;
    edges[num].v = v ; 
    edges[num].w = w ;
    edges[num].nxt = head[u] ; 
    head[u] = num ; 
}

void init() {
    cin >> n >> m ; 
    dp.resize( n + 1 , infor{0 , INF} ) ; 
    head.resize( n + 1 ) ; 
    vis.resize( n + 1 ) ;
    edges.resize( 2 * m + 1 ) ; 
    while ( m -- ) {
        int t , h ; cin >> t >> h ; 
        add( t , h , 1 ) ;
        add( h , t , 1 ) ;
    }
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
    // 这里入队的含义是什么 这道题本质的解法是 BFS , 入队相当于把
    while ( !q.empty() ) {
        auto [v , w] = q.front() ; q.pop() ;
        int mnw = w + 1 ; 
        for ( int i = head[v] ; i ; i = edges[i].nxt ) {
            int vv = edges[i].v ; 
            int ww = edges[i].w ; 
            auto &[cnt , ww] = dp[i] ;  
            if ( mnw <= ww ) { 
                cnt = (cnt + dp[v].cnt) % MOD1 ; 
                if ( !vis[i] ) {  
                    q.emplace( a , mnw ) ;
                    vis[a] = 1 ; 
                }
            }
        }

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
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << dp[i].cnt % MOD1 << endl ; 
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/





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
int num = 0 ; 

vector<int> vis ;
vector<int> head ; 

struct edge {  
    int v ; 
    int w ; 
    int nxt ; 
} ; vector<edge> edges ; 

struct infor { 
    int cnt ; 
    int w ; 
} ; vector<infor> dp ; 




// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

inline void add ( int u , int v , int w ) {
    num ++ ; 
    edges[num].v = v ;
    edges[num].w = w ;
    edges[num].nxt = head[u] ; 
    head[u] = num ;  
}

void init() {
    cin >> n >> m ; 
    head.resize( n + 1 , 0 ) ; 
    edges.resize( 2 * m + 1 ) ;
    dp.resize( n + 1 , infor{0 , INF} ) ; 
    while ( m -- ) {
        int t , h ; cin >> t >> h ; 
        add( t , h , 1 ) ;
        add( h , t , 1 ) ; 
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
        if ( vis[v] ) continue ; 
        vis[v] = 1 ; 
        int mnw = w + 1 ; 
        for ( int i = head[v] ; i ; i = edges[i].nxt ) {
            int vv = edges[i].v ; 
            int ww = edges[i].w ; 
            if ( dp[vv].w > mnw ) {
                cnt[vv] = cnt[v] ; 
                dp[vv].w = mnw ; 
                q.emplace( vv , mnw ) ; 
            } else if ( dp[vv].w == mnw ) {
                cnt[vv] = ( cnt[vv] + cnt[v] ) % MOD1 ; 
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
#define ull unsigned int int
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD1 = 100003 ; 
const int MOD2 = 998244353 ; 
const int maxn = 4e5 ;

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ; 
int num = 0 ; 

struct edge{ 
    int u ;
    int v ; 
    int w ; 
    int nxt ; 
} ;

struct Edge {
    int v ;
    int w ; 
    bool operator< ( const Edge& a ) const {
        return w > a.w ; 
    }
} ; 

vector<int> dis ; 
vector<int> cnt ;
vector<int> head ;
vector<edge> edges ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

inline void add( int u , int v , int w ) {
    edges[num].u = u ;
    edges[num].v = v ; 
    edges[num].w = w ; 
    edges[num].nxt = head[u] ;
    head[u] = num ;
    num ++ ; 
} 

void Dijkstra ( int start ) {
    priority_queue<Edge> pq ;
    pq.emplace( Edge{start , 0} ) ;
    vis[start] = 1 ; dis[start] = 0 ; 
    while ( !pq.empty() ) {
        auto [v , w] = pq.top() ; pq.pop() ; 

        for ( int i = head[v] ; i != -1 ; i = edges[i].nxt ) {
            int vv = edges[i].v ; 
            int ww = edges[i].w ; 
            if ( !vis[vv] && dis[vv] > dis[v] + ww ) {
                dis[vv] = dis[v] + ww ; 
                pq.emplace( Edge{vv , dis[vv]} ) ; 
                cnt[vv] = cnt[v] ; 
            } else if ( dis[vv] == dis[v] + ww ) {
                cnt[vv] = (cnt[vv] + cnt[v]) % MOD1 ; 
            }
             
        }
    }
    
}

void solve() {
     


}

// ========================== Idea =============================================
/*

BFS , 每次到达一个节点记录路径长度和时间
可以看作每条边的权值都是 1 , 然后直接 Dijkstra 即可

计数是如何实现的呢 ? 
对于节点 y 来说 , 他相邻的节点假设是 x 
dp[dis[y]] = dp[dis[y] - 1]

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n >> m ; 
    // 这道题统计的是从起点出发的路径的数量 所以所有点先默认是 0 即可 不能是一
    cnt.resize( n + 1 , 0 ) ; 
    head.resize( n + 1 , -1 ) ; 
    edges.resize( 2 * m + 1 ) ; 
    dis.resize( n + 1 , INT_MAX ) ;
    while ( m -- ) {
        int u , v ; cin >> u >> v ; 
        add( u , v , 1 ) ; 
        add( v , u , 1 ) ;
    }

    cnt[1] = 1 ;
    Dijkstra( 1 ) ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << cnt[i] << endl ;
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/



