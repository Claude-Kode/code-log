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
	int n , m ;
	cin >> n >> m ;
	vector <int> arr ( n ) ;
	for ( auto &a : arr ) cin >> a ;
	vector <int> query ( m ) ;
	for ( auto &a : query ){ 
		cin >> a ;
		int l = 0 , r = n - 1 ;
		int answer = -1 ;
		while ( l <= r ) {
			int mid = ( l + r ) / 2 ;
			if ( arr[mid] >= a ) { r = mid - 1 ; answer = mid ; }
			else l = mid + 1 ;
		}
		if ( arr[answer] == a ) cout << answer + 1 << ' ' ;
		else cout << -1 << ' ' ;
	}
	
	return 0 ;
}
//questions ：
/*

*/