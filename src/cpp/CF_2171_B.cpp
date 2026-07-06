// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
只有最后一个和第一个要特殊处理
只要是中间的直接全部填 0 
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ; cin >> t ;
	while ( t -- ) {
		int n ; cin >> n ;
		vector<int> arr ( n ) ;
		int diff = 0 ; 
		for ( int i = 0 ; i < n ; i ++ ) {
			int temp ; cin >> temp ;
			if ( i != 0 && i != n - 1 && temp == -1 ) 
				arr[i] = 0 ;
			else arr[i] = temp ;
		}
		// if ( n == 1 ) { 
		// 	if ( arr[0] == -1 ) {
		// 		cout << 0 << endl << 0 << endl ;
		// 	}
		// 	else {
		// 		cout << arr[0] << endl << arr[0] << endl ;
		// 	}
		// 	continue ;
		// }	

		for ( int i = 0 ; i < n - 1 ; i ++ ) {
			diff += arr[i + 1] - arr[i] ; 
		}

		int& front = arr.front() ;
		int& back = arr.back() ; 
		if ( front == -1 && back != -1 ) {
			front = diff - 1 ; diff = 0 ;
		} else if ( front != -1 && back == -1 ) {
			back = -1 - diff ; diff = 0 ;
		} else if ( front == -1 && back == -1 ) {
			front = 0 ; back = -1 * diff ; diff = 0 ;
		}
		// op
		cout << abs(diff) << endl ;
		for ( auto &a : arr ) cout << a << ' ' ; 
		cout << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/