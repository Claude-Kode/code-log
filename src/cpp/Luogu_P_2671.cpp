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
		int n , m ;
	cin >> n >> m ;
	vector<int> arr ( n ) ;
	for ( auto &a : arr ) cin >> a ;
	vector<int> color ( n ) ;
	for ( auto &a : color ) cin >> a ;
	// 其实就是要求 x 和 z 的奇偶性相同
	int sum = 0 ;
	// index from 0 to n - 1 
	for ( int i = 0 ; i < n ; i += 2 ) {
		for ( int j = i + 2 ; j < n ; j += 2 ) {
			if ( color[i] == color[j] ) sum += ( i + j + 2 ) * ( arr[i] + arr[j] ) ; 
			sum %= 10007 ;
		}
	}
	for ( int i = 1 ; i < n ; i += 2 ) {
		for ( int j = i + 2 ; j < n ; j += 2 ) {
			if ( color[i] == color[j] ) sum += ( i + j + 2 ) * ( arr[i] + arr[j] ) ; 
			sum %= 10007 ;
		}
	}
	cout << sum << endl ;
	return 0 ;
}
//questions ：
/*

*/