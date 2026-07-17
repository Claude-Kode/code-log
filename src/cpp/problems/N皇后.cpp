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
int count1 = 0 ; 
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
		count1 ++ ;
		if ( count1 > 3 ) return ;
		for ( auto &a : answer ) {
			cout << a.y << ' ' ;
		}
		cout << endl ;
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
	DFS ( 1 ) ;
	cout << count1 << endl ;
	return 0 ;
}
//questions ：
/*

*/
