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
#include <utility>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int , int>
#define TUP tuple<int , int , int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const ll LINF = 1e18 ;
const int MOD = 1e9 + 7 ;
const int MOD2 = 998244353 ;

// ========================== Global Variables / Arrays ========================
vector<int> father , ranks , usize ; 

// ========================== Functions ========================================

void init ( int n ) {
    father.resize( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) 
        father[i] = i ;

    ranks.resize( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) 
        ranks[i] = 1 ;
    
    usize.resize( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) 
        usize[i] = 1 ;
        
}

int ufind ( int a ) {
    if ( father[a] == a ) return a ; 
    return father[a] = ufind( father[a] ) ;
}

void join ( int a , int b ) {
    int ra = ufind( a ) ;
    int rb = ufind( b ) ;
    if ( ra == rb ) return ; 

    if ( ranks[ra] <= ranks[rb] ) 
        father[ra] = rb , usize[rb] ++ ; 
    else 
        father[rb] = ra , usize[ra] ++ ;
        
    if ( ranks[ra] == ranks[rb] ) 
        ranks[rb] ++ ; 
    
}

bool isSame ( int a , int b ) {
    int ra = ufind( a ) ;
    int rb = ufind( b ) ;
    return ra == rb ;
}

// ========================== Idea =============================================
/*
这道题就是一个并查集
但是最后要查根节点的个数
这怎么搞 ??? 
就是遍历一下有几个 father 是他自己呗
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int n , m ; cin >> n >> m ; 
    init( n ) ; 
    while ( m -- ) {
        int x , y ; cin >> x >> y ; 
        join( x , y ) ; 
    }
    int cnt = 0 , mx = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( father[i] = i ) cnt ++ ; 
        mx = max ( mx , usize[i] ) ;
    }
    cout << cnt << ' ' << mx ;
    return 0 ;
}
// ========================== Question =========================================
/*

*/
