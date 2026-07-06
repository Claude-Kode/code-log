// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <ranges>
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
	int n , c ;
	cin >> n >> c; 
	vector<int> arr ( n ) ;
	unordered_map <int , int> mp ;
	for ( auto &a : arr ) {
		cin >> a ;
		mp[a + c] ++ ;
	}
	int cnt = 0 ;
	for ( auto &a : arr ) if ( mp[a] ) cnt += mp[a] ; 
	cout << cnt ;
	return 0 ;
}
//questions ：
/*

*/