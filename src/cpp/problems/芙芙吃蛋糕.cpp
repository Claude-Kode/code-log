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
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
struct infor {
	int index ;
	char c ;
} ;
// functions declarations

//idea
/*
每个右括号找相邻的最近的左括号
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	string str ;
	cin >> str ;
	int ans  = 0 ;
//	unordered_map <char , char> mp = { ')' , '(' } ;
	vector <infor> st ;
	for ( int i = 0 ; i < n ; i ++ ) {
		// 1
		if ( str[i] == '(' ) st.push_back( { i , '(' }) ;
		// 2
		else if ( str[i] == ')' ) { // bug
			if ( !st.empty() && st.back().c == '(' ) {
				ans = max ( ans , i - st.back().index + 1 ) ;
			}
			st.push_back( { i , ')' } ) ;
		}	
	}
	cout << ans << endl ;
	return 0 ;
}
//questions ：
/*

*/