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
const int maxn = 300001 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n ;
int i , j ; 
char op ;

vector<int> cnt ; 
vector<int> front ; 
vector<int> ranks ; 
vector<int> parent ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    cin >> n ; 
    cnt.resize( maxn , 1 ) , front.resize( maxn , 0 ) , parent.resize( maxn ) , ranks.resize( maxn , 1 ) ;  
    for ( int i = 1 ; i <= maxn - 1 ; i ++ ) {
        parent[i] = i ; 
    }
}

int Find( int a ) {
    if ( a == parent[a] ) 
        return a ; 
    else {
        // return parent[a] = Find( parent[a] ) 
        // front[a] += front[parent[a]] ; 
        int fa = Find( parent[a] ) ; 
        // 这里的回溯是不是类似记忆化的拆解子问题手段
        // 每个front 只能 += 他的上一级 相当于前缀和做法
        front[a] += front[parent[a]] ; 
        return parent[a] = fa ;
    }    
}

void merge( int a , int b ) {
    int pa = Find( a ) ; 
    int pb = Find( b ) ; 
    if ( pa == pb ) 
        return ;

    // 走到这一步 a , b 能确保是直接连接在根节点上的

    front[pa] += cnt[pb] ; 
    cnt[pb] += cnt[pa] ;
    parent[pa] = pb ; 
    
    // if ( ranks[pa] <= ranks[pb] ) {
    //     front[pa] += cnt[pb] ; 
    //     parent[pa] = pb ; 
    //     cnt[pb] += cnt[pa] ;
    // }
    // else {
    //     front[pb] += cnt[pa] ; 
    //     parent[pb] = pa ; 
    //     cnt[pa] += cnt[pb] ;        
    // }

    // if ( ranks[pa] == ranks[pb] )   
    //     ranks[pb] ++ ; 
}


bool isSame( int a , int b ) {
    return Find( a ) == Find( b ) ; 
}


void solve() {
    
    cin >> op >> i >> j ; 
    if ( op == 'M' ) {
        merge( i , j ) ; 
    }

    if ( op == 'C' ) {
        isSame( i , j ) ? cout << labs( front[i] - front[j] ) - 1 << endl :  cout << -1 << endl ; 
        // if ( isSame( i , j ) ) {
        //     cout << labs( front[i] - front[j] ) - 1 << endl ; 
        // }
        // else {
        //     cout << -1 << endl ; 
        // }
    }
    
}

// ========================== Idea =============================================
/*

cnt 是在 merge 里面更新的
这个基本是直觉了
front 是在 find 里面更新的
计算的是前驱 所以说在有递归的 find 里面就合理了

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    


    init() ; 
    while ( n -- ) solve() ; 


    return 0 ;
}
// ========================== Question =========================================
/*

*/






// 