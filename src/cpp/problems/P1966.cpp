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
const int MOD1 = 1e8 - 3 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n ;
int exchangeCnt ;

struct fire{ 
    int val ; 
    int orinPos ; 
} ; 

vector<fire> matches1 , matches2 ; 
vector<int> arr ; 
vector<int> temp ; 



// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    matches1.resize( n + 1 ) ;
    matches2.resize( n + 1 ) ;
    arr.resize( n + 1 ) ;
    temp.resize( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> matches1[i].val ; 
        matches1[i].orinPos = i ; 
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> matches2[i].val ; 
        matches2[i].orinPos = i ; 
    }
}

void mergesort( int l , int r ) {
    if ( l >= r ) return ; 

    int mid = (l + r) / 2 ; 
    mergesort( l , mid ) ; 
    mergesort( mid + 1 , r ) ;

    int i = l ; 
    int j = mid + 1 ;
    int pos = l ; 
    while ( i <= mid && j <= r ) {
        if ( arr[i] <= arr[j] ) {
            temp[pos++] = arr[i++] ;  
        } else {
            temp[pos++] = arr[j++] ; 
            exchangeCnt = ( exchangeCnt + mid - i + 1 ) % MOD1 ; 
        }
        
    }

    while ( i <= mid ) temp[pos++] = arr[i++] ;
    while ( j <= r ) temp[pos++] = arr[j++] ;

    copy( temp.begin() + l , temp.begin() + r + 1 , arr.begin() + l ) ; 

}

void solve() {
     


}

// ========================== Idea =============================================
/*

同序积最大 , 所以要让两组火柴的元素的相对顺序是一致的

我一开始的思路就是把两个火柴全部变成有序序列
然后对原数组拥统计逆序对

1. 逆序对数量等于交换次数
2. 

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n ; 
    init() ;
    // temp = matches1 ; 
    // sort( temp.begin() , temp.end() ) ; 
    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     matches1[i] = lower_bound( temp.begin() , temp.end() , matches1[i] ) - temp.begin() ; 
    // }
    // temp = matches2 ; 
    // sort( temp.begin() , temp.end() ) ; 
    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     matches2[i] = lower_bound( temp.begin() , temp.end() , matches2[i] ) - temp.begin() ; 
    // }

    // for ( int i = 1; i <= n ; i ++ ) {
    //     arr[matches2[i]] = matches1[i] ; 
    // }

    // 按高度排序
    sort(matches1.begin() + 1, matches1.end(), [&] ( fire &a , fire &b ) {
        return a.val < b.val ; 
    });
    sort(matches2.begin() + 1, matches2.end(), [&] ( fire &a , fire &b ) {
        return a.val < b.val ; 
    });
    // 核心映射逻辑 将问题转化为求逆序对
    for (int i = 1; i <= n; ++i) {
        arr[matches2[i].orinPos] = matches1[i].orinPos;
    }

    mergesort( 1 , n ) ; 

    cout << exchangeCnt << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/
