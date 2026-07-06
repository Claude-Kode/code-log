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
int count1 = 0 ;
bool st[100110];
vector <int> prime ;
// functions declarations

void eulerSieve () {
	for ( int i = 2 ; i < 100100 ; i ++ ) {
		if ( !st[i] ) prime.push_back( i ) ; 
		for ( int p : prime ) {
			if ( ( i * p ) > 10010 ) break ;
			st[ i * p ] = true ;
			if ( i % p == 0 ) break ; 
		}
	}
}

void solve ( int x ) {
	while ( 1 ) {
		x *= 10 ;
		for ( int i = 1 ; i <= 9 ; i ++ ) {
			if ( st[ x + i ] ) continue ;
			else { cout << x + i << endl ; return ; }
		}
		x += 1 ;
	}

}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	eulerSieve() ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int temp ;
		cin >> temp ;
		solve( temp ) ;
	}
	return 0 ;
}
//questions ：
/*

*/
