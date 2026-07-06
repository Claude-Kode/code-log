// header file
#include <iostream>
#include <vector>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
结局自己组的1是奇数次就赢了
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ; cin >> t ;
	while ( t -- ) {
		int n ; cin >> n ;
		vector<int> A ( n ) , B ( n ) ;
		int res = 0 ; 
		for ( auto &a : A ) { cin >> a ; res ^= a ; } 
		for ( auto &a : B ) { cin >> a ; res ^= a ; }
		if ( !res ) { cout << "Tie" << endl ; continue ; }
		int f_bit = 0 , index = 0 ;
		for ( int i = 0 ; i < 32 ; i ++ ) if ( res >> i & 1 ) f_bit = i ;
		// 找到最后一个可以改变 f_bit 位的索引是谁 谁能改变谁就赢了
		for ( int i = 0 ; i < n ; i ++ ) 
			if ( ( A[i] ^ B[i] ) & 1 << f_bit ) 
				{ index = i ; }
		( index & 1 ) == 1 ? cout << "Mai" << endl : cout << "Ajisai" << endl ;
 	}
	return 0 ;
}
//questions ：
/*

*/