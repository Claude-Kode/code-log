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

//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ; cin >> n ;
	vector<vector<int>> arr ( 2 , vector<int> ( n ) ) ;
	int mn = INT_MAX , mx = INT_MIN ;
	for ( auto &row : arr ) {
		for ( auto &a : row ) {
			cin >> a ;
			mx = max ( mx , a ) ;
			mn = min ( mn , a ) ;   
		}
	}
	
	return 0 ;
}
//questions ：
/*

*/