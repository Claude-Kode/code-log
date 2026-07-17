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
	int n ;
	cin >> n ;
	vector<int> arr ( n + 1 , 0 ) ;
	for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ;
	int ans = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) if ( arr[i] > arr[i-1] ) ans += arr[i] - arr[i - 1] ;
	cout << ans << endl ;
	return 0 ;
}
//questions ：
/*

*/