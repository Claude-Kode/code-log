//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明

//idea
/*

*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n ;
		cin >> n ;
		vector <int> arr ( n ) ;
		int result = 0 ;
		bool have_different = true ;
		for ( auto & a : arr ) {
			cin >> a ;
			if ( have_different && a != arr[0] ) {
				result = a ;
				a = 0 ;
				have_different = false ;
			}
		}
		if ( result ) {
			//
			cout << 1 << endl << result ;
			cout << endl ;
			//
			cout << n -1 ;
			cout << endl ;
			for ( const auto &a : arr ) {
				if ( a != 0 ) cout << a << ' ' ;
			}
			cout << endl ;
		} else {
			cout << 1 << endl << arr[0] ;
			cout << endl ;
			arr.pop_back() ;
			for ( const auto &a : arr ) {
				cout << a << ' ' ;
			}
			cout << endl ;
		}
		arr.clear() ;
	}
	return 0;
}
