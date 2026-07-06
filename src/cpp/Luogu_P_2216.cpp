// // header file
// #include <iostream>
// #include <algorithm>
// #include <deque>
// #include <vector>
// // macro definition
// #define endl '\n'
// #define int long long
// // namespace declarations
// using namespace std ;
// // global variables && arrays

// // functions declarations

// //idea
// /*
// 对每一行预处理然后单调队列
// 对于每一行进行 单调递增队列

// 最大值单调队列处理  ans_max

// 行的双端队列滑动窗口 ans_max_row

// 最小值单调队列处理 ans_min

// 行的双端队列滑动串口 ans_min_row

// */
// // codes
// signed main(){
// 	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
// 	int a , b , n ;
// 	cin >> a >> b >> n ;
// 	vector<vector<int>> arr ( a , vector<int> ( b ) ) ;
// 	for ( auto &row : arr )
// 		for ( auto &a : row ) 
// 			cin >> a ;
	
// 	// max ans 
// 	// 除arr外所有数组的元素均为arr映射下标
// 	vector<vector<int>> ans_max_row ;
// 	vector<vector<int>> ans_min_row ;
// 	for ( int i = 0 ; i < a ; i ++ ) {
// 		deque<int> mx , mn ;
// 		ans_max_row.push_back( vector<int>() ) ;
// 		ans_min_row.push_back( vector<int>() ) ;
// 		for ( int j = 0 ; j < b ; j ++ ) {
// 			int l = j - n + 1 ;
// 			while ( !mx.empty() && arr[i][mx.back()] <= arr[i][j] ) 
// 				mx.pop_back() ;
// 			while ( !mn.empty() && arr[i][mn.back()] >= arr[i][j] )
// 				mn.pop_back() ;

// 			mx.push_back( j ) ;
// 			mn.push_back( j ) ;

// 			if ( l > mx.front() ) 
// 				mx.pop_front() ;
// 			if ( l > mn.front() )
// 				mn.pop_front() ;

// 			if ( j >= n - 1 ) {
// 				ans_max_row[i].push_back( mx.front() ) ;
// 				ans_min_row[i].push_back( mn.front() ) ;
// 			}
// 		} 
// 	}
// 	// for ( auto &row : ans_max_row ) {
// 	// 	for ( auto &a : row ) cout << a << ' ' ;
// 	// 	cout << endl ;
// 	// }
// 	// cout << endl ;
// 	// for ( auto &row : ans_min_row ) {
// 	// 	for ( auto &a : row ) cout << a << ' ' ;
// 	// 	cout << endl ;
// 	// }
// 	// row -> col proc -> ans
// 	// i -> col ; j -> row
// 	vector<vector<int>> ans_max ( a - n + 1 , vector<int> ( b - n + 1 , 0 ) ) ;
// 	vector<vector<int>> ans_min ( a - n + 1 , vector<int> ( b - n + 1 , 0 ) ) ;
// 	for ( int i = 0 ; i < b - n + 1 ; i ++ ) {
// 		deque<int> mx , mn ;
// 		// enumerate row
// 		for ( int j = 0 ; j < a ; j ++ ) {
// 			int l = j - n + 1 ;
// 			while ( !mx.empty() && arr[mx.back()][ans_max_row[mx.back()][i]] <= arr[j][ans_max_row[j][i]] ) 
// 				mx.pop_back() ;
// 			while ( !mn.empty() && arr[mn.back()][ans_min_row[mn.back()][i]] >= arr[j][ans_min_row[j][i]] )
// 				mn.pop_back() ;

// 			mx.push_back( j ) ;
// 			mn.push_back( j ) ;

// 			if ( l > mx.front() ) 
// 				mx.pop_front() ;
// 			if ( l > mn.front() )
// 				mn.pop_front() ;

// 			if ( j >= n - 1 ) {
// 				// cout << j - n + 1 << ' ' << i << endl ;
// 				ans_max[j - n + 1][i] = mx.front() ;
// 				ans_min[j - n + 1][i] = mn.front() ;
// 			}			
// 		}
// 	}
// 	// cout << endl ;
// 	// for ( auto &row : ans_max ) {
// 	// 	for ( auto &a : row ) {
// 	// 		cout << a << ' ' ; 
// 	// 	}
// 	// 	cout << endl ;
// 	// }
// 	// cout << endl ;
// 	// for ( auto &row : ans_max ) {
// 	// 	for ( auto &a : row ) {
// 	// 		cout << a << ' ' ;
// 	// 	}
// 	// 	cout << endl ;
// 	// }
// 	// cal ans 
// 	int ans = 1145141919810 ; 
// 	for ( int i = 0 ; i < a - n + 1 ; i ++ ) {
// 		for ( int j = 0 ; j < b - n + 1  ; j ++ ) {
// 			int max_value = arr[ans_max[i][j]][ans_max_row[ans_max[i][j]][j]] ;
// 			int min_value = arr[ans_min[i][j]][ans_min_row[ans_min[i][j]][j]] ;
// 			ans = min ( ans , max_value - min_value ) ;
// 		}
// 	}

