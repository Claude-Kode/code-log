// header file
#include <iostream>
#include <algorithm>
#include <vector>
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
	vector<int> arr ( 3 ) ;
	for ( auto &a : arr ) cin >> a ;
	sort ( arr.begin() , arr.end() ) ;
	if ( arr.back() - arr.front() > 10 ) cout << "check again" ;
	else cout << "final " << arr[1] ;
	return 0 ;
}
//questions ：
/*

*/