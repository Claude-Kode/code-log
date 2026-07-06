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
	deque<int> dq_largest , dq_smallest ;
	vector<int> ans_largest , ans_smallest ;
	for ( int i = 0 ; i < n ; i ++ ) {
		// 入队 + 维护
		while ( !dq_smallest.empty() && arr[dq_smallest.back()] >= arr[i] ) 
			dq_smallest.pop_back() ;
		while ( !dq_largest.empty() && arr[dq_largest.back()] <= arr[i] ) 
			dq_largest.pop_back() ;
			
		dq_largest.push_back( i ) ;
		dq_smallest.push_back( i ) ;
		int l = i - k + 1 ;
		if ( l >= 0 && l > dq_largest.front() ) dq_largest.pop_front() ; 
		if ( l >= 0 && l > dq_smallest.front() ) dq_smallest.pop_front() ;
		if ( l >= 0 ) ans_largest.push_back( arr[dq_largest.front()] ) ;
		if ( l >= 0 ) ans_smallest.push_back( arr[dq_smallest.front()] ) ;
	}
	for ( auto &a : ans_smallest ) cout << a << ' ' ;
	cout << endl ;
	for ( auto &a : ans_largest ) cout << a << ' ' ;
	return 0 ;
}
//questions ：
/*

*/