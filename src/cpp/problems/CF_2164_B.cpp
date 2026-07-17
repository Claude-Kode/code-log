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
void solve() {
	int n ; cin >> n ;
	vector<int> arr ( n ) ;
	for ( auto &a : arr ) cin >> a ;
	sort ( arr.begin() , arr.end() ) ;
	for ( int i = 0 ; i < n - 1 ; i ++ ) {
		for ( int j = i + 1 ; j < n ; j ++ ) {
			if ( arr[j] % arr[i] % 2 == 0 ) {
				cout << arr[i] << ' ' << arr[j] << endl ;
				return ;
			}
		}
	}
	cout << -1 << endl ;
}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int tt ; cin >> tt ;
	while ( tt -- ) solve() ; 
	return 0 ;
}
//questions ：
/*

*/