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
const int MOD = 1e9 + 7 ;
const int MOD2 = 998244353 ;

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;
vector<int> parent , ranks , pre ;
int n , m , q ; 

// ========================== Functions ========================================

void init() {
    parent.resize( n + 1 ) ;
    ranks.resize( n + 1 , 0 ) ;
    pre.resize( n + 1 , 0 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        parent[i] = i ;
    }
}

int Find( int a ) {
    if ( parent[a] == a )
        return a ;
    // error 1 
    // 还有错误 应该先回溯找 再来回头更新 最后 return 
    int ppa = Find( parent[a] ) ;
    pre[a] += pre[parent[a]] ;
    return parent[a] = ppa ;
}

void Union( int a , int b , int w ) {
    int pa = Find( a ) ;
    int pb = Find( b ) ;
    if ( pa != pb ) {
        // error 2
        parent[pb] = pa ; 
        pre[pb] = pre[a] + w - pre[b] ; 
        // error 3
    }
}

void solve() {
    
}

// ========================== Idea =============================================
/*

所有的l 和 r 都抽象成节点 然后只要我知道所有的点和最右边的点的距离 我问哪两个随便求一下不行了
有点像 front 前缀问题 我又想像蓄水池一样写 但是一个点可能联通多个区间 没法表示
正常的前缀和数组是一个根节点是 0 的并查集

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;


    cin >> n >> m >> q ;
    init() ;
    for ( int i = 1 ; i <= m ; i ++ ) {
        int l , r , w ; cin >> l >> r >> w ;
        // error 4
        l -- ; 
        Union( l , r , w ) ;
    }

    while ( q -- ) {
        int x , y ; cin >> x >> y ;
        x -- ; 
        if ( Find( x ) != Find( y ) ) {
            cout << "UNKNOWN" << endl ;
        } else {
            cout << pre[y] - pre[x] << endl ;
        }
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/