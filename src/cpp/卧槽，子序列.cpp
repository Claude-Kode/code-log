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
bool check ( vector <int> arr , int test , int n , int m ) {
	int odd = 0 , even = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( ( ( odd + even ) & 1 ) == 0 ) {
			if ( arr[i] >= test ) odd ++ ;
		} else {
			even ++ ;
		}
		if ( ( odd + even ) >= m && odd >= ( m + 1 ) / 2 ) return true ;
	}
	
	odd = 0 , even = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( ( ( odd + even ) & 1 ) == 1 ) {
			if ( arr[i] >= test ) even ++ ;
		} else {
			odd ++ ;
		}
		if ( ( odd + even ) >= m && even >= m / 2 ) return true ;
	}
	
	return false ;
}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , m ; 
	cin >> n >> m ;
	vector <int> arr ( n , 0 ) ;
	for ( auto &a : arr ) {
		cin >> a ;
	}
	auto it_min = min_element ( arr.begin() , arr.end() ) ;
	auto is_max = max_element ( arr.begin() , arr.end() ) ;
	int min_value = *it_min ;
	int max_value = *is_max ;
	int l = min_value , r = max_value , answer = 0 ;
	while ( l <= r ) {
		int mid = ( l + r ) >> 1 ;
		if ( check ( arr , mid , n , m ) ) {
			l = mid + 1 ;
			answer = mid ;
		} else {
			r = mid - 1 ;
		}
	}
	cout << answer << endl ;
	return 0 ;
}
//questions ：
/*

*/
