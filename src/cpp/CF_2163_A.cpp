// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <unordered_map>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
排序之后递增r
除了头和尾两个数字剩下所有的数字都应该相同
换句话说相同的数字个数必须是 n - 2 
排序后保证k操作的数字全部相等就可以了
就是 a[i] == ar[i + 1] && i & 1 == 0 && i != n - 1 ;
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n ;
		cin >> n ;
		vector<int> arr ( n ) ; 
		for ( int i = 0 ; i < n ; i ++ ) {
			cin >> arr[i] ;
		}
		sort ( arr.begin() , arr.end() ) ;
		bool sign = true ;
		for ( int i = 0 ; i < n - 1 ; i ++ ) {
			if ( ( i & 1 ) == 1 && arr[i] != arr[i + 1] ) { sign = false ; break ; }
		}
		sign ? cout << "YES" << endl : cout << "NO" << endl ;
	}

	return 0 ;
}
//questions ：
/*

*/