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
struct rectangle {
	int x ;
	int y ;
};
int arr[100001] ;
//函数声明
int count_pieces ( vector <rectangle> rectangle_vector , int test ) {
	int cnt_pieces = 0 ;
	for ( auto &a : rectangle_vector ) {
		cnt_pieces += ( a.x / test ) * ( a.y / test )  ;
	}
	return cnt_pieces ;
}
//idea
/*
首先枚举每块巧克力的宽 x
然后是验证答案环节
对于每块巧克力 ，长a宽b
能切出 ( a / x ) * ( b / x ) 块
l肯定是1，r是这里面的x或者y最大的一个
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , k ;
	cin >> n >> k ;
	vector <rectangle> rectangle_vector ( n ) ;
	int max_side_len = 0 ;
	for ( auto &a : rectangle_vector ) {
		cin >> a.x >> a.y ;
		// find max side_length
		if ( max_side_len < a.x || max_side_len < a.y ) {
			max_side_len = max ( a.x , a.y ) ; 
		}
	}
	int l = 1 , r = max_side_len ; //还是闭区间写法
	int result = 0 ;
	while ( l <= r ) {
		int mid = ( l + r ) / 2 ;
		int cnt = count_pieces ( rectangle_vector , mid ) ;
		if ( cnt >= k ) {
			l = mid + 1 ;
			result = mid ;
		}
		if ( cnt < k ) r = mid - 1 ;
	}
	cout << result << endl ;
	return 0;
}
//questions ：
/*

*/
