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
	int n ;
	cin >> n ;
	vector<int> arr ( n ) ;
	int sum = 0 ;
	for ( auto &a : arr ){
		cin >> a ;
		sum += a ;
	}	
	cout << sum << endl ;
	sum > 100 ? cout <<  "Statement made by gzd" << endl : cout << "Good job" << endl ;
	return 0 ;
}
//questions ：
/*

*/