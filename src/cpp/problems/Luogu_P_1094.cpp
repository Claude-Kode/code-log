// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
符号问题 ， arr[r] + arr[l] <= w 这里是有等于号的
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int w , n ;
	cin >> w >> n ;
	vector<int> arr ;
	int ans = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int temp ; cin >> temp ;
		if ( temp >= w )  ans ++ ;
		else arr.push_back( temp ) ;
	}
	// for ( auto &a : arr ) cout << a << ' ' ;
	// cout << ans << endl ;
	sort ( arr.begin() , arr.end() ) ;
	int l = 0 , r = arr.size() - 1 ;
	// for ( auto &a : arr ) cout << a << ' ' ;
	// cout << endl ;
	while ( l <= r ) {
		// cout << l + 1 << ' ' << r + 1 << endl ;
		if ( l == r ) { ans ++ ; break ; }
		if ( arr[r] + arr[l] <= w ) { ans ++ ; l ++ ; r -- ; }
		else { ans ++ ; r -- ; }
	}
	cout << ans << endl ;
	return 0 ;
}
//questions ：
/*

*/