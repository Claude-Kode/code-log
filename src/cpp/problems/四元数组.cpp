//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组
int arr[1001], l[1001], r[1001] ;
//函数声明

//代码
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n ;
	cin >> n ;
	int result = 0 ;

	for ( int i = 0 ; i < n ; i++ ) cin >> arr[i] ;

	for ( int j = 1 ; j < n ; j++ ) {
		for ( int i = 0 ; i < j ; i++ ) {
			if ( arr[i] < arr[j] ) l[j]++;
		}
	}

	for ( int k = 1 ; k < n - 1 ; k++ ) {
		for ( int i = k + 1 ; i < n ; i++ ) {
			if ( arr[i] >  arr[k] ) r[k]++;
		}
	}

	for ( int j = 0 ; j < n - 1 ; j++ ) {
		for ( int k = j + 1 ; k < n ; k++ ) {
			if ( arr[j] < arr[k] ) result += ( l[j] * r[k] ) % 3344 ;
		}
	}
	result %= 3344 ;
	cout << result << endl ; 
	return 0;
}
