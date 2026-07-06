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

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	int res = 0 ; 
	while ( n -- ) {
		int a , b ;
		cin >> a >> b ;
		if ( !res ) res += b - a + 1 ;
		else res *= b - a + 1 ;
	}
	if ( res <= 1e5 ) cout << "NO TLE" << endl ;
	else if ( res > 1e5 && res <= 1e7 ) cout << "POSSIBLE" << endl ;
	else cout << "TLE" << endl ;
	return 0 ;
}
//questions ：
/*

*/