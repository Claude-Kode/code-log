// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
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
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n ;
		cin >> n ;
		vector<int> arr ( n ) ;
		for ( auto &a : arr ) cin >> a ;
		sort ( arr.begin() , arr.end() ) ;
		stack<int> st ;
		for ( auto &a : arr ) {
			if ( st.empty() ) st.push( a ) ;
			else if ( st.top() < a ) st.push( a ) ;
		}
		cout << st.size() << endl ;
	}
	return 0 ; 
}
//questions ：
/*

*/