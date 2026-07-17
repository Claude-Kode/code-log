//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
int arr[100001] ;
//函数声明
bool check ( int arr[] , int test , int m , int n ) {
	int cnt = 0 ; 
	int total = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		total += arr[i] ;
		if ( total > test ) {
			cnt ++ ;
			total = arr[i] ;
		}
	}
	if ( cnt > m ) return false ; //分的段数太多了，test定少了
	else return true ; //分段分的少了，定的test高了
}
//idea
/*
M <= N 可能出现单个数字成一组，且所有数字都是最大值，还是闭区间
问test的最小值，所以等于了之后还得往小了找
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m ;
	cin >> n >> m ;
	int max_number = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> arr[i] ;
		max_number += arr[i] ;
	}
	int l = 1 , r = max_number ;
	while ( l <= r ) {
		int mid = ( l + r + 1 ) >> 1 ;
		if ( check ( arr , mid , m , n ) ) r = mid - 1 ;
		else l = mid + 1 ;
	}
	cout << l << endl ;
	return 0;
}
//questions ：
/*
分割问题默认是连续，不能排序后处理
*/
