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
#define int long long 
#define mod 1000000007
//命名空间声明
using namespace std ;
//全局变量&数组

//函数声明
int fact ( int a , int b ) {
	int res = 1 ;
	for ( int i = a ; i > a - b ; i -- ) {
		res *= i ;
		res %= mod ;
	}
	return res ;
}
//idea
/*

*/
//代码
signed main(){
	ios_base::sync_with_stdio ( false ) ; cin.tie ( 0 ) ;cout.tie ( 0 ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n , m , k ;
		cin >> n >> m >> k ;
		vector <int> arr ( n ) ;
		int cnt = 0 ;
		for ( auto &a : arr ) {
			cin >> a ;
			if ( a >= k ) cnt ++ ;
		}
		cout << fact ( m , cnt ) << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/
