// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <climits>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations
bool check ( int test , int target , vector <int> &grade ) {
	if ( grade[test] >= target ) return true ;
	else return false ;
}
//idea
/*
对于query的灭一个元素在grade数组中找一个绝对值相差最小的数
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int m , n ;
	cin >> m >> n ;
	vector <int> grade ( m + 1 ) ;
	vector <int> query ( n ) ;
	for ( int i = 1 ; i <= m ; i ++ ) cin >> grade[i] ;
	grade[0] = INT_MIN ; grade.push_back ( INT_MAX ) ;
	sort ( grade.begin() , grade.end() ) ;
	int res = 0 ; 
	for ( auto &a : query ) {
		cin >> a ;
		// a is target 
		int l = 1 , r = m , answer = 0 ; 
		while ( l <= r ) {
//			cout << l << ' ' << r << endl ;
			int mid = ( l + r ) / 2 ;
			if ( check ( mid , a , grade ) ) r = mid - 1 ;
			else l = mid + 1 ;
			answer = mid ; 
		} 
		res += min ( { abs ( grade[answer] - a ) , abs( grade[answer+1] - a ) , abs( grade[answer-1] - a ) } ) ; 
	}
	cout << res ;
	return 0 ;
}
//questions ：
/*

*/