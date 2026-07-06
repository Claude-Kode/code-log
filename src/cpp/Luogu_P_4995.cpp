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
利用双指针进行的算数，真的挺好用的
*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	vector<int> arr ( n + 1 , 0 ) ;
	for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ;
	sort ( arr.begin() , arr.end() ) ;
	int ans = 0 ;
	int l = 0 , r = n ;
	bool sign_move_l = true ;
	while ( l < r ) {
		ans += ( arr[r] - arr[l] ) * ( arr[r] - arr[l] ) ;
		if ( sign_move_l ) { l ++ ; sign_move_l = false ; }
		else { r -- ; sign_move_l = true ; } 
	}
	cout << ans << endl ;
	return 0 ;
}
//questions ：
/*

*/