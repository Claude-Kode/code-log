// #include <bits/stdc++.h>

// using namespace std ; 

// #define int long long 
// #define endl '\n'

// const int maxn = 1e9 ;
// const int mod = 1e9 + 7 ; 

// void solve() {
	
	
	
// }

// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
// 	int n , k ; cin >> n >> k ; 
// 	vector<int> arr( n ) ; 
// 	unordered_map<int , int> ump ; 
// 	ump[0] ++ ; 
// 	int xorSum = 0 , cnt = 0 ; 
// 	for ( int i = 0 ; i < n ; i ++ ) {
// 		cin >> arr[i] ;
// 		xorSum ^= arr[i] ; 
// 		int target = k ^ xorSum ; 
// 		if ( ump[target] ) {
// 			cnt += ump[target] ; 
// 		}
// 		ump[xorSum] ++ ; 
// 	}
// 	cout << cnt << endl ;	
// 	return 0 ; 
// }
// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque> 
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int , int , int>
// #define ull unsigned int int
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD2 = 998244353 ; 
// const int MOD = 1e9 + 7 ; 
// const ll LINF = 1e18 ;

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;



// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     int n , k , x , cnt = 0 ; cin >> n >> k ; 
//     vector<int> arr( n + 1 ) ; 
//     unordered_map<int , int> ump ; 
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         cin >> arr[i] ; 
//     }
//     for ( int i = 0 ; i <= n ; i ++ ) {
//         x ^= arr[i] ; cnt += ump[x ^ k] ; 
//         ump[x] ++ ; 
//     }
//     cout << cnt << endl ; 
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */
#include <bits/stdc++.h>
using namespace std ; 
int main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    long long n , k , x , cnt = 0 ; cin >> n >> k ; 
    vector<long long> arr( n + 1 ) ; 
    unordered_map<long long , long long> ump ; 
    for ( int i = 1 ; i <= n ; i ++ ) { cin >> arr[i] ; }
    for ( int i = 0 ; i <= n ; i ++ ) { x ^= arr[i] ; cnt += ump[x ^ k] ; ump[x] ++ ; }
    cout << cnt << endl ; 
    return 0 ; 
}