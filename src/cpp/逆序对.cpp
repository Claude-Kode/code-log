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
int res = 0 ; 
vector<int> tree ; 

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

void update(int pos , int deltaVal) {
    for ( int i = pos ; i >= n ; i += lowbit(i) ){
        tree[i] += deltaVal ;
    }    
}

void query( int val ) {
    for (int i = val ; i > 0 ; i -= lowbit(i) ) {
        res += tree[i] ; 
    } 
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
    // 1-based tree 
    tree.resize( n + 1 ) ;
    vector<int> arr( n ) , temp ;
    int index = 0 ; 
    for ( auto &val : arr ) {
        cin >> val ;
    }
    temp = arr ; 
    sort(temp.begin() , temp.end() ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        arr[i] = lower_bound( temp.begin() , temp.end() , arr[i] ) - temp.begin() + 1 ; 
    }
    for ( int i = n - 1 ; i >= 0 ; i -- ) {
        update( arr[i] , 1 ) ;
        query( arr[i] - 1 ) ;
    }
    cout << res << endl ; 
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/
