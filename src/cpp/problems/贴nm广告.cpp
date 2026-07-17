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
struct coordinate{
	int x ;
	int y ;
};
//函数声明
int cmp_x ( const coordinate &a , const coordinate &b ) {
	if ( a.x < b.x ) return a.x ;
	if ( a.x == b.x )return a.y < b.y ;
}
int cmp_y ( const coordinate &a , const coordinate &b ) {
	if ( a.y < b.y ) return a.y ;
	if ( a.y == b.y )return a.x < b.x ;
}
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n ; 
	cin >> n ;
	coordinate a[n] ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> a[i].x >> a[i].y ;
	}
	int result = 4 * n ;
	sort ( a , a + n , cmp_y ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
//		if ( a[i+1].x - a[i].x == 1 && a[i+1].y == a[i].y ) result -= 2 ;
		cout << a[i].x << ' ' << a[i].y << endl ;
	}
	cout << endl ;
	sort ( a , a + n , cmp_x ) ;
	for ( int i = 0 ; i < n - 1 ; i ++ ) {
//		if ( a[i+1].y - a[i].y == 1 && a[i+1].x == a[i].x  ) result -= 2 ;
		cout << a[i].x << ' ' << a[i].y << endl ;
	}
	
	for ( int i = 0 ; i < n - 1 ; i ++ ) {
		for ( int j = i + 1 ; j < n ; j ++ ) {
			if ( a[j].y - a[i].y == 1 && a[j].x - a[i].x == 1 ) result -= 1 ;
		}
	}
//	cout << result << endl ;
	return 0;
}
//如果x 相同 ， y 相差为 1 ， 重合 += 2
//如果y 相同 ， x 相差为 1 ， 重合 += 2
//如果 x y 都相差 1 ，重合 += 1
//每个x对y排序 ，遍历
//每个y对x排序 ，遍历
//问题的关键，怎么筛选出 x 和 y 都相差 1 的项的总数呢
