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
int m , n ;
int presum = 0 , answer = 0 ;
bool canbeUsed[11] ;
// functions declarations

void bool_set ( int pos ) {
	for ( int i = 0 ; i < 11 ; i ++ ) {
		if ( i <= pos ) canbeUsed[i] = true ; 
		else canbeUsed[i] = false ;
	} 
}

void DFS ( int step , int sum , int pre ) {
	if  ( step == n + 1 ) {
		answer ++ ;
		return ;
	}
	else {
		for ( int i = pre ; i <= m ; i ++ ) {
			if ( canbeUsed[i] ) {
				bool_set ( m - presum - i ) ;
				DFS ( step + 1 , presum + i , i ) ;
				bool_set ( m - presum ) ;
			}
		}
		return ;
	}
}

//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		cin >> m >> n ;
		answer = 0 ;
		bool_set ( m ) ;
		DFS ( 1 , 0 , 0 ) ;
		cout << answer << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/
