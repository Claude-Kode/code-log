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
int arr[3000001] , diff[3000001] ;
//函数声明
void generate_diff ( int arr[] , int diff[] , int n ){
	diff[0] = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ){
		diff[i] = arr[i] - arr[i-1] ;
	}
}
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , q ; 
	cin >> n >> q ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> arr[i] ;
	}
	generate_diff ( arr , diff , n ) ;
	int operate = 0 ;
	while ( q-- ) {
		cin >> operate ;
		int l = 0 , r = 0 , w = 0 ;
		
		if ( operate == 1 ) { // add
			cin >> l >> r >> w ;
			diff[l] += w ;
			if ( ( r + 1 ) <= n ) diff[r+1] -= w ;
			
		} else if ( operate == 2 ) { // subtract 
			cin >> l >> r >> w ;
			diff[l] -= w ;
			if ( ( r + 1 ) <= n ) diff[r+1] += w ;
			
		} else { // print
			cin >> l >> r ;
			int number = 0 ;
			for ( int i = 1 ; i <= r ; i ++ ){
				number += diff[i] ;
				if ( i >= l ) cout <<  number << ' ' ;
			}
			cout << endl ;
		} 
	}
	return 0;
}
