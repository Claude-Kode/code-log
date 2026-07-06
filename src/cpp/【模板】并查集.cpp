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
vector<int> father ;
vector<int> ranks ; 

// ========================== Functions ========================================

// 我以后的统一范式 合并是把前面的参数连到后面上 ( 没有按秩合并的时候 )


// // 并查集初始化
// void init( int n ) {
//     father.resize( n ) ; 
//     for ( int i = 0 ; i < n ; i ++ ) {
//         father[i] = i ;
//     }
// }
// // 并查集里寻根的过程
// int find( int u ) {
//     return u == father[u] ? u : father[u] = find( father[u] ) ; // 路径压缩
// }

// // 判断 u 和 v是否找到同一个根
// bool isSame( int u, int v ) {
//     u = find( u ) ;
//     v = find( v ) ;
//     return u == v ;
// }

// // 将v->u 这条边加入并查集
// void join( int u , int v ) {
//     u = find( u ) ; // 寻找u的根
//     v = find( v ) ; // 寻找v的根
//     if ( u == v ) return ; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
//     father[v] = u ;
// }

// int n = 1005; // n根据题目中节点数量而定，一般比节点数量大一点就好
// vector<int> father = vector<int> (n, 0) ; // C++里的一种数组结构
// vector<int> ranks = vector<int> (n, 1) ; // 初始每棵树的高度都为1

// // 并查集初始化
// void init() {
//     for ( int i = 0 ; i < n ; i ++ ) {
//         father[i] = i ;
//         ranks[i] = 1 ; // 也可以不写
//     }
// }
// // 并查集里寻根的过程
// int find( int u ) {
//     return u == father[u] ? u : find( father[u] ) ;// 注意这里不做路径压缩
// }

// // 判断 u 和 v是否找到同一个根
// bool isSame( int u, int v ) {
//     u = find( u ) ;
//     v = find( v ) ;
//     return u == v ;
// }

// // 将v->u 这条边加入并查集
// void join( int u, int v ) {
//     u = find( u ) ; // 寻找u的根
//     v = find( v ) ; // 寻找v的根

//     if ( ranks[u] <= ranks[v] ) father[u] = v ; // ranks小的树合入到ranks大的树
//     else father[v] = u ;

//     if (ranks[u] == ranks[v] && u != v) ranks[v]++; // 如果两棵树高度相同，则v的高度+1，因为上面 if (ranks[u] <= ranks[v]) father[u] = v; 注意是 <=
// }



void init ( int n ) {
    father.resize( n + 1 ) ;  
    for ( int i = 1 ; i <= n ; i ++ ) 
        father[i] = i ; 

    ranks.resize( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) 
        ranks[i] = 1 ; 

}

// find 进行的复杂度跟他进行过的次数有关系 第一次是 nlogn 剩下后面都是 O( 1 )
// 因为你每次递归的时候 都进行了一次优化
int unionFind ( int a ) {
    if ( father[a] == a ) return a ;
    return father[a] = unionFind( father[a] ) ;
} 

bool isSame ( int a , int b ) {
    int root_of_a = unionFind( a ) ;
    int root_of_b = unionFind( b ) ;
    return root_of_a == root_of_b ;
}

// 按秩序合并 简称 按秩合并 
// 两个集合 把数字的映射关系画出图来 相当于两颗树 ( 你看呗 , a -> b 像不像树上两个连接的节点 ) 
// 所以你的 join 和 find 还有各种行为 本质上是在一棵树上进行的操作 
// 所以你操作进行的快慢啥的跟你的树的深度 关系很大
// 那这个时候合并两颗子集树就要寻思寻思了 怎么合并能让合并后形成的那棵树高度最小呢
// 注意 思考的时候要记得并查集的合并方式是 把两个树的根节点挑一个出来 另一个根节点成为这个根节点的子节点
// 自己画图别画错了会得出错误的结论
// 最后的结论是 层数小的树应该连接到层数高的树上
// 实现方式就是用另一个映射数组 ranks
// ranks[a] = b , a 元素所在的集合树的深度是 b 
// 具体看代码 初始化的啥的自己理解
void join ( int a , int b ) {
    int root_of_a = unionFind( a ) ;
    int root_of_b = unionFind( b ) ;
    if ( root_of_a == root_of_b ) return ; 
    // 这里是把两个根节点合并 ( 按秩合并 )
    if ( ranks[root_of_a] <= ranks[root_of_b] ) 
        father[root_of_a] = root_of_b ;
    else 
        father[root_of_b] = root_of_a ;
    // 更新ranks
    if ( ranks[root_of_a] == ranks[root_of_b] )
        // 如果两棵树高度相同，则v的高度+1，
        // 因为上面 相等的时候默认是连接到后面的 b 
        // 因为每次查询都只会查到根节点 所以只更新根节点就可以了
        // 为啥只有相同的时候才更新 ? 因为上一行都说了
        // 如果你更高 你肯定不用更新 因为合并后树的高度没变还是你
        // 如果你矮 合并之后的树根节点就不是你了 查也是查别人 更新你干啥
        // 但是如果相同就得更新了 因为新的根节点的高度一定是 + 1 
        // 有点数学归纳法的意思了 品一品就好
        ranks[root_of_b] ++ ; 
}

inline void solve() {
    int n , m ; cin >> n >> m ;
    init( n ) ; 
    while ( m -- ) {
        int op , a , b ;
        cin >> op >> a >> b ; 
        if ( op == 1 ) 
            join( a , b ) ;
        else 
            isSame( a , b ) ? cout << 'Y' << endl : cout << 'N' << endl ;
    }
}

// ========================== Idea =============================================
/*

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    solve() ; 
    return 0 ;
}
// ========================== Question =========================================
/*

*/

