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
		for ( auto &a : arr ) cin >> a ;
		sort ( arr.begin() , arr.end() , greater<int>() ) ;
		int target = arr [0] ;
		int index = 0 ;
		for ( int i = 0 ; i < n - 1 ; i ++ ) {
			arr[i] += i + 1 ;
			if ( target - arr[i] >= 0 && target - arr[i+1] <= 0 ) {
				index = i ;
				break ;
			}
		}
		cout << target + index << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/
