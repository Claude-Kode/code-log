// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

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

// int n ; 

// vector<int> cnt ; 
// vector<int> adj ;

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void init( ) {
//     cin >> n ; 
//     adj.resize( n + 1 ) ; 
//     cnt.resize( n + 1 , 1 ) ;
// }

// void DFS( int begin ) {

//     if ( lim ) return ; 



// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
//     init() ; 
//     int cnt = 0 ; 
//     while ( 1 ) {
//         cnt ++ ; 
//         for ( int i = 1 ; i <= n ; i ++ ) {
//             if ( !merge( i , adj[i] ) )  {
//                 cout << cnt << endl ; 
//                 return 0 ;
//             }
//         }
//     }

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

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
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
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define endl '\n'
// #define int long long
// #define ll long long
// #define ull unsigned int int
// #define PII pair<int , int>
// #define TUP tuple<int , int , int>

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const ll LINF = 1e18 ;
// const int MOD = 1e9 + 7 ;
// const int MOD2 = 998244353 ;

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;



// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void solve() {
    
// }

// void DFS( vector<int> &vis , vector<int> &adj , int &mn , int begin , int step ) {
//     if ( vis[begin] )
//     { mn = min( mn , step ) ; return ; }
//     vis[begin] = 1 , DFS( vis , adj , mn , adj[begin] , step + 1 ) ;
// } 

// // ========================== Idea =============================================
// /*

// 有向无环图 求最小环大小
// topo 排序是用来处理

// 每一次操作相当于对指定的点和点之间创建一条边 

// topo sort后 如果过存在环 , 那么这个环的所有节点都不会被加入

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    


//     int n ; cin >> n ;
//     vector<int> adj( n + 1 ) ;
//     vector<int> indegree( n + 1 ) ; 
//     for ( int i = 1 , end ; i <= n ; i ++ ) 
//         cin >> end , adj[i] = end , indegree[end] ++ ; 
//     queue<int> q ; 
//     for ( int i = 1 ; i <= n ; i ++ ) 
//         if ( indegree[i] == 0 ) q.push( i ) ; 
//     vector<int> notcircle( n + 1 ) ; 
//     vector<int> vis( n + 1 , 0 ) ; 
//     while( !q.empty() ) {

//         auto top = q.front() ; q.pop() ; 
//         // cout << top << endl ; 
//         notcircle[top] = 1 ; vis[top] = 1 ; 
//         if ( -- indegree[adj[top]] == 0 ) 
//             q.push( adj[top] ) ;  
//     }  
//     int mn = n ; 
//     for ( int i = 1 ; i <= n ; i ++ ) 
//         if ( !vis[i] ) DFS( vis , adj , mn , i , 0 ) ;
//     cout << mn << endl ;
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */


// // #include <bits/stdc++.h>
// // int n , ans = 0x3f3f3f , cnt ; vector<int> fa ; 
// // int Find( int a , int cnt ) { ++ cnt ; a == fa[a] ? a : Find( fa[a] ) ; } 
// // int main() {
// //     cin >> n ; for ( int i = 1 ; i <= n ; i ++ ) fa[i] = i ; 
// //     for ( int i = 1 , t ; i <= n ; cnt = 0 , i ++ ) 
// //         cin >> t , Find( t , cnt) == i ? ans = std :: min( ans ) : fa[a] = t ; 
// //     cout << ans << endl ; 
// // }



// // #include<bits/stdc++.h>
// // int n , fa[200005] , ans=0x3f3f3f , cnt ; 
// // int find(int x) { cnt ++ ; return ( fa[x] == x ? x : find( fa[x] )) ; }
// // int main(){
// // 	cin >> n;
// // 	for( int i = 1 ; i <= n ; i ++ ) fa[i] = i ;
// // 	for( int i = 1 , t ; i <= n ; cnt = 0 , i ++ ) 
// //         cin >> t , find(t) == i ? ans = std :: min(ans , cnt) : fa[i] = t ; 
// // 	cout << ans; 
// // }




// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
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
// #define endl '\n'
// #define int long long
// #define ll long long
// #define ull unsigned int int
// #define PII pair<int , int>
// #define TUP tuple<int , int , int>

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const ll LINF = 1e18 ;
// const int MOD = 80112002 ; 
// const int MOD2 = 998244353 ; 


// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// int n , m ;

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
//     cin >> n >> m ; 
//     queue<int> q ; 
//     vector<vector<int>> adj( n + 1 ) ; 
//     vector<int> indegree( n + 1) ; 
//     vector<int> outdegree( n + 1 ) ; 
//     vector<int> ans( n + 1 ) ; 
//     // 按照 hunter -> prey 的顺序进行排序 图是逆向统计 indegree 的 所以图应该存的是 prey -> hunter
//     // indegree[i] 表示 i 的 hunter 有几个
//     for ( int i = 1 ; i <= m ; i ++ ) {
//         int prey , hunter ; 
//         cin >> prey >> hunter ; 
//         adj[hunter].push_back( prey ) ;
//         // 入度是猎人有几个
//         indegree[prey] ++ ; 
//         // 出度是猎物有几个
//         outdegree[hunter] ++ ; 
//     }
    
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         if ( !indegree[i] ) {
//             q.emplace( i ) ;  
//             ans[i] = 1 ;
//         }
//     }
    
//     // 拓扑排序是在干啥 ? 
//     // 为什么这里能直接统计到最大食物链呢 因为这个拓扑排序会一直排序到这个链状结构的末端
//     // 这个 ans 相当于是 dp 数组了感觉 
//     while ( !q.empty() ) {
//         auto cur = q.front() ; q.pop() ; 

//         for ( auto &a : adj[cur] ) {
//             ans[a] += ans[cur] ;
//             ans[a] %= MOD ; 
//             if ( !--indegree[a] ) {
//                 q.emplace( a ) ;
//             }
//         }
//     }

//     int res = 0 ; 
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         if ( outdegree[i] == 0 ) {
//             res += ans[i] ;
//             res %= MOD ; 
//         }
//     }
//     cout << res << endl ;
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */