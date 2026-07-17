// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
int n , x ;
struct jump_distance {
	int first ;
	int second ;
};
int cnt = 0 , current_distance = 0 ;
vector < jump_distance > jump_distance_vector ;
// functions declarations

void sign ( int step , int a ) {
	if ( a == 1 ) { jump_distance_vector [step].first = 0 ; }
	if ( a == 2 ) { jump_distance_vector [step].second = 0 ; }
}

void DFS  ( int step , int a ) {
	// return judge
	if ( cnt ) return ;
	if ( step == n + 1 ) { sign ( step - 1 , a ) ; return ; }
	if ( current_distance == x ) {	sign ( step - 1 , a ) ; cnt ++ ; return ; }
	if ( current_distance > x ) { sign ( step - 1 , a ) ; return ; }
	// recursion ; mark 0 means cant been DFS 
	if ( jump_distance_vector [step].first ) {
		current_distance += jump_distance_vector [step].first ;
		DFS ( step + 1 , 1 ) ;
		DFS ( step + 1 , 2 ) ;
		current_distance -= jump_distance_vector [step].first ;
		
	}
	if ( jump_distance_vector [step].second ) {
		current_distance += jump_distance_vector [step].second ;
		DFS ( step + 1 , 1 ) ;
		DFS ( step + 1 , 2 ) ;
		current_distance -= jump_distance_vector [step].second ;
	}
}

//idea
/*
distance range from 1 to 100
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	cin >> n >> x ;
	jump_distance_vector.resize( n ) ;
	for ( auto &a : jump_distance_vector ) {
		cin >> a.first >> a.second ;
	}
	DFS ( 1 , 1 ) ;
	DFS ( 1 , 2 ) ;
	cnt ? cout << "Yes" << endl : cout << "No" << endl ;
	return 0 ;
}
//questions ： 
/*

*/
