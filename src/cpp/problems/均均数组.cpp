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
	while ( t -- ) {
		int n ;
		cin >> n ;
		vector <int> arr ( n ) ;
		int sum = 0 ;
		for ( auto &a : arr ) { cin >> a ; sum+= a ; }
		if ( sum / n * n == sum ) cout << "Yes" << endl ;
		else cout << "No" << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/