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
int arr[100001] , arr_copy[100001] ;
char a[100001] ;
//函数声明
void stringtonumber ( char a[] , int arr[] , int arr_copy[] , int len ) {
	for ( int i = 1 ; i <= len ; i ++ ) {
		arr[i] = a[i] - '0' ;
		arr_copy[i] = arr[i] ; 
	}
}
void process ( int arr[] , int arr_copy[] , int len , int k ) {
	for ( int i = 1 ; i <= len ; i ++ ) {
		if ( arr_copy[i] == 1 ){
			for ( int j = i - k ; j <= i + k ; j ++ ) {
				if ( j < 1 || j > len ) continue ;
				arr[j] = 1 ;
			}
		}
	}
}
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int len ; 
	cin >> len ; 
	for ( int i = 1 ; i <= len ; i ++ ) {
		cin >> a[i] ;
	}
	stringtonumber ( a , arr , arr_copy , len ) ;
	int k ;
	cin >> k ;
	process ( arr , arr_copy , len , k ) ;
//	for ( int i = 1 ; i <= len ; i ++ ) {
//		cout << arr[i] << ' ' ;
//	}
	int count_latern = 0 ;
	for ( int i = 1 ; i <= len ; i ++ ) {
		if ( arr[i] == 0 ){
			count_latern ++ ;
			i += ( 2*k ) ;
		}
	}
	cout << count_latern << endl ;
//	for ( int i = 1 ; i <= n ; i ++ ) {
//		cout << arr[i] << ' ' ;
//	}
//	int sub = 0 ; 
//	for ( int i = 1 ; i <= n ; i ++ ){
//		if ( arr[i] == 0 ) counforzero[sub] ++ ;
//	}
//	if( count_0 / k * k == count_0 ) cout << count 
	return 0;
}
//正着来一遍，碰到1直接把后面k个都变成1，再反着来一遍（也是对原数组）然后合并 但是好像没什么卵用
//用差分数组的状态流来做呢或许可行
