//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
//宏定义
#define endl '\n'
#define mod 1000000007
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明
int multiply ( int k ) {
	int result = 1 ;
	for ( int i = 0 ; i < k ; i ++ ) {
		result *= 2 ;
	}
	return result ;
}
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
		int buckle[200] = { 0 } ;
		int k ;
		cin >> k ;
		int times = multiply(k) ;
		for ( int i = 1 ; i <= times ; i ++ ) {
			int temp ;
			cin >> temp ;
			buckle[temp] ++ ;
		}
		
		for ( int i = 1 ; i < 200 ; i ++ ) {
			buckle[i] += buckle[i-1] / 2 ;
			buckle[i-1] %= 2 ;
		}
			
		long long result = 0 , base = 1 ;
		
		for ( int i = k ; i < 200 ; i ++ ) {
			result = ( result + ( base * buckle[i] ) % mod ) % mod ;
			base = ( base * 2 ) % mod ;
		}
		cout << result << endl ;
	}
	return 0;
}
//questions ：
/*

*/
