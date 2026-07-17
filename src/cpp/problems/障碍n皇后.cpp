// header file
#include <iostream>
#include <vector>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
int n ;
int ans = 0 ;
// functions declarations
void DFS ( int row , int &ans , int cols , int diag1 , int diag2 , vector <int> &masks ) {
	if ( row == n  ) ans ++ ;
	else {
		for ( int i = 0 ; i < n ; i ++ ) { // enum cols 
			if ( !( ( cols >> i ) & 1 ) && !( ( diag1 >> ( i + row ) ) & 1) && !( ( diag2 >> ( i - row + n - 1 ) ) & 1 ) && ! ( ( masks[row] >> i ) & 1 ) ) {
				DFS ( row + 1 , ans , cols | ( 1 << i ) , diag1 | ( 1 << (i + row) ) , diag2 | ( 1 << (i - row + n - 1)  ) , masks ) ;
			}
		}
	}
}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	cin >> n ;
	int cols = 0 , diag1 = 0 , diag2 = 0 ;
	vector <int> masks ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int mask = 0 ;
		for ( int j = 0 ; j < n ; j ++ ) {
			char temp ;
			cin >> temp ;
			if ( temp == 'x' ) mask |= ( 1 << j ) ;
		}
		masks.push_back( mask ) ;
	}
	// n equal to rowlen - 1 && collen - 1  
	DFS ( 0 , ans , cols , diag1 , diag2 , masks ) ;
	cout << ans << endl ;
	return 0 ;
}
//questions ：
/*

*/
