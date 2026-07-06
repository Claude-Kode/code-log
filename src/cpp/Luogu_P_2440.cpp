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
bool check ( int test , int target , vector <int> woods ) {
	int res = 0 ;
	for ( auto &a : woods ) res += ( a / test ) ;
	if ( res >= target ) return true ; // 切多了 ， 单段的长度太小了
	else return false ;
}
//idea
/*
test是当前尝试的单段的长度
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , k ;
	cin >> n >> k ;
	vector <int> woods ( n ) ;
	int maxLen = 0 ;
	for ( auto &a : woods ) {
		cin >> a ;
		if ( maxLen < a ) maxLen = a ;
	}
	int l = 1 , r = maxLen , answer = 0 ;
	while ( l <= r ) {
//		cout << l << ' ' << r << endl ;
		int mid = ( l + r ) / 2 ;
		if ( check ( mid , k , woods ) ) { l = mid + 1 ; answer = mid ; }
		else r = mid - 1 ;
	}
	cout << answer ;
	return 0 ;
}
//questions ：
/*

*/