// header file
#include <iostream>
#include <vector>
#include <unordered_map>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
cnt_a > a ; res += gap
cnt_a < a ; res += cnt_a
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int tt ; cin >> tt ;
	while ( tt -- ) {
		int n ; cin >> n ;
		unordered_map<int , int> mp ;
		vector<int> arr ( n ) ;
		for ( auto &a : arr ) { cin >> a ; mp[a] ++ ; }
		int res = 0 ;
		for ( auto [val , cnt] : mp ) if ( cnt != val ) cnt > val ? res += cnt - val : res += cnt ;
		cout << res << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/