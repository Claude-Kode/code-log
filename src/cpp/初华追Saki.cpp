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
大胆猜测回文数的长度是不变的

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	//
	string str , ans ;
	cin >> str ;
	int n = str.size() ;
	if ( str.size() == 1 ) { cout << 0 << endl ; return 0 ; }
	//
	int l = 0 , r = n - 1 ;
	bool sign1 = true ;
	while ( l < r ) {
//		cout << l << ' ' << r << endl ;
		if ( str[l] == str[r] ) { l ++ ; r -- ; }
		else { sign1 = false ; break ; }
	}
	if ( sign1 ) { cout << 0 << endl ; return 0 ; }
	//
	for ( auto &a : str ) ans += '9' - a + '0' ;
	bool sign = true ;
	for ( auto &a : ans ) {
		if ( sign && a == '0' ) { continue ; }
		if ( sign ) { sign = false ; cout << a ; continue ; }
		if ( !sign ) cout << a ;
	}
	return 0 ;
}
//questions ：
/*
去掉前导 0 太笨重了
*/