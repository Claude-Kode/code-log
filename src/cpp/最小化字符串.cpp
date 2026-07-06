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
const int INF = 0x3f3f3f3f3f3f3 ;
const int MOD2 = 998244353 ; 
const int MOD = 1e9 + 7 ; 
const ll LINF = 1e18 ;

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , k ; 
vector<int> parent( 26 , 0 ) ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    for ( int i = 1 ; i <= 25 ; i ++ ) 
        parent[i] = i ; 
}

int Find( int a ) {
    return parent[a] == a ? a : parent[a] = Find( parent[a] ) ;
}

void merge( int a , int b ) {
    int pa = Find( a ) , pb = Find( b ) ; 
    parent[pa] = parent[pb] ; 
}

void solve() {
     


}

// ========================== Idea =============================================
/*

考虑一种特殊情况 最大字典序字母减去 a == gap
gap <= k 则可以全部转化为 a 
既然追求字典序最小 核心是要让靠前的字符更小 但是这道题替换的顺序是不确定的
也就是说可能存在一种方案 
我觉得就是普通的贪心 直接把从第一个到最后一个依次全部转化成 a 


把所有字符去重 然后倒序排序 向后遍历 如果哪一步的 gap <= k 直接全部转化 剩下的字符 位置优先
这个应该是错的 本来就是应该位置优先转化

直接从前向后遍历 看见的就转还成 转化成 a 就行了 直到用光为止
但是怎么考虑覆盖性问题呢
就是可能只要加一点钱 就可以搞定很多的转化

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;

    int tt ; cin >> tt ; 
    while ( tt -- ) {
        cin >> n >> k ;
        init() ; 
        vector<int> str( n ) ; 
        for ( auto &a : str ) {
            char temp ; cin >> temp ; 
            a = temp - 'a' ; 
        }
        for ( auto &a : str ) {
            while ( Find(a) > 0 && k > 0 ) {
                merge( Find(a) , Find(a) - 1 ) ; 
            }
        }
        for ( auto &a : str ) 
            cout << (char)(Find(a) + 'a') ;
        cout << endl ; 
    }
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/
