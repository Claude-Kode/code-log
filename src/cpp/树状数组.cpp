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
vector<int> diffTree , preDiffTree ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

// pos -> 1 base 

int lowebit( int i ) { return (i & -i) ; }

void update( int pos , int delta ) {
    // 为什么这里是 + 而且是小于等于 n 
    for ( int i = pos ; i <= n ; i += lowebit( i ) ) 
        diffTree[i] += delta ; 
    for ( int i = pos ; i <= n ; i += lowebit( i ) ) 
        preDiffTree[i] += ( n + 1 - pos ) * delta ;     
}

int query( int l , int r ) {
    int suml = 0 , sumr = 0 ;
    for ( int i = l - 1 ; i > 0 ; i -= lowebit( i ) ) 
        suml += preDiffTree[i] ; 
    for ( int i = r ; i > 0 ; i -= lowebit( i ) ) 
        sumr += preDiffTree[i] ;     
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
    vector<int> arr( n + 1 ) ; 
    diffTree.resize( n + 1 ) , preDiffTree.resize( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ;
        int val = arr[i] - ( i == 1 ? 0 : arr[i - 1] ) ;
        // val == diff[i]
        update( i , val ) ;
    }    
    // for ( auto &a : diffTree ) 
    //     cout << a << endl ;
    while ( m -- ) {
        int op ; cin >> op ;
        switch ( op ) {
            int x , y , k ;  
            case 1 : 
                cin >> x >> y >> k ;
                update( x , k ) ; 
                if ( y + 1 <= n ) 
                    update( y + 1 , -k ) ; 
                break ; 

            case 2 : 
                cin >> x >> y ; 
                cout << query( x , y ) << endl ; 
                break ;
        } 
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
