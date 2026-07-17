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
	int n , a , b ;
	cin >> n >> a >> b ;
	vector <int> arr ( n + 1 ) ;
	int res = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> arr[i] ;
		res += min ( ( arr[i] - arr[i-1] ) * a , b ) ;
	}
	cout << res << endl ;
	return 0 ;
}
//questions ：
/*

*/