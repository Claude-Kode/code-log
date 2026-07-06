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
int arr[2025][2025] ;
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int  n ;
	cin >> n ;
	int x , y ;
	int max_x = 0 , max_y = 0 ;
	int min_x = 10000 , min_y = 10000 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> x >> y ;
		x += 1000 , y += 1000 ;
		arr[x-1][y-1] = 1 ;
		arr[x-1][y] = 1 ;
		arr[x-1][y+1] = 1 ;
		arr[x][y-1] = 1 ;
		arr[x][y] = 1 ;
		arr[x][y+1] = 1 ;
		arr[x+1][y-1] = 1 ;
		arr[x+1][y] = 1 ;
		arr[x+1][y+1] = 1 ;
		if ( max_x < x ) max_x = x ;
		if ( max_y < y ) max_y = y ;
		if ( min_x > x ) min_x = x ;
		if ( min_y > y ) min_y = y ;
	}
	int square = 0 ;
	for ( int i = min_x - 1  ; i <= max_x + 1 ; i ++ ) {
		for ( int j = min_y - 1 ; j <= max_y + 1 ; j ++ ) {
			if ( arr[i][j] == 1 && arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] == 1 ){
				square ++ ;
			}
		}
	}
	cout << square << endl ;
	return 0 ;
}
