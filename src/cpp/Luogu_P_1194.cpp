/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
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
const int MOD1 = 998244353 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int A , B ; 
int ans ; 

vector<int> dis ; 
vector<int> beenBought ;
vector<vector<int>> price ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    cin >> A >> B ;
    price.resize( B + 1 , vector<int>( B + 1 , A )) ; 
    beenBought.resize( B + 1 ) ;  
    dis.resize( B + 1 , A ) ; 
    for ( int i = 1 ; i <= B ; i ++ ) {
        for ( int j = 1 ; j <= B ; j ++ ) {
            cin >> price[i][j] ; 
            if ( i != j ) {
                if ( price[i][j] == 0 ) price[i][j] = A ; 
                else price[i][j] = min( price[i][j] , A ) ; 
            }

        }
    }
}

void prim( int start ) {

    ans += dis[start] ; 

    beenBought[start] = 1 ; 
    // adj_grid[i][j] === i --> j ( directed edge )
    for ( int j = 1 ; j <= B ; j ++ ) {
        dis[j] = min( dis[j] , price[start][j] ) ; 
    }

    while ( 1 ) {
        int mnw = INT_MAX ; 
        int mnh = -1 ; 
        for ( int i = 1 ; i <= B ; i ++ ) {
            if ( !beenBought[i] && mnw > dis[i] ) {
                mnw = dis[i] ;
                mnh = i ;
            }
        }

        if ( mnh == -1 ) break ; 

        beenBought[mnh] = 1 ; 
        dis[mnh] = 0 ;  
        ans += mnw ; 
        
        for ( int j = 1 ; j <= B ; j ++ ) {
            // if ( j == mnh ) continue ;  
            dis[j] = min( dis[j] , price[mnh][j] ) ;
        }

    }
    
    // cout << "prim" << endl ; 

}

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    init() ; 
    for ( int i = 1 ; i <= B ; i ++ ) {
        if ( !beenBought[i] ) prim( i ) ; 
    }
    
    cout << ans << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/
