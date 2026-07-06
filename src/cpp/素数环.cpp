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
int n ;
bool nums [21] ;
bool notprime [114] ;
vector <int> prime ;
map <int , int> mymap  ;
// functions declarations
void DFS ( int step ) {
	// print judge 
	if ( step == 1 && !notprime [ 1 + mymap[n] ] ) {
		for ( auto &a : mymap ) cout << a.second << ' ' ;
		cout << endl ;
	} else {
		for ( int i = 2 ; i <= n ; i ++ ) {
			if ( nums [i] && !notprime [ i + mymap [ step - 1 ] ]  ) {
				
				nums [i] = false ;
				mymap [step] = i ;
				
				if ( step == n ) DFS ( 1 ) ;
				else DFS ( step + 1 ) ;
				
				mymap.erase ( step ) ; 
				nums [i] = true ;
				
			}
		}
	}
	//
	
}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	// prime
	for ( int i = 2 ; i <= 100 ; i ++ ) {
		if ( !notprime[i] ) {
			prime.push_back ( i ) ;
		}
		for ( auto &a : prime ) {
			if ( i * a > 100 ) break ;
			notprime [ i * a ] = true ;
			if ( i % a == 0 ) break ;
		}
	}
	// DFS
	mymap [1] = 1 ;
	int case_num = 1 ;
	while ( cin >> n ) {
		cout << "Case" << ' ' << case_num << ':' << endl ; 
		for ( int i = 2 ; i <= n ; i ++ ) nums[i] = true ;
		DFS ( 2 ) ;
		for ( int i = 2 ; i <= n ; i ++ ) nums[i] = false ;
		case_num ++ ;
		cout << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/
