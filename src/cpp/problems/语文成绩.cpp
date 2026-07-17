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
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n , p ;
	cin >> n >> p ; 
	for ( int i = 1 ; i <= n ; i ++ ){
		cin >> arr[i] ;
	}
	generate_diff ( arr , diff , n ) ;
	int min_score = 300000000 ; 
	while ( p -- ) {
		int l = 0 , r = 0 , score = 0 ;
		cin >> l >> r >> score ;
		diff[l] += score ; 
		if( ( r + 1 ) <= n ) diff[r+1] -= score ;
	}
	int final_score = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ){
		final_score += diff[i] ;
		if ( min_score > final_score ) {
			min_score = final_score ;
		}
	}
	cout << min_score << endl ;
	return 0;
}
