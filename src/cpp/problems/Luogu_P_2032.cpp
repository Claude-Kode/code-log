// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque> 
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
	int n , k ;
	cin >> n >> k ;
	vector<int> arr ( n ) ;
	for ( auto &a : arr ) cin >> a ;
	deque<int> dq ;
	for ( int i = 0 ; i < n ; i ++ ) {
		while ( !dq.empty() && arr[i] >= arr[dq.back()] ) 
			dq.pop_back() ;
		dq.push_back( i ) ;
		int l = i - k + 1 ;
		if ( l >= 0 && l > dq.front() ) dq.pop_front() ;
		if ( l >= 0 ) cout << arr[dq.front()] << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/