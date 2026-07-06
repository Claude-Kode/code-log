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
int arr[1001][1001] ;
long long pre[1001][1001] ;
//函数声明
void generate_prefix ( int arr[][1001] , long long pre[][1001] , int n ,int m ){
	pre[0][0] = 0 ; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pre[i][j] = arr[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		}
	}
}
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m , c ;
	cin >> n >> m >> c ;
	//int max_len = min ( n , m ) ; //领地的最大边长
	for ( int i = 1 ; i <= n ; i ++ ){
		for ( int j = 1 ; j <= m ; j++ ){
			cin >> arr[i][j] ;
		}
	}
	generate_prefix( arr, pre , n , m ) ; 
	long long max = -10000000000000 ;
	int x = 1 , y = 1 ;
	long long value = 0 ;
	for ( int row = 1 ; row <= n - c + 1 ; row ++ ){
		for ( int col = 1 ; col <= m - c + 1 ; col ++ ){
			value = pre[row+c-1][col+c-1] - pre[row+c-1][col-1] - pre[row-1][col+c-1] + pre[row-1][col-1] ;
			if ( max < value ) { 
				max = value ; 
				x = row ;
				y = col ;
			}else if ( max == value ){
				if ( x > row ) { x = row ;}
				else if ( x == row ) { y = min ( y , col ) ;}
			}
		}
	}
	cout << x << ' ' << y << endl ;
	return 0;
}

