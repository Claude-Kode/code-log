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
bool check ( vector<int> arr , int test , int n , int m ) {
	int total_need = m * test ;
	for ( int i = 0 ; i < n ; i ++ ) {
		arr[i] >= test ? total_need -= test : total_need -= arr[i] ;
	}
	if ( total_need <= 0 ) return true ; //  l = mid + 1 
	else return false ; // r = mid - 1 
}
//idea
/*
binary search method 
enumerate the quantity of palettes
the total_contrubution is m * quantity
if one > quantity , total_need -= one-value
else total-need is one's value
if quantity < 0 , break and make l bigger
if quantity = 0 , try to make l bigger
if quantity < 0 , try to make r smaller
that's my approach
*/
// codes
signed main() {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , m , k ;
	cin >> n >> m >> k ;
	vector <int> arr ( n ) ;
	int total = 0 ;
	int max_value = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> arr [i] ;
		total += arr[i] ;
		if ( max_value < arr[i] ) max_value = arr[i] ; 
	}
	sort ( arr.begin() , arr.end() , greater<int>() ) ;
	// special judge
	if ( m == 1 || n == 1 ) {
		cout << max_value * k << endl ;
		return 0 ;
	}
	if ( n < m ) {
		cout << 0 << endl ; 
		return 0 ;
	}
	
	// normal judge 
	int l = -1 , r = total / m + 1 ;
	int answer = 0 ;
	while ( l <= r ) {
		int mid = ( l + r ) >> 1 ;
		if ( check ( arr , mid , n , m ) ) {
			l = mid + 1 ;
			answer = mid ;
		} else {
			r = mid - 1 ;
		}
	}
	cout << answer * k << endl ;
	return 0 ;
}
//questions ：
/*

*/
