// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
消耗体力等于两堆之和，所以排序之s后把最大的放到最后面合并是最好的
*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	priority_queue<int , vector<int> , greater<>> pq ;
	vector<int> arr ( n ) ;
	for ( auto &a : arr ) {
		cin >> a ;
		pq.push( a ) ;
	}
	// use the smallest heap 
	int res = 0 ;
	while ( pq.size() >= 2 ) {
		int x = pq.top() ; pq.pop() ;
		int y = pq.top() ; pq.pop() ;
		res += x + y ;
		pq.push( x + y ) ;
	}
	cout << res << endl ;
	return 0 ;
}
//questions ：
/*

*/