//头文件
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std ;
//全局变量&数组

//函数声明

//idea
/*

*/
//代码
int main () {
	ios_base::sync_with_stdio ( false ) ;
	cin.tie ( 0 ) ;
	cout.tie ( 0 ) ;
	int n , q ;
	cin >> n >> q ;
	vector <char> str ( n ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		str[i] = 'A' + i ;
	}
	for ( int i = 0 ; i < n - 1 ; i ++ ) {
		for ( int j = 0 ; j < n - i - 1 ; j ++ ) {
			cout << '?' << ' '<< str[j] << ' ' << str[j+1] << endl ; 
			cout.flush() ;
			char c ;
			cin >> c ;
			if ( c != '<' ) swap ( str[j] , str[j+1] ) ;
		}
	}
	cout << '!' << ' ' ;
	cout.flush() ;
	for ( auto &a : str ) {
		cout << a << ' ' ;
		cout.flush() ;
	}
	return 0 ;
}
//questions ：
/*
buble sort
*/
