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
int arr[100005] , suf[100005] ;
//函数声明
void generate_suffix( int arr[] , int suf[] , int n ){
	suf[n+1] = 0 ;
	for ( int i = n ; i >= 1 ; i -- ) {
		suf[i] = suf[i+1] + arr[i] ;
	}
}
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n ;
	cin >> n ;
	for( int i = 1 ; i <= n ; i ++ ){
		cin >> arr[i] ;
	}
	generate_suffix ( arr , suf , n ) ;
	for ( int i = n ; i >= 1 ; i -- ) {
//		cout << suf[i] << ' ' ;
	}
	int k = 1000001 ;
	int temp = 0 ; 
	for ( int i = n ; i >= 1 ; i -- ) {
		temp = suf[i] / ( n + 1 - i ) ;
		if ( k > temp ) k = temp ;
//        cout << temp << ' ' ;
	}
//	cout << k ;
	long long result = 0 ;
	long long pass = 0 ;
	for( int i = n ; i >= 1 ; i -- ) {
		arr[i] += pass ;
		result += arr[i] - k ; 
		pass = arr[i] - k ;
	}
	cout << result << endl ;
	return 0;
}
//传递 ：多于当前的装进pass里面，操作次数等于每次的pass数量
