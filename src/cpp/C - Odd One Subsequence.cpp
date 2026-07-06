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
	vector <int> arr ( n , 0 ) ; 
	for ( auto &a : arr ) cin >> a ;
	sort ( arr.begin() , arr.end() ) ; 
	bool sign = false ; 
	int result = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( arr[i] >= n ) {
			sign = true ;
			result = i ;
			sign = true ;
		} else if ( sign && arr[i] > n ) {
			result = i ;
			break ;
		}
	}
	result -= 1 ;
	result >= 0 ? cout << result << endl : cout << 0 << endl ;
	return 0 ;
}
//questions ：
/*

*/
