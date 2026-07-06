// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip> 
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
int finalDistance , n , m ; 
// 
// functions declarations
bool check ( int test , vector <int> diffDistance ) {
	int countRemoval = 0 ;
	for ( int i = 0 ; i < n + 1 ; i ++ ) {
		if ( test > diffDistance[i] ) {
			countRemoval ++ ;
			if ( i < n ) diffDistance[i+1] += diffDistance[i] ;
		}
	}
	return countRemoval <= m ; // less than m proved that the min distance is to big , r should be smaller
}
//idea
/*
 n or m can be 0
*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	cin >> finalDistance >> n >> m ;
	if ( n == 0 ) { cout << finalDistance << endl ; return 0 ; }
	vector <int> distance ( n + 2 ) ;
	distance[0] = 0 ; distance[n+1] = finalDistance ;
	for ( int i = 1 ; i <= n ; i ++ ) cin >> distance[i] ;
	vector <int> diffDistance ( n + 1 ) ;
	int minDistance = __LONG_LONG_MAX__ ;
	for ( int i = 0 ; i <= n ; i ++ ) {
		diffDistance[i] = distance[i+1] - distance[i] ;
		if ( minDistance > diffDistance[i] ) minDistance = diffDistance[i] ;
	}
	// sj
	if ( m == 0 ) { cout << minDistance << endl ; return 0 ; }
	int l = 0 , r = finalDistance , answer = 0 ;
	while ( l <= r ) {
		int mid = ( l + r ) / 2 ;
		if ( check( mid , diffDistance ) ) { l = mid + 1 ; answer = mid ; }
		else { r = mid - 1 ; }
	}
	cout << answer << endl ;
	return 0 ;
}
//questions ：
/* 

*/