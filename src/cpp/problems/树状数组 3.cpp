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

int n , m ; 
vector<int> arr , diffTree , preDiffTree ;

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

class Solution {
public:
    int reversePairs(vector<int>& record) {
        // increasing
        vector<int> sortedSequence ;
        int res = 0 ; 
        for ( int &a : record ) {
            // 对于每个数字 在有序序列中寻找插入的位置 
            // 这个位置的索引和总长度的差就是逆序对的个数
            // 位置就是插入后的位置 也就是他会取代第一个等于他的位置
            auto insertPos = lower_bound( sortedSequence.begin() , sortedSequence.end() , 1LL + a ) ; 
            res += sortedSequence.end() - insertPos ; 
            sortedSequence.insert( insertPos , a ) ; 
        }
        return res ; 
    }
} ;

int lowbit( int num ) {
    return num & -num ; 
}

void update( int pos , int deltaVal ) {
    for ( int i = pos ; i <= n ; i += lowbit( i ) ) 
        diffTree[i] += deltaVal ;
    for ( int i = pos ; i <= n ; i += lowbit( i ) )
        preDiffTree[i] += pos * deltaVal ; 
}

int calRangeSum( int l , int r ) {
    int suml1 = 0 , suml2 = 0 , suml = 0 ;
    for ( int i = l - 1 ; i > 0 ; i -= lowbit(i) ) 
        suml1 += diffTree[i] ; 
    for ( int i = l - 1 ; i > 0 ; i -= lowbit(i) ) 
        suml2 += preDiffTree[i] ; 
    suml = l * suml1 - suml2 ; 

    int sumr1 = 0 , sumr2 = 0 , sumr = 0 ;
    for ( int i = r ; i > 0 ; i -= lowbit(i) ) 
        sumr1 += diffTree[i] ; 
    for ( int i = r ; i > 0 ; i -= lowbit(i) ) 
        sumr2 += preDiffTree[i] ; 
    sumr = (r + 1) * sumr1 - sumr2 ; 

    return sumr - suml ; 

}

void solve() {


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
    cin >> n >> m ;
    arr.resize( n + 1 , 0 ) , diffTree.resize( n + 1 , 0 ) , preDiffTree.resize( n + 1 , 0 ) ;

    // cout << Solution().reversePairs( arr ) << endl ;

    for ( int i = 1 ; i <= n ; i ++ )   
        cin >> arr[i] , update( i , arr[i] - arr[i - 1] ) ; 
    
    while ( m -- ) {
        int op ; cin >> op ; 

        if ( op == 1 ) {

            int x , y , k ; cin >> x >> y >> k ;
            update( x , k ) ;
            if ( y + 1 <= n ) update( y + 1 , -k ) ; 

        }

        if ( op == 2 ) {

            int x , y ; cin >> x >> y ;
            cout << calRangeSum( x , y ) << endl ;

        }
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/


