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
void generate_prefix ( int pre []  , int arr[] , int n ) {
	pre[0] = 0 ;
	for ( int i = 1; i <= n ; i ++ ) {
		pre[i] = arr[i] + pre[i-1] ; 
	}
}
void generate_suffix ( int suff[]  , int arr[] , int n ) {
	for ( int i = n ; i >= 1 ; i -- ) {
		suff[i] = suff[i+1] + arr[i] ;
	}
}
//idea
/*
把水群的次数排序，递减，从头取，从末尾取
头的次数是count_head，尾部的是count_tail
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n ;
	cin >> n ;
	int arr[n+1] = { 0 } , pre[n+1] = { 0 } , suff[n+1] = { 0 };
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> arr[i] ;
	}
	sort ( arr , arr + n ) ;
	generate_prefix ( pre , arr , n ) ;
	generate_suffix ( suff , arr , n ) ;
//	for ( auto & a : arr ) {     sort output test 
//		cout << a << ' ' ;
//	}
	int q ;
	cin >> q ;
	while ( q -- ) {
		int x ;
		cin >> x ;
		int next_result = 0 , sum_result = 0 ;
		if ( ( x & 1 ) == 1 ) { // x is odd
			next_result = arr[ n - ( x - 1 ) / 2 ] ;
			sum_result += pre[ ( x - 1 ) / 2 + 1 ] ;
			sum_result += suff[ n - ( x - 1 ) / 2 + 1 ] ;
			cout << next_result << ' ' << sum_result << endl ;
		} else { // x is even
			next_result = arr[ x / 2 + 1 ] ;
			sum_result += pre[ x / 2 ] ;
			sum_result += suff[ n - x / 2 + 1 ] ;
			cout << next_result << ' ' << sum_result << endl ;
		}
	}
	return 0;
}
//questions
/*
greater <int> () ;

*/
