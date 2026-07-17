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
struct sign{
	int smaller ;
	int larger ;
};
int arr[1001];
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n ;
	cin >> n ;
	for ( int i = 0 ; i < n ; i++){
		cin >> arr[i] ;
	}
	sign a[ ( n * n - n ) / 2 ] ;
	int sub = 0 ;
	for ( int i = 0 ; i < n - 1 ; i++){
		for ( int j = i + 1 ; j < n ; j++){
			if ( arr[i] < arr[j] ) {
				a[sub].smaller = arr[i] ; 
				a[sub].larger = arr[j] ;
				sub++;
			}
		}
	}
	int result = 0 ;
	for ( int i = 0 ; i < sub - 2  ; i++ ){
		for ( int j = i + 1 ; j < sub - 1  ; j++ ){
			for ( int k = j + 1 ; k < sub ; k++ ){
				if ( a[i].larger < a[j].smaller && a[j].larger < a[k].smaller ){
					result++;
				}
			}
		}
	}
	cout << result << endl ;
	return 0;
}
