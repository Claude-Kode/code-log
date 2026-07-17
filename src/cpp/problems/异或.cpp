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
		int n , x ;
		cin >> n >> x ;
		if ( n == 1 ) {
			cout << -1 << endl ;
			continue ;
		}
		if  ( ( x & 1 ) == 1 ) {
			cout << -1 << endl ;
			continue ;
		} else {
			for ( int i = 0 ; i < n - 2 ; i ++ ) {
				cout << 0 << ' ' ;
			}
			cout << x / 2 << ' ' << x / 2 << endl ;
		}
	}
	return 0;
}
//questions ：
/*

*/
