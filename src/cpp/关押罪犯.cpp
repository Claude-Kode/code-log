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
#define ull unsigned long long
#define PII pair<int , int>
#define TUP tuple<int , int , int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const ll LINF = 1e18 ;
const int MOD = 1e9 + 7 ;
const int MOD2 = 998244353 ;

// ========================== Global Variables / Arrays ========================

vector<int> fri ;
vector<int> ene ;
vector<int> ranks ;

// ========================== Functions ========================================

void init( int n ) {
    fri.resize( n + 1 ) , ene.resize( n + 1 ) , ranks.resize( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) 
        fri[i] = i , ene[i] = 0 , ranks[i] = 1 ;
}

int Find( int a ) {
    if ( fri[a] == a ) 
        return a ; 
    else
        return fri[a] = Find( fri[a] ) ; 
}

void join( int a , int b ) {
    int ra = Find( a ) ; 
    int rb = Find( b ) ;

    if ( ranks[ra] <= ranks[rb] ) 
        fri[ra] = rb ;
    else 
        fri[rb] = ra ;

    if ( ranks[ra] == ranks[rb] ) 
        ranks[rb] ++ ; 
}

bool isSame( int a , int b ) {
    int ra = Find( a ) ;
    int rb = Find( b ) ; 
    return ra == rb ;   
}

void solve() {
    int n , m ; cin >> n >> m ; 
    init( n ) ; 
    vector<TUP> data( m ) ; 
    for ( auto &[a , b , value] : data ) 
        cin >> a >> b >> value ; 
    sort ( data.begin() , data.end() , []( TUP a ,TUP b ) {
        return get<2>( a ) > get<2>( b ) ;
    }) ;
    for ( auto &[a , b , value] : data ) {
        if ( isSame( a , b ) ) { 
            cout << value << endl ; return ; }
        else {
            if ( ene[a] == 0 ) ene[a] = Find( b ) ;
            else join( ene[a] , b ) ;
            if ( ene[b] == 0 ) ene[b] = Find( a ) ;
            else join( ene[b] , a ) ;  
        }
    }
    cout << 0 << endl ;
}

// ========================== Idea =============================================
/*

先不谈排序 如果两个人是敌人 要尽可能的把两个人分开
敌人的敌人是朋友 这里进行了这样的合并
然后是如果两个人已经是朋友了 你在这一步还有了矛盾值 说明两个必须被安排在同一个监狱里面

如果两个人有矛盾 就把他们分开
同时 进行朋友合并 朋友之间可以住在一个监狱里面
这里面的朋友不意味他们不会爆发冲突
假如进行到 i , 进行了一次朋友和并 意味着这两个人的冲突的值不会大于前面所有的 i 的值

把敌人分配到不同监狱 敌人的敌人分配到同一个监狱
从高到低进行分配 如果两个人已经在一个监狱 并且确定之后会爆发矛盾 由于是从高到低 他们爆发的矛盾一定是之后最大的
也就是说 在之前的遍历当中 矛盾都不会出现 因为尽管怎么分配都会发生矛盾 但是由于排序了的原因 他们的矛盾都是在后面爆发的

表面是并查集的合并 其实是分开 ? 

对于每个人 你有两种选择 第一种和他一个监狱 第二种和不是他的人一个监狱

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

1. 为什么要排序
2. 什么是带权并查集
3. 为什么仅仅通过合并集合 有冲突就能直接输出 ? 

*/
