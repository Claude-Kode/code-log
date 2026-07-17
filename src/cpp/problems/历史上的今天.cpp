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
一个标志sign
初始化 sign = 0 
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	string str ;
	cin >> str ;
	bool sign = false ; 
	for ( auto &a : str ) {
		// reverse judge and process
		if ( sign ) a = '1' - a + '0' ;
		// judge sign 
		if ( a == '1' ) sign = !sign ;
	}
	cout << str << endl ;
	return 0 ;
}
//questions ：
/*

*/