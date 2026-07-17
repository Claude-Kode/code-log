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
	int n , m  ;
	cin >> n >> m ;
	vector<vector<int>> pre ( n , vector<int> ( m , 0 ) ) ;
	for ( int i = 0 ; i < n  ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			char temp ; cin >> temp ;
			if ( i == 0 && temp == 'F' ) pre[i][j] = 1 ;
			else if ( temp == 'F' ) pre[i][j] = pre[i -1][j] + 1 ;
			// cout << pre[i][j] << ' ' ;
		}
		// cout << endl ;
	}
	int ans = 0 ; 
	for ( int i = 0 ; i < n ; i ++ ) {
		// left travel  
		stack<int> st1 ;
		vector<int> left ( m , -1 ) ;
		for ( int j = 0 ; j < m ; j ++ ) {
			while ( !st1.empty() && pre[i][j] <= pre[i][st1.top()] ) 
				st1.pop() ;
			if ( !st1.empty() ) left[j] = st1.top() ;
			st1.push( j ) ; 
		}
		// right travel
		stack<int> st2 ;
		vector<int> right ( m , m ) ; 
		for ( int j = m - 1 ; j >= 0 ; j -- ) {
			while ( !st2.empty() && pre[i][j] <= pre[i][st2.top()] )
				st2.pop() ;
			if ( !st2.empty() ) right[j] = st2.top() ; 
			st2.push( j ) ;
		}
		// cal ans
		for ( int j = 0 ; j < m ; j ++ ) 
			ans = max ( ans , pre[i][j] * ( right[j] - left[j] - 1 ) ) ;
	}
	cout << 3 * ans ;
	return 0 ;
}
//questions ：
/*

*/