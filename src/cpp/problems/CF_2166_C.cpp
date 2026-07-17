// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 
#include <tuple>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
好像也可以用哈希表存每个元素的
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n ; cin >> n ;
		if ( n == 1 ) { cout << 0 << endl ; continue ; }
		// <value , curp , prep , nxtp 
		vector<int> arr ( n + 1 ) ;
		vector<int> index ( n + 1 , 0 ) , pre_index ( n + 1 , 0 ) , nxt_index ( n + 1 , 0 ) ;  
		for ( int i = 1 ; i <= n ; i ++ ) {
			cin >> arr[i] ;
			index[i] = i ; pre_index[i] = i - 1 ; nxt_index[i] = i + 1 ;
		}
		pre_index[1] = n ; nxt_index[n] = 1 ;
		sort ( index.begin() + 1 , index.end() , [&]( int a , int b ) {
			return arr[a] < arr[b] ;
		}) ;
		int ans = 0 ;
		for ( int i = 1 ; i < n ; i ++ ) {
			int cur = index[i] , pre = pre_index[cur] , nxt = nxt_index[cur] ;
			ans += min ( arr[pre] , arr[nxt] ) ;
			// 把cur的pre的nxt改成 cur的nxt
			// 把cur的nxt的pre改成 cur的pre
			pre_index[nxt] = pre ;
			nxt_index[pre] = nxt ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/