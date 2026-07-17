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
		int n ;
		cin >> n ;
		if ( n % 2 == 1 ) cout << 0 << endl ;
		else cout << n / 4 + 1 << endl ; 
	}
	return 0 ;
}
//questions ：
/*

*/