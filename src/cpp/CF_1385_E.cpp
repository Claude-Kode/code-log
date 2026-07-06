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


// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void solve() {
     
    int n , m ; cin >> n >> m ;
    vector<int> indegree( n + 1 ) ;  
    vector<int> indirected( n + 1 ) ; 
    vector<vector<int>> grid( n + 1  , vector<int>( n + 1 , 0 )) ; 
    while ( m -- ) {
        int t , u , v ; cin >> t >> u >> v ; 
        grid[u][v] = 1 ;
        indegree[u] ++ ; 
        if ( t ) {
            grid[v][u] = 1 ;
            indegree[v] ++ ;
            indirected[u] ++ ;
            indirected[v] ++ ;  
        } 
    } 

    queue<int> q ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( !indegree[i] ) {
            for ( int j = 1 ; j <= m ; j ++ ) {
                if ( grid[i][j] ) indegree[j] -- ;
            }
            q.push( i ) ;   
        }
    }

    if ( q.empty() ) {        
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( indegree[i] == indirected[i] ) {
                q.push( i ) ; 
                for ( int j = 1 ; j <= m ; j ++ ) {
                    if ( grid[i][j] ) {
                        grid[j][i] = 0 ; 
                        indirected[i] -- ;
                        indegree[i] -- ; 
                    }
                }
            }
        }
    }

    if ( q.empty() ) { cout << "NO" << endl ; return ; }
    
    while ( !q.empty() ) {
        auto a = q.front() ; q.pop() ; 

        for ( int i = 1 ; i <= m ; i ++ ) {
            if ( grid[a][i] ) indegree[i] -- ;
            if ( indegree[i]) 
        }

        if ( q.empty() ) {        
            for ( int i = 1 ; i <= n ; i ++ ) {
                if ( indegree[i] == indirected[i] ) {
                    q.push( i ) ; 
                    for ( int j = 1 ; j <= m ; j ++ ) {
                        if ( grid[i][j] ) {
                            grid[j][i] = 0 ; 
                            indirected[i] -- ;
                            indegree[i] -- ; 
                        }
                    }
                }
            }
        }

        if ( q.empty() ) { cout << "NO" << endl ; return ; }
    }

    cout << "YES" << endl ; 
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            if ( grid[i][j] ) cout << i << ' ' << j << endl ; 
        }
    }

}

// ========================== Idea =============================================
/*

要让无向边变成有向边 , 让图联通而且不出现环

1.根节点要在呢么选择
2.如果只要碰到环就解掉 , 为什么这种方式是可行的

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt -- ) {
        solve() ;
    }
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/

