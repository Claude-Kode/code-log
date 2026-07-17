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



// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void solve() {
     
    int n ; cin >> n ; 
    vector<int> arr(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }

    bool con = false ; 
    int l = 1 , r = n ; 
    vector<int> ans(1 , 0) ; 
    while ( l < r ) {
        if ( arr[l] < ans.back() == con ) {
            ans.push_back( arr[l ++] ) ;
            con ^= 1 ;
            cout << 'L' ;
        } else if ( arr[r] < ans.back() == con ) {
            ans.push_back( arr[r --] ) ; 
            con ^= 1 ;
            cout << 'R' ;
        } else {
            ans.push_back( arr[r --] ) ; 
            con ^= 1 ;
            cout << 'R' ;
        }
    }
    cout << endl ; 
}

// ========================== Idea =============================================
/*

排列中 任意两个数之间只有两种关系 我大于你 你大于我
好多大题的方法都是通过数学归纳法证明出来的
交替输出左右两项更大的和更小的
如果是输出更小的 他一定会比上一项更小 如果输出更大的 他一定比上一项更大

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n ; cin >> n ; 
        vector<int> arr( n ) ;
        for ( auto &a : arr ) cin >> a ;
        int l = 0 , r = n - 1 ; 
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( i % 2 ) {
                if ( arr[l] > arr[r] ) {
                    cout << 'L' ;
                    l ++ ; 
                }
                else {
                    cout << 'R' ;
                    r -- ; 
                }
            }
            else {
                if ( arr[l] > arr[r] ) {
                    cout << 'R' ;
                    r -- ;
                }
                else {
                    cout << 'L' ; 
                    l ++ ; 
                }
            }
        }
        cout << endl ; 
    }
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/
