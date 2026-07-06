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
bool dp[10005] ;
bool xdp[10005] ;
// functions declarations

//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , x ;
	cin >> n >> x ;
	dp[0] = 1 ;
	while ( n -- ) {
		int a , b ;
		cin >> a >> b ;
		for ( int i = 0 ; i < x ; i ++ ) {
			if ( dp[i] ) {
				if ( i + a <= x ) xdp[ i + a ] = 1 ;
				if ( i + b <= x ) xdp[ i + b ] = 1 ;
			}
		}
		if ( xdp[x] && n == 1 ) xdp[x] = 0 ;
		for ( int i = 0 ; i <= x ; i ++ ) { dp[i] = xdp[i] ; xdp[i] = 0 ;}
	}
	dp[x] ? cout << "Yes" << endl : cout << "No" << endl ;
	return 0 ;
}
//questions ：
/*

*/
