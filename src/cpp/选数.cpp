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
int n , k ;
int answer = 0 , sum = 0 ;
int arr[20] ;
// functions declarations

bool prime_judge ( int x ) {
	if ( x <= 1 ) return false ; 
	for ( int i = 2 ; i <= sqrt( x ) ; i ++ ) {
		if ( x % i == 0 ) return false ;
	}
	return true ;
}

void DFS ( int step , int sum , int pre ) {
	if ( step == k + 1 ) {
		if( prime_judge ( sum ) ) answer++  ;
		return ;
	} else {
		for ( int i = pre ; i < n ; i ++ ) {
			DFS ( step + 1 , sum + arr[i] , i + 1 ) ;
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
	
	cin >> n >> k ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> arr[i] ;
	}
//	sort ( arr , arr + n ) ;
	DFS ( 1 , 0 , 0 ) ;
	cout << answer << endl ;
	return 0 ;
}
//questions ：
/*

*/
