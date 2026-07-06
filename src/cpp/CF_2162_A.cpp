// header file
#include <iostream>
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
		int n = 0 , mx = 0 ;
		cin >> n ;
		for ( int i = 0 ; i < n ; i ++ ) {
			int temp = 0 ; cin >> temp ;
			mx = max ( mx , temp ) ;
		}
		cout << mx << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/