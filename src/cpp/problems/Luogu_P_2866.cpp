// header file
#include <iostream>
#include <algorithm>
#include <stack>
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
	int n ;
	cin >> n ;
	vector<int> arr ( n ) ;
	stack<int> st ;
	for ( auto &a : arr ) cin >> a ;
	// 维护一个单调递减栈
	int res = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		while ( !st.empty() && st.top() <= arr[i] ) 
			st.pop() ;
		res += st.size() ;
		st.push( arr[i] ) ;
	}
	cout << res ;
	return 0 ;
}
//questions ：
/*

*/