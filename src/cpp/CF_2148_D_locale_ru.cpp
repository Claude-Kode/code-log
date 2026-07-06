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
如果一个奇数没有 return 0 
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t;
	 while ( t -- ) {
		int n ; cin >> n ;
		vector<int> odds ; 

		int ans = 0 ;
		bool sign = true ;
		for ( int i = 0 ; i < n ; i ++ ) {
			int temp ; cin >> temp ;
			if ( ( temp & 1 ) == 1 ) { sign = false ; odds.push_back( temp ) ; } 
			else ans += temp ;
		}
		//sj
		if ( sign ) { cout << 0 << endl ; continue ; }

		sort ( odds.begin() , odds.end() ) ;
		int len = odds.size() ; 
		for ( int i = len / 2 ; i < len ; i ++ ) {
			ans += odds[i] ;
		} 
		cout << ans << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/