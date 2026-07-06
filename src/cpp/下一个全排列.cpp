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
	if ( n > 5 ) {
		for ( int i = 1 ; i <= n - 5 ; i ++ ) {
			
		}
	}
	vector <int> arr ( 5 , 0 ) ;
	for ( int i = 0 ; i < 5 ; i ++ ) {
		arr[i] = ( n - 4 + i ) ; 
	}
	for ( auto &a : arr ) {
		cout << a << ' ' ;
	}
	// sort from n - 5 + 1 to n because 5! = 120 seriously > m
	// the other part output in increasing order
	// to keep a array with 5 elements value form n - 5 + 1 to n
	// because of the lex order , we can calculate the next number by the value of m
	return 0 ;
}
//questions ：
/*

*/
