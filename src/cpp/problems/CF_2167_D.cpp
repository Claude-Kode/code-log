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
vector<int> ansList = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 } ;
// functions declarations

//idea
/*
enumerate the x and check by traveling the array 
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t; 
	while ( t -- ) {
		int n ;
		cin >> n ;
		vector <int> arr ( n ) ;
		for ( auto &a : arr ) cin >> a ;
		bool sign = false ;
		for ( auto &a : ansList ) {
			if ( sign ) break ;
			for ( auto &b : arr) {
				if ( b % a ) {
					cout << a << endl ;
					sign = true ;
					break ;
				}
			}
		}
	}
	return 0 ;
}
//questions ：
/*

*/