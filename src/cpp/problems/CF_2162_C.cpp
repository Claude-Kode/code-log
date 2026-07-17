// header file
#include <iostream>
#include <algorithm>
#include <vector>
// #include <unordered_map>
// #include <stack>
// #include <map>
// #include <queue>
// #include <deque>
// macro definition
#define endl '\n'
#define int long long
#define gap ' ' 
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

// idea
/*

*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int a , b ;
		cin >> a >> b ;
		// bits_a的有效二进制数字的位数
		int bits_a = 32 - __builtin_clz( a ) , bits_b = 32 - __builtin_clz( b ) ;
		if ( bits_a < bits_b ) { cout << -1 << endl ; continue ; }
		else if ( a == b ) { cout << 0 << endl ; continue ; }
		else {
			vector<int> val ;
			for ( int i = 0 ; i < bits_a ; i ++ ) {
				int bit_a = ( a >> i ) & 1 ;
				if ( bit_a == 0 ) val.push_back( 1 << i ) ; 
			}
			for ( int i = 0 ; i < bits_a ; i ++ ) {
				int bit_b = ( b >> i ) & 1 ;
				if ( bit_b == 0 ) val.push_back( 1 << i ) ;
			}
			cout << val.size() << endl ; 
			for ( auto &a : val ) cout << a << ' ' ;
			cout << endl ;
		}
	}
	return 0 ;
}
//questions ：
/*

*/