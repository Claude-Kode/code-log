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
vector <int> arr ;
// functions declarations
vector <int> turnTobinary ( int n ) {
	vector <int> arr ;
	while ( n ) {
		arr.push_back( n % 2 ) ;
		n /= 2 ;
	}
	if ( !n ) arr.push_back( 0 ) ;
	return arr ;
}

int fast_power ( int n , int k ) {
	int cnt = 0 ; int result = 1 ;
	vector <int> arr ( turnTobinary ( k ) ) ;
	for ( auto &a : arr ) {
		if ( a ) result *= n ^ cnt ;
		cnt ++ ;
	}
	return result ;
}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , k ;
	cin >> n >> k ;
	cout << fast_power ( n , k ) ; 
	return 0 ;
}
//questions ：
/*

*/
