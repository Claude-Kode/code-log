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
const int maxn = 1000005 ;
// functions declarations

//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ; cin >> n ;
	while ( n -- ) 
	vector<int> primes ; 
	vector<bool> np ( n + 1 , 0 ) ;
	for ( int i = 2 ; i <= n ; i ++ ) {
		if ( !np[i] ) primes.push_back( i ) ; 
		for ( auto &a : primes ) {
			if ( i * a > n ) break ;
			np[i * a] = true ;
			if ( i % a == 0 ) break ;
		} 
 	}
	// 求每个数到下一个质数有多远
	int r = 0 ;
	int num = 1 ; 
	while ( r <= primes.size() - 1 ) {
		if ( num == n ) { cout << 1 << endl ; break ; }
		if ( num <= primes[r] ) cout << primes[r] - num << endl ;
		else r ++ ;
	}
	return 0 ;
}
//questions ：
/*

*/
	return 0 ;
}
//questions ：
/*

*/