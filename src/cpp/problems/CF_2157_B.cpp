// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
// macro definition
#define endl '\n'
#define int long long
#define maxn 200001
// namespace declarations
using namespace std ;
// global variables && arrays
int dirs[3][2] = { { 1 , 0 } , { 0 , 1 } , { 1 , 1 } } ;
// functions declarations 
// bool solve() {
// 	int n , xx , yy ; cin >> n >> xx >> yy ;
// 	xx = abs( xx ) ; yy = abs( yy ) ; 
// 	string str ; cin >> str ;
// 	// BFS
// 	queue<pair<int , int>> q ;
// 	vector<vector<int>> vis ( maxn , vector<int> ( maxn , 0 ) ) ;
// 	q.emplace( 0 , 0 ) ; vis[0][0] = 1 ;
// 	int lim ;
// 	for ( auto &c : str ) {
// 		c == '4' ? lim = 2 : lim = 3 ;
// 		int t = q.size() ;
// 		while ( t -- ) {
// 			auto [x , y] = q.front() ; q.pop() ; 
// 			if ( x == xx && y == yy ) return true ;
// 			for ( int i = 0 ; i < lim ; i ++ ) {
// 				int nx = x + dirs[i][0] , ny = y + dirs[i][1] ;
// 				if ( !vis[nx][ny] ) { q.emplace( nx , ny ) ; vis[nx][ny] = true ; } 
// 			}
// 		} 
// 	}
// 	return false ;
// }
bool solve () {
	int n , xx , yy ; cin >> n >> xx >> yy ;
	xx = abs( xx ) ; yy = abs( yy ) ; 
	string str ; cin >> str ;
	int cnt_4 = 0 ;
	for ( auto &c : str ) if ( c == '4' ) cnt_4 ++ ; 
	if ( xx <= n && yy <= n ) {
		if ( yy <= n - cnt_4 ) return true ;
		if ( xx <= n - cnt_4 ) return true ;
		if ( xx + yy <= 2 * n - cnt_4 ) return true ;
	}
	return false ;
}
//idea
/*
这个题只和 x , y 的绝对值有关系
我觉得有点棘手的是那个正好卡在边边的缝里
*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int tt ; cin >> tt ;
	while ( tt -- ) solve() ?cout << "YES" << endl : cout << "NO" << endl ;
	return 0 ;
}
//questions ：
/*

*/