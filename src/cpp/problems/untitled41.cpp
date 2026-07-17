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
bool oil [114] [514] ;
struct coordinate {
	int x ;
	int y ;
};
int cnt = 0 ;
int root_x , root_y ;
// functions declarations

void DFS ( int x , int y ) { // x == row ; y == coloumn
	oil [ x ] [ y ] = false ;
	if ( oil [ x - 1 ] [ y ]     ) DFS ( x - 1 , y ) ; // 上
	if ( oil [ x - 1 ] [ y + 1 ] ) DFS ( x - 1 , y + 1 ) ; // 右上
	if ( oil [ x ] [y + 1]       ) DFS ( x , y + 1 ) ; // 右
	if ( oil [ x + 1 ] [ y + 1 ] ) DFS ( x + 1 , y + 1 ) ; // 右下
	if ( oil [ x + 1 ] [ y ]     ) DFS ( x + 1 , y ) ; // 下
	if ( oil [ x + 1 ] [ y - 1 ] ) DFS ( x + 1 , y - 1 ) ; // 左下
	if ( oil [ x ] [ y - 1 ]     ) DFS ( x , y - 1 ) ; // 左
	if ( oil [ x - 1 ] [ y - 1 ] ) DFS ( x - 1 , y - 1 ) ; // 左上
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
	while ( cin >> n >> m && m != 0 ) {
		vector <coordinate> real_oil ;
		for ( int i = 1 ; i <= n ; i ++ ) { // x == i ; y == j
			string row ;
			cin >> row ; // 读一行
			for ( int j = 1 ; j <= m ; j ++ ) {
				if ( row [ j - 1 ] == '@' ) { // 挨个判
					oil [ i ] [ j ] = true ;
					real_oil.push_back ( { i , j } ) ; // 记坐标
				}
			}
		}
		for ( auto &a : real_oil ) {
			if ( oil [ a.x ] [ a.y ] ) {
				root_x = a.x ;
				root_y = a.y ; //记录根坐标
				DFS ( a.x , a.y ) ;
			}
		}
		cout << cnt << endl ;
		cnt = 0 ;
		real_oil.clear() ;
	}
	return 0 ;
}
//questions ：
/*

*/
