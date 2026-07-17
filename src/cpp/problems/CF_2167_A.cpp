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
	int t ;
	cin >> t ;
	while ( t --  ) {
		vector <int> arr ( 4 ) ;
		for ( int &a : arr ) cin >> a ;
		int temp = arr.back() ; 
		bool sign = true ;
		for ( int &a : arr ) {
			if ( a != temp ) {
				sign = false ;
				break ;
			}
		}
		sign ? cout << "YES" << endl : cout << "NO" << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/