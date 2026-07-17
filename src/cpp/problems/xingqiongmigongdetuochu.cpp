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
#define TUP tuple<int, int, int>
#define ull unsigned long long
#define PII pair<int, int>
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

int l , n , m ;
int sx , sy , sz , ex , ey , ez ; 

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}} ;

vector<vector<TUP>> mp( 26 ) ; 
vector<vector<vector<int>>> arr ; 
vector<vector<vector<int>>> vis ; 
vector<vector<vector<int>>> graph ; 
vector<int, unordered_map<TUP, TUP>> ump ; 

struct infor {
	int x ;
	int y ; 
    int z ; 
	int val ;
	bool hasSkipped ; 
} ;

queue<infor> q ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

bool check( int x , int y , int z ) {
    return x > 0 && x <= n && y > 0 && y <= m && z > 0 && z <= l ; 
}

bool isSkipped( int x , int y , int z ) {
    return arr[z][x][y] >= 'A' && arr[z][x][y] <= 'Z' ; 
}

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> l >> n >> m ;
    for ( int k = 1 ; k <= l ; k ++ ) {
        for ( int i = 1 ; i <= n ; i ++ ) {
            for ( int j = 1 ; j <= m ; j ++ ) {
                char temp ; cin >> temp ; 
                if ( temp == '.' ) arr[k][i][j] = 1 ; 
                else if ( temp == '#' ) arr[k][i][j] = 0 ; 
                else if ( temp == '@' ) sx = i , sy = j , sz = k , arr[k][i][j] = 1 ; 
                else if ( temp == '=' ) ex = i , ey = j , ez = k , arr[k][i][j] = 1 ;
                else mp[arr[k][i][j] - 'A'].emplace_back( i , j , k ) , arr[k][i][j] = temp ; 
            }
        }
    }
    
    for ( int i = 1 ; i <= 26 ; i ++ ) if ( !mp[i].empty() ) {
        auto a = mp[i][0] , b = mp[i][1] ; 
        ump[i][a] = b ; 
        ump[i][b] = a ; 
    } 

    

    return 0 ;
}
// ========================== Question =========================================
/*

*/

