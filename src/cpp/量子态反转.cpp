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
正态就是偶数
反态就是奇数
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , k ;
	cin >> n >> k ;
	int arr[n+1] = { 0 } , diff[n+1] = { 0 };
	while ( k -- ) {
		int l = 0 , r = 0; 
		cin >> l >> r ;
		diff[l] ++ ;
		if ( r <n ) diff[r+1] -- ;
	}
	int count_normal = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		arr[i] = arr[i-1] + diff[i] ;
		if ( (arr[i] & 1) == 0 ) {
			count_normal ++ ;
		}
	}
	cout << count_normal << endl ;
	return 0;
}
