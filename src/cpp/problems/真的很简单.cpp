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
欧拉筛判断
但是合数往上乘的操作只能到n ,
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ; 
	while ( t -- ) {
		int n , m ; 
		cin >> n >> m ;
		int cnt = 0 ;
		for ( int i = 1 ; i <= n ; i ++ ) 
			if ( m % i == 0 ) cnt ++ ;
		( cnt & 1 ) == 1 ? cout << "Yes" << endl : cout << "No" << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/