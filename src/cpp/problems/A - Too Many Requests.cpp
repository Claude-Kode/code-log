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
cout n times , 
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , m ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) { 
		if ( i <= m ) {
			cout << "OK" << endl ;
		} else {
			cout << "Too Many Requests" << endl ;  
		}
	}
	return 0 ;
}
//questions ：
/*

*/
