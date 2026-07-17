// header file
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
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
	unordered_map < int , bool > hashmap ( n ) ;
	unordered_set < int > answer ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int temp ; cin >> temp ;
		hashmap[temp] = true ;
	}
	int m ;
	cin >> m ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int temp ; cin >> temp ;
		for ( auto &a : hashmap ) {
			if ( hashmap.find( temp - a.first ) != hashmap.end() ) {
				answer.insert ( a.first ) ;
				answer.insert ( temp - a.first) ;
			}
		}
	}
	cout << answer.size() << endl ;
	return 0 ;
} 
//questions ：
/*
 
*/
