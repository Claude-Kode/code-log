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
int arr[100001];
//函数声明

//idea
/*

*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , q ;
	cin >> n >> q ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> arr[i] ;
	}
	while ( q -- ) {
		int query ;
		cin >> query ;
		int l = 0 , r = n ;
		while ( l < r ) {
			int mid = ( l + r ) >> 1 ;
			if ( arr[mid] >= query ) r = mid ;
			else l = mid + 1 ;
		}
		r < n ? cout << arr[r] << endl : cout << -1 << endl ;
	}
	return 0;
}
//questions ：
/*

*/
