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
struct coordinate {
	int x ;
	int y ;
};
int n ;
vector < struct coordinate > answer ;
char chessborad [10] [10] = { "." } ;
// functions declarations

bool judge ( int x , int y ) {
	if ( answer.empty() ) return true ;
	for ( auto it = answer.begin() ; it != answer.end() ; it ++ ) {
		if ( it -> x == x ) return false ;
		if ( it -> y == y ) return false ;
		if ( abs ( y - it -> y ) == abs ( x - it -> x ) ) return false ;
	}
	return true ;
}

void chessborad_intialize () { 
	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = 1 ; j <= n ; j ++ ) {
			chessborad [i] [j] = '.' ;
		}
	}
}

void chessborad_print () {
	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = 1 ; j <= n ; j ++ ) {
			cout << chessborad [i] [j]  ;
		}
		cout << endl ;
	}
	cout << endl ;
}

void DFS ( int step ) {
	if ( step == n + 1 ) {
		chessborad_intialize() ;
		for ( auto &a : answer ) {
			chessborad [a.x] [a.y] = 'Q' ;
		}
		chessborad_print() ;
	} else {
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( judge ( step , i ) ) {
				answer.push_back( { step , i } ) ;
				DFS ( step + 1 ) ;
				answer.pop_back() ;
			}
		}
	}
}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	cin >> n ;
	if ( n == 1 ) {
		cout << 'Q' << endl ;
		return 0 ;
	}
	DFS ( 1 ) ;
	return 0 ;
}
//questions ：
/*

*/