// 	cout << ans ;
// 	return 0 ;
// }
// //questions ：
// /*

// */

 
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
#define ull unsigned int int
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD2 = 998244353 ; 
const int MOD = 1e9 + 7 ; 
const int maxn = 1e9 ; 

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
     


}

// ========================== Idea =============================================
/*

首先是纯暴力的思路 枚举所有的 n * n 的然后搞出来

我当初怎么写出来的 卧槽 我这么牛逼吗

所有的最大值一共有 ( a - n + 1 ) * ( b - n + 1 ) 种搭配

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
	int a , b , n ; cin >> a >> b >> n ; 
	vector<vector<int>> arr( a , vector<int>( b )) ; 
	vector<vector<int>> silidingGridMaxValue ; 
	vector<vector<int>> silidingGridMinValue ; 
	vector<vector<int>> silidingWindowMaxValue ; 
	vector<vector<int>> silidingWindowMinValue ; 

	for ( auto &row : arr ) {
		for ( auto &a : row ) {
			cin >> a ; 
		}
	}

	// 先每一行滑动串口最大 搞出 a 行来
	// 然后对这 a 行竖着 n 滑动窗口最大 
	// 最小同理

	vector<vector<int>> ans_max_row ;
	vector<vector<int>> ans_min_row ;
	for ( int i = 0 ; i < a ; i ++ ) {
		deque<int> mx , mn ;
		ans_max_row.push_back( vector<int>() ) ;
		ans_min_row.push_back( vector<int>() ) ;
		for ( int j = 0 ; j < b ; j ++ ) {
			int l = j - n + 1 ;
			while ( !mx.empty() && arr[i][mx.back()] <= arr[i][j] ) 
				mx.pop_back() ;
			while ( !mn.empty() && arr[i][mn.back()] >= arr[i][j] )
				mn.pop_back() ;

			mx.push_back( j ) ;
			mn.push_back( j ) ;

			if ( l > mx.front() ) 
				mx.pop_front() ;
			if ( l > mn.front() )
				mn.pop_front() ;

			if ( j >= n - 1 ) {
				ans_max_row[i].push_back( mx.front() ) ;
				ans_min_row[i].push_back( mn.front() ) ;
			}
		} 
	}

	vector<vector<int>> ans_max ( a - n + 1 , vector<int> ( b - n + 1 , 0 ) ) ;
	vector<vector<int>> ans_min ( a - n + 1 , vector<int> ( b - n + 1 , 0 ) ) ;
	for ( int i = 0 ; i < b - n + 1 ; i ++ ) {
		deque<int> mx , mn ;
		// enumerate row
		for ( int j = 0 ; j < a ; j ++ ) {
			int l = j - n + 1 ;
			while ( !mx.empty() && arr[mx.back()][ans_max_row[mx.back()][i]] <= arr[j][ans_max_row[j][i]] ) 
				mx.pop_back() ;
			while ( !mn.empty() && arr[mn.back()][ans_min_row[mn.back()][i]] >= arr[j][ans_min_row[j][i]] )
				mn.pop_back() ;

			mx.push_back( j ) ;
			mn.push_back( j ) ;

			if ( l > mx.front() ) 
				mx.pop_front() ;
			if ( l > mn.front() )
				mn.pop_front() ;

			if ( j >= n - 1 ) {
				// cout << j - n + 1 << ' ' << i << endl ;
				ans_max[j - n + 1][i] = mx.front() ;
				ans_min[j - n + 1][i] = mn.front() ;
			}			
		}
	}

	int ans = 1145141919810 ; 
	for ( int i = 0 ; i < a - n + 1 ; i ++ ) {
		for ( int j = 0 ; j < b - n + 1  ; j ++ ) {
			int max_value = arr[ans_max[i][j]][ans_max_row[ans_max[i][j]][j]] ;
			int min_value = arr[ans_min[i][j]][ans_min_row[ans_min[i][j]][j]] ;
			ans = min ( ans , max_value - min_value ) ;
		}
	}

	cout << ans ;

    return 0 ;
}
// ========================== Question =========================================
/*

*/


