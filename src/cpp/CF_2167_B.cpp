// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
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
		string a , b ;
		cin >> a >> b ;
		sort ( a.begin() , a.end() ) ;
		sort ( b.begin() , b.end() ) ;
		a == b ? cout << "YES" << endl : cout << "NO" << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/