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
#include <utility>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int , int>
#define TUP tuple<int , int , int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const ll LINF = 1e18 ;
const int MOD = 1e9 + 7 ;
const int MOD2 = 998244353 ;

// ========================== Global Variables / Arrays ========================
vector<vector<string>> ans ( 3 ) ;  
vector<bool> vis ( 5 ) ; 
string temp ; 
// ========================== Functions ========================================
void DFS ( int step , int n , vector<string> &ans ) {
    if ( step == n ) {
        ans.push_back( temp ) ;
    }
    else {
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( !vis[i] ) {
                vis[i] = true ; temp.push_back(i + '0') ;
                DFS (  step + 1 , n , ans ) ;
                vis[i] = false ; temp.pop_back() ; 
            }
        }
    }
}

// ========================== Idea =============================================
/*

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    for ( int i = 2 ; i <= 4  ; i ++ ) 
        { DFS ( 0 , i , ans[i - 2] ) ; vis.clear() ; vis.resize(5 , false) ; temp.clear() ; }
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        string str ; int j , k ;
        cin >> str >> j >> k ;
        string a = ans[str.size() - 2][j - 1] , b  = ans[str.size() - 2][k - 1] ;
        int cnt = 0 ;
        for ( int i = 0 ; i < str.size() ; i ++ ) if ( a[i] == b[i] ) cnt ++ ;
        cout << cnt << 'A' << str.size() - cnt << 'B' ; 
        cout << endl ;
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
