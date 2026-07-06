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
枚举高度，然后计算每次能获得的木材
如果木材恰好等于缩小
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , m ;
	cin >> n >> m ;
	int maxHeight = 0 ;
	vector <int> treeHeight ( n ) ;
	for ( auto &a : treeHeight ) {cin >> a ; if ( maxHeight < a) maxHeight = a ; }
	// target is m  
	auto check = [&] ( int test ) -> bool { 
		int totalHeight = 0 ;

		for ( auto &a : treeHeight ) 
			if ( test < a ) totalHeight += a - test ;

		if ( totalHeight >=  m ) return true ;
		else return false ;
	} ;
	//
	int l = 0 , r = maxHeight , answer = -1 ;
	while ( l <= r ) {
//		cout << l << ' ' << r << endl ;
		int mid = ( l + r ) / 2 ;
		if ( check ( mid ) ) { l = mid + 1 ; answer = mid ; }
		else r = mid - 1 ;
	} 
	cout << answer ;
	// if answer == -1 , means the right boundary never been updating 
	return 0 ;
}
//questions ：
/*

*/