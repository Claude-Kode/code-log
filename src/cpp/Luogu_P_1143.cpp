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
	string num ; 
	cin >> num ;
	int base ; 
	cin >> base ;
	int len = num.size() ;
	int value = 0 ;
	int temp = 1 ;
	for ( int i = len - 1 ; i >= 0 ; i -- ) {
		if ( num[i] >= '0' && num[i] <= '9' ) {
			value += ( num[i] - '0' ) * temp ;
		}
		else {
			value += ( num[i] - 'A' + 10 ) * temp ;
		}
		temp *= n ;
	} 
	string nums ;
	while ( value ) {
		int nnum = value % base ;
		if ( nnum >= 0 && nnum <= 9 ) nums.push_back( nnum + '0' ) ;
		else nums.push_back( nnum + 'A' - 10 ) ;
		value /= base ;
	}
	for ( auto it = nums.rbegin() ; it != nums.rend() ; it ++ ) {
		cout << *it ;
	}
	return 0 ;
}
//questions ： 
/*

*/