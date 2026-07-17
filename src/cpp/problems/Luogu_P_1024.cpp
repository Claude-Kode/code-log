// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
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
signed main () {
	cout << fixed << setprecision ( 2 ) ;
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	double a , b , c , d ;
	cin >> a >> b >> c >> d ;
	for ( double i = -100.00 ; i <= 100.00 ; i += 0.01 )
		if ( abs ( a * i * i * i + b * i * i + c * i + d ) < 1e-6 ) cout << i << ' ' ;
	return 0 ;
}
//questions ：
/*

*/