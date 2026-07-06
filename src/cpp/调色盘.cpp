//头文件
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
//宏定义
#define endl '\n'
#define int long long
//命名空间声明
using namespace std ;
//全局变量&数组

//函数声明
int count_operations ( vector <int> arr , int n  , int m ) {
	int operations = 0 ;
	while ( arr[m-1] > 0 ) {
		for ( int i = 0 ; i < m ; i ++ ) {
			arr[i] -- ;
		}
// 		for ( int i = 0 ; i < n ; i ++ ) {
// 			cout << arr[i] << ' ' ;
// 		}
//         cout << endl ;
		sort ( arr.begin() , arr.end() , greater<int>() ) ;
// 		for ( int i = 0 ; i < n ; i ++ ) {
// 			cout << arr[i] << ' ' ;
// 		}
// 		cout << endl ;
		operations ++ ;
	}
	return operations ;
}

//idea
/*
array-a have n elements
every times you can choose m elements with different subs , make them -- , count for one operation
question for the maximum number of the operations
the best condition is clear the array-a as possible
so you should minus the elements by the desending order of their value
and every time you change the elements
you should make a sort
range sub from 0 to m
without using binary search
//
binary search method 
enumerate the quantity of palettes
minus the quantity according to the condition of value of the elements in array-a
if quantity < 0 , break and make l bigger
if quantity = 0 ,try to make l bigger
if quantity < 0 , try to make r smaller
that's my approach 
*/
//代码
signed main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , m , k ;
	cin >> n >> m >> k ;
	vector <int> arr ( n ) ;
	int total = 0 , min_value = 2e9 ;
	for ( auto &a : arr ) {
		cin >> a ;
		total += a ;
		if ( min_value > a ) min_value = a ;
	}
	if ( m == n ) { 
		cout << min_value << endl ;
	} else if ( n == 1 || m == 1 ) {
		cout << total << endl ; 
	} else {
		sort ( arr.begin() , arr.end() , greater<int>() ) ;
//		count_operations( arr , n , m ) ;
		cout << count_operations( arr , n , m ) * k << endl ;	
	}
	return 0 ;
}
//questions ：
/*

*/
