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

int n ;
vector<int> leftSmallerTree , rightBiggerTree ; 
vector<int> leftSmallerCnt , rightBiggerCnt ;

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

int lowbit( int i ) {
    return i & -i ;
}

void update( vector<int> &tree , int pos , int deltaVal ) {
    for ( int i = pos ; i <= n ; i += lowbit(i) ){
        tree[i] += deltaVal ;
    }    
}

int query( vector<int> &tree , int val ) {
    int cnt = 0 ; 
    for (int i = val ; i > 0 ; i -= lowbit(i) ) {
        cnt += tree[i] ;
    }  
    return cnt ; 
}

void solve() {
    


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;

    // RE 看看是不是树的初始化没有做好
    cin >> n ;
    leftSmallerTree.resize( n + 1 ) ; 
    leftSmallerCnt.resize( n + 1 ) ; 
    rightBiggerTree.resize( n + 1 ) ; 
    rightBiggerCnt.resize( n + 1 ) ; 


    // TLE 是什么原因呢 
	// for loop wrong 
	// 写函数一定要注意了是不是引用传递   
	// 调用 query 的时候查询的值出错了
    vector<int> arr( n + 1 ) ; 
    for( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }
    // 这里离散化的时候数组的 base 值会影响结果的 还有 arr 里面的序列数值也会因为 temp.begin 而改变的
    // 如果 temp == arr 都是 1-based 那么 temp 的有效元素 - temp.begin() >= 1 就不用再额外加 1 了
    // 另外这个错误十分隐蔽 因为如果最大的数字有多个 那么 + 1 是不会越界的 很阴
    vector<int> temp = arr ;
    sort( temp.begin() + 1 , temp.end() ) ; 

    for( int i = 1 ; i <= n ; i ++ ) {
        arr[i] = lower_bound( temp.begin() + 1 , temp.end() , arr[i] ) - temp.begin() ;
    }

    // 查询递增对 
    for ( int i = 1 ; i <= n ; i ++ ) {  
        update( leftSmallerTree , arr[i] , 1 ) ; 
        leftSmallerCnt[i] = query( leftSmallerTree , arr[i] - 1 ) ;
    }

    for ( int i = n ; i >= 1 ; i -- ) {    
        update( rightBiggerTree , arr[i] , 1 ) ; 
        rightBiggerCnt[i] = (n - i + 1) - query( rightBiggerTree , arr[i] ) ;
    }

    // cout << "leftSmaller: " ;
    // for ( auto &a : leftSmallerCnt ) 
    //     cout << a << ' ' ;
    // cout << endl << "rightBigger: " ;
    // for ( auto &a : rightBiggerCnt ) 
    //     cout << a << ' ' ;
    // cout << endl ;

	// rightBiggerCnt.back() = 0 ; 

    int res = 0 ; 
    for ( int i = 2 ; i <= n - 1 ; i ++ ) {
        res += leftSmallerCnt[i] * rightBiggerCnt[i] ; 
    }

    cout << res << endl ;


    // // 查询逆序对
    // for ( int i = n ; i >= 1 ; i -- ) {
    //     update( descendingTree , i , 1 ) ; 
    //     query( descendingTree , descendings , arr[i] - 1 ) ;
    // }

    // int res = 0 ; 
    // for ( int i =1 ; i <= n ; i ++ ) {
    //     res += ascendings[i] * descendings[i] ;
    // }
	
    // for ( auto &a : ascendings ) 
    //     cout << a << ' ' ;
    // cout << endl ; 
    // for ( auto &a : descendings ) 
    //     cout << a << ' ' ;
    // cout << endl ;  

//     cout << res << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/
