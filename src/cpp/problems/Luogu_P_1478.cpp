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
struct infor {
	int height ;
	int consume ;
} ;
// functions declarations

//idea
/*

*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , s ;
	cin >> n >> s ;
	int a , b ;
	cin >> a >> b ;

	vector<infor> arr  ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int height , consume ;
		cin >> height >> consume ;
		if ( height <= ( a + b ) ) {
			arr.push_back( { height , consume } ) ;
		}
	}

	sort ( arr.begin() , arr.end() , [] ( infor a , infor b ) {
		return a.consume < b.consume ;
	} ) ;

	// for ( auto &a : arr ) cout << a.height << ' ' << a.consume << endl ;
	int ans = 0 ;
	int index = 0 ;
	while ( s ) {
		if ( s >= arr[index].consume ) {
			ans ++ ; 
			s -= arr[index].consume ;
		} else break ;
		index ++ ;
	}

	cout << ans << endl ;
	return 0 ;
}
//questions ：
/*

*/