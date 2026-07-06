// header file
#include <iostream>
#include <algorithm>
#include <vector>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n ; cin >> n ;
		vector<int> arr ( n ) ;
		bool even = false , odd = false ;
		for ( auto &a : arr ) {
			cin >> a ;
			a % 2 == 0 ? even = true : odd = true ;
		}
		if ( even && odd ) sort ( arr.begin() , arr.end() ) ;
		for ( auto &a : arr ) cout << a << ' ' ;
		cout << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/