// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
bool st[110000] ;
vector < int > prime ;
// functions declarations
void eulerSieve () {
	for ( int i = 2 ; i < 110000 ; i ++ ) {
		if ( !st[i] ) prime.push_back( i ) ;
		for ( int p : prime ) {
			if ( i * p  > 110000 ) break ;
			st[ i * p ] = true ;
			if ( i % p == 0 ) break ; 
		}
	}
}

void BFS ( int temp ) {
	queue < int > myqueue ;
	for ( int i = 1 ; i <= 9 ; i ++ ) {
		myqueue.push ( temp * 10 + i ) ;
	}
	while ( 1 ) {
		for ( int i = 1 ; i <= 9 ; i ++ ) {
			int val = myqueue.front() ;
			myqueue.pop() ;
			if ( !st[val] ) { cout << val << endl ; return ; }
			for ( int j = 1 ; j <= 9 ; j ++ ) myqueue.push ( val * 10 + j ) ;
		}
	}
} 
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	eulerSieve () ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int temp ;
		cin >> temp ;
		BFS ( temp ) ; 
	}
	return 0 ;
}
//questions ：
/*

*/
