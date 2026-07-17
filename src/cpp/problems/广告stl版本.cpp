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
struct square_infor {
	int x ;
	int y ;
};
//函数声明

int sort_x ( square_infor a , square_infor b ) {
	if ( a.x == b.x ) return a.y < b.y ;
	return a.x < b.x ;
}

int sort_y ( square_infor a , square_infor b ) {
	if ( a.y == b.y ) return a.x < b.x ;
	return a.y < b.y ;
}

//idea

//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n ;
	cin >> n ;
	vector < square_infor > ads ( n ) ;
	for ( auto &a : ads ) {
		cin >> a.x >> a.y ;
	}
	
	int result = 4 * n ; 
	//先查一个x上的重复
	sort ( ads.begin() , ads.end() , sort_x ) ;
	for ( auto a = ads.begin() ; a < ads.end() - 1 ; a ++ ) {
		if ( abs( ( a + 1 ) -> x - ( a -> x ) )== 1  && abs(  ( a + 1 ) -> y -  a -> y  )== 1 ) {
			result -= 1 ;
		}
		if ( ( a -> x ) == ( ( a + 1 ) -> x ) && ( ( a + 1 ) -> y )- ( a -> y ) == 1 ) {
			result -= 2 ;
		}
	}
	//在查同一个y上重复的
	sort ( ads.begin() , ads.end() , sort_y ) ;
	for ( auto a = ads.begin() ; a < ads.end() - 1 ; a ++ ) {
		if ( abs( ( a + 1 ) -> x - ( a -> x ) )== 1  && abs( ( ( a + 1 ) -> y )- ( a -> y ) )== 1 ) {
			result -= 1 ;
		}
		if ( ( a -> y ) == ( ( a + 1 ) -> y ) && ( ( a + 1 ) -> x ) - ( a -> x ) == 1 ) {
			result -= 2 ;
		}
	}
	cout << result << endl ;
	return 0;
}
