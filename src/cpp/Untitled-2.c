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

// functions declarations
bool check ( int test , int target ,  vector <int> power ) {
	if ( power[test] >= target ) return false ;
	else return true ;
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
		int n ;
		cin >> n ;
		vector <int> power ( n ) ;
		vector <int> wins ;
		vector <int> loses ;
		for ( auto &a : power ) cin >> a ;
		sort ( power.begin() , power.end() ) ;
		for ( int i = 0 ; i < n ; i ++ ) {
			// 如果前面的数字等于这个数字，把wins和loses的最后一个结果push_back
			// 如果不等于，说明这是第一个 win = i , lose = n - upper_bound + 1 
			if ( i > 0 && power[i] == power[i-1] ) {
				wins.push_back( wins.back() ) ;
				loses.push_back( loses.back() ) ;
			} else {
				wins.push_back( i ) ;
				auto it = upper_bound( power.begin() , power.end() , power[i] ) ;
				if ( it == power.end() ) loses.push_back( 0 ) ;
				else {
					loses.push_back( n - 1 - ( it - power.begin() ) + 1 ) ; 	
				}
			}
		}
		for ( auto &a : wins ) cout << a << ' ' ;
		cout << endl ;
s		for ( auto &a : loses ) cout << a << ' ' ;
		cout << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/