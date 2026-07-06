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
int n , m ;
// functions declarations
bool check ( int test , vector <int> arr ) {
	int cnt = 1 , sum = 0 ;
	for ( auto &a : arr ) {
		sum += a ;
		if ( a > test ) return true ;
//		if ( sum <= test && a == arr.back() ) { cnt ++ ; break ; }
		if ( sum > test ) { sum = a ; cnt ++ ; } 
	}
	// 某一段的和大于
	return cnt > m ; // cnt is too big means the test is too small , l = mid + 1 
}
//idea
/*
gs
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	cin >> n >> m ;
	vector <int> arr ( n ) ;
	int sum = 0 ;
	for ( auto &a : arr ) { cin >> a ; sum += a ; }
	// bs
	int l = 1 , r = sum , answer = r ;
	while ( l <= r ) {
//		cout << l << ' ' << r << endl ;
		int mid = ( l + r ) / 2 ;
		if ( check ( mid , arr ) ) { l = mid + 1 ; }
		else { r = mid - 1 ; answer = mid ; }
	}
	cout << answer << endl ;
	return 0 ;
}
//questions ：
/*

*/