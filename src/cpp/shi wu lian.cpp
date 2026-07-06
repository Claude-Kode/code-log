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

vector<int> fri , ene1 , ene2 , ranks ; 
// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;



// ========================== Functions ========================================

void init( int n ) {
    fri.resize( n + 1 ) , ene1.resize( n + 1 ) , ranks.resize( n + 1 ) , ene2.resize( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) 
        fri[i] = i , ene1[i] = 0 , ene2[i] = 0 , ranks[i] = 1 ;
        
}

int Find( int a ) {
    if ( fri[a] == a ) 
        return a ; 
    else
        return fri[a] = Find( a ) ; 
}

void join( int a , int b ) {
    int ra = Find( a ) ; 
    int rb = Find( b ) ;

    if ( ranks[ra] <= ranks[rb] ) 
        fri[ra] = rb ;
    else 
        fri[rb] = ra ;

    if ( ranks[ra] == ranks[rb] ) 
        ranks[rb] ++ ; 
}

bool isSame( int a , int b ) {
    int ra = Find( a ) ;
    int rb = Find( b ) ; 
    return ra == rb ;   
}

// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void solve() {
    
}

// ========================== Idea =============================================
/*

这道题就是 敌人的敌人才是朋友

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int n , k ; cin >> n >> k ;
    init( n ) ; 
    int cnt = 0 ; 
    vector<TUP> data( k ) ;
    for ( auto &[rel , a , b] ) {
        cin >> rel >> a >> b ; 
        if ( isSame( a , b ) ) 
            cnt ++ ; 
        else 
            if ( rel == 1 )
                join( a , b ) ; 
            else {
                if ( ene[a] == 0 ) ene[a] = Find( b ) ;
                else join( , b ) ; 
                if ( ene[b] == 0 ) ene[b] = Find( a ) ;
                else join( ene[ene[b]] , a ) ; 
            }
    }
    cout << cnt << endl ; 
    return 0 ;
}
// ========================== Question =========================================
/*

*/
