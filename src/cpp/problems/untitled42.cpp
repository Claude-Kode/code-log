// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
bool cell [114] [514] ;
struct coordinate {
	int x ;
	int y ;
};
int cnt = 0 ;
int root_x , root_y ;
// functions declarations

void DFS ( int x , int y ) { // x == row ; y == coloumn
	cell [ x ] [ y ] = false ;
	if ( cell [ x - 1 ] [ y ]     ) DFS ( x - 1 , y ) ; // 上
	if ( cell [ x - 1 ] [ y + 1 ] ) DFS ( x - 1 , y + 1 ) ; // 右上
	if ( cell [ x ] [y + 1]       ) DFS ( x , y + 1 ) ; // 右
	if ( cell [ x + 1 ] [ y + 1 ] ) DFS ( x + 1 , y + 1 ) ; // 右下
	if ( cell [ x + 1 ] [ y ]     ) DFS ( x + 1 , y ) ; // 下
	if ( cell [ x + 1 ] [ y - 1 ] ) DFS ( x + 1 , y - 1 ) ; // 左下
	if ( cell [ x ] [ y - 1 ]     ) DFS ( x , y - 1 ) ; // 左
	if ( cell [ x - 1 ] [ y - 1 ] ) DFS ( x - 1 , y - 1 ) ; // 左上
	if ( x == root_x && y == root_y ) cnt ++ ;
//    cout << x << ' ' << y << endl ;
}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , m ;
	cin >> n >> m ;
	vector <coordinate> real_cell ;
	for ( int i = 1 ; i <= n ; i ++ ) { // x == i ; y == j
		for ( int j = 1 ; j <= m ; j ++ ) {
			int temp ;
			cin >> temp ;
			if ( temp ) cell [i] [j] = true ;
		}
	}
	for ( auto &a : real_cell ) {
		if ( cell [ a.x ] [ a.y ] ) {
			root_x = a.x ;
			root_y = a.y ; //记录根坐标
			DFS ( a.x , a.y ) ;
		}
	}
	cout << cnt << endl ;
	return 0 ;
}
//questions ：
/*

*/
