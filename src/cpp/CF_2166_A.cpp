// header file
#include <iostream>
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

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n ;
		cin >> n ;
		string s ;
		cin >> s ;
		int cnt  = 0 ;
		for ( auto &a : s ) if ( a != s.back() ) cnt ++ ;
		cout << cnt << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/