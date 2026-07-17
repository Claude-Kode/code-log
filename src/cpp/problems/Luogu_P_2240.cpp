// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <stack> 
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

// idea
/*

*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	vector <int> elements ( n ) ;
	for ( auto &a : elements ) cin >> a ;
	stack <int> st ;
	st.push( 1145141919810 ) ;
	for ( auto &a : elements ) {
		st.push( min ( a , st.top() ) ) ;
	}
	cout << st.top() << endl ;
	int m ;
	cin >> m ;
	return 0 ;
}
//questions ：
/*

*/