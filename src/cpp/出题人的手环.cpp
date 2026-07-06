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
vector<int> arr ; 
vector<int> seq ; 
vector<int> tree ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

inline int lowbit( int i ) {
    return i & -i ;
}

inline void update( int pos , int delta ) {
    for ( int i = pos ; i <= n ; i += lowbit(i) ) {
        tree[i] += delta ;
    }
}

inline int sum( int val ) {
    int res = 0 ; 
    for ( int i = val ; i > 0 ; i -= lowbit( i ) ) {
        res += tree[i] ; 
    } 
    return res ; 
}

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n ; 
    seq.resize( n + 1 ) ; 
    arr.resize( n + 1 ) ; 
    tree.resize( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
        // arr[i] += 1e9 + 10 ;
    }
    // vector<int> temp( arr.begin() + 1 , arr.end() )  ;  
    // sort( temp.begin() , temp.end() ) ;              
    // temp.erase( unique( temp.begin() , temp.end() ) , temp.end() ) ;  

    // unordered_map<int , int> rank_map;
    // for (int i = 0 ; i < temp.size() ; i ++ ) {
    //     rank_map[temp[i]] = i + 1 ;  
    // }

    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     arr[i] = rank_map[arr[i]] ;  
    //     seq[arr[i]] ++ ;
    // }
    vector<int> temp( arr.begin() + 1 , arr.end() )  ; 
    sort( temp.begin() , temp.end() ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        arr[i] = lower_bound( temp.begin() , temp.end() , arr[i] ) - temp.begin() + 1 ;
//         cout << arr[i] << ' ' ; 
        seq[arr[i]] ++ ; 
    }
    	
//     cout << endl ; 
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        seq[i] += seq[i - 1] ; 
    }

//     for ( int i = 1 ; i <= n ; i ++ ) {
//         cout << seq[i] << ' ' ; 
//     }
//     cout << endl ; 
    
    int ans_1 = 0 ; 
    for ( int i = n ; i > 0 ; i -- ) {
        // 这俩顺序有要求吗
        // 答案是没有
        ans_1 += sum( arr[i] - 1 ) , ans_1 %= MOD ; 
        update( arr[i] , 1 ) ; 
    }

// 	cout << ans_1 << endl ;
    
    int res = ans_1 , nxt = 0 , cur = ans_1 ; 
    for ( int i = n ; i > 1 ; i -- ) {
        // i 表示此时原排列中 第i个数是最后一个 
        int cntBigger = seq.back() - seq[arr[i]] ;
        int cntSmaller = seq[arr[i] - 1] ;
        nxt = cur - cntBigger + cntSmaller ; 
        // 为啥这里会出现负数啊
        if ( nxt < 0 ) 
            nxt += MOD ;  
//         cout << nxt << endl ; 
        res *= nxt , res %= MOD ; 
        cur = nxt ; 
    }

    cout << res % MOD << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

易错点: 
1. temp 的前导 0 在 arr[i] < 0 的时候离散化会出 bug
2. 这题 nxt 的更新过程中会出现负数 wtf 取模要考虑如果是负数应该怎么办
3. 二分查找竟然会比 hash 更快

*/



