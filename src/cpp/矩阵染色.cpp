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
const int maxn = 1e6 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m , sx , sy , tx , ty ; 
int dirs[4][2] = { {1 , 0 } , {-1 , 0} , {0 , 1} , {0 , -1} } ; 
vector<vector<PII>> colorsMaps( maxn ) ; 


// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

bool isLegalCoordinate( int x , int y ) {
    return x >= 1 && x <= n && y >= 1 && y <= m ;
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
    vector<vector<int>> colorMatrix( n + 1 , vector<int>( m + 1 ) ) ;
    vector<vector<int>> vis( n + 1 , vector<int>( m + 1 ) ) ; 
    for( int i = 1 ; i <= n ; i ++ ) {
        for( int j = 1 ; j <= m ; j ++ ) {
            cin >> colorMatrix[i][j] ; 
            colorsMaps[colorMatrix[i][j]].emplace_back( i , j ) ;
        }
    }

    cin >> sx >> sy >> tx >> ty ; 

    // TUP = tuple< x , y , step >
    queue<TUP> q ; 
    for( auto &[x , y] : colorsMaps[colorMatrix[sx][sy]] ) {
        if ( isLegalCoordinate(x , y) ) {
            q.emplace( x , y , 0 ) ; 
            vis[x][y] = 1 ;
        }
    }
    
    while( !q.empty() ) {
        auto &[x , y , step] = q.front() ; q.pop() ;

        // res judge 
        if ( x == tx && y == ty ) {
            cout << step << endl ; 
            break ; 
        }

        // legal PII<x , y> push 
        for( auto &dir : dirs ) {
            int nx = x + dir[0] , ny = y + dir[1] ; 
			if ( isLegalCoordinate(nx , ny) && !vis[nx][ny] ) {
                q.emplace( nx , ny , step + 1 ) ; 
                vis[nx][ny] = 1 ; 
            }
            int nxtColor = colorMatrix[nx][ny] ; 
            for( auto &[xx , yy] : colorsMaps[nxtColor] ) {

                if ( isLegalCoordinate(xx , yy) && !vis[xx][yy] ) {
                    q.emplace( xx , yy , step + 1 ) ;     
                }
            }

        }
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/



#include <bits/stdc++.h>
#define int long long 
#define PII pair<int , int>
#define TUP tuple<int , int , int> 
using namespace std ;
int n , m , sx , sy , tx , ty ; 
int dirs[4][2] = { {1 , 0 } , {-1 , 0} , {0 , 1} , {0 , -1} } ; 
vector<vector<PII>> colorsMaps( maxn ) ; 
bool isLegalCoordinate( int x , int y ) {
    return x >= 1 && x <= n && y >= 1 && y <= m ;
}
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    cin >> n >> m ;
    vector<vector<int>> colorMatrix( n + 1 , vector<int>( m + 1 ) ) ;
    vector<vector<int>> vis( n + 1 , vector<int>( m + 1 ) ) ; 
    for( int i = 1 ; i <= n ; i ++ ) 
        for( int j = 1 ; j <= m ; j ++ ) 
            cin >> colorMatrix[i][j] , colorsMaps[colorMatrix[i][j]].emplace_back( i , j ) ;
	cin >> sx >> sy >> tx >> ty ; 
    queue<TUP> q ; 
    for( auto &[x , y] : colorsMaps[colorMatrix[sx][sy]] ) 
        if ( isLegalCoordinate(x , y) ) 
            q.emplace( x , y , 0 ) , vis[x][y] = 1 ;
    while( !q.empty() ) {
        auto &[x , y , step] = q.front() ; q.pop() ;
        if ( x == tx && y == ty ) { cout << step << endl ; break ; }
        for( auto &dir : dirs ) {
            int nx = x + dir[0] , ny = y + dir[1] ; 
			if ( isLegalCoordinate(nx , ny) && !vis[nx][ny] ) {
                q.emplace( nx , ny , step + 1 ) , vis[nx][ny] = 1 ; 
                for( auto &[xx , yy] : colorsMaps[colorMatrix[nx][ny]] ) 
                    q.emplace( xx , yy , step + 1 ) , vis[xx][yy] = 1 ; 
            }
        }
    }
    return 0 ;
}