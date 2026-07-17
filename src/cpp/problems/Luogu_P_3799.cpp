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
	vector <int> arr ( n ) ;
	for ( auto &a : arr ) cin >> a ;
	sort ( arr.begin() , arr.end() ) ;
	long long cnt = 0 ;
	for ( int i = 0 ; i < n - 2 ; i ++ ) {
		for ( int j = i + 1 ; j < n - 1 ; j ++ ) {
			for ( int k = j + 1 ; k < n ; k ++ ) {
//				cout << i << ' ' << j << ' ' << k << endl ;
				if ( arr[i] == arr[j] == arr[k] ) cnt ++ ;
				cnt %= 1000000007 ;
			}
		}
	}
	cout << cnt << endl ;
	return 0 ;
}
//questions ：
/*

*/