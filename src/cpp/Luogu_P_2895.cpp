// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map> 
#include <queue>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
int dirs[5][2] = { { 0 , 0 } , { 1 , 0 } , { -1 , 0 } , { 0 , 1 } , { 0 , -1 } } ;
// functions declarations
bool judge ( int x , int y ) { return x >= 0 && y >= 0 ; }
//idea
/*
只要BFS的途中碰到这个点是-1就可以逃出去
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;

	// input process
	int m ;
	cin >> m ;
	unordered_map<int, vector<pair<int , int>>> stones ;
	vector<vector<int>> map ( 305 , vector<int> ( 305 , 0 ) ) ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int x , y , t ; cin >> x >> y >> t ;
		stones[t].emplace_back( x , y ) ;
		for ( auto &dir : dirs ) {
			int nx = x + dir[0] , ny = y + dir[1] ;
			if ( judge( nx , ny ) ) {
				map[nx][ny] = 1 ;
			}
		}
	}

	// 找目标点
	// int tx = -1 , ty = -1 ;
	// for ( int i = 0 ; i < 302 ; i ++ ) {
	// 	for ( int j = 0 ; j <= i ; j ++ ) {
	// 		if ( map[j][i - j] == 0 ) 
	// 			tx = i ; ty = j ;
	// 	}
	// }
	// if ( tx == -1 && ty == -1 ) { cout << -1 << endl ; return 0 ; }

	// BFS part
	// 因为可能不能动 , 所以移动要把自己加上
	vector<vector<int>> st ( 305 , vector<int> ( 305 , 0 ) ) ;
	vector<vector<int>> vis ( 305 , vector<int> ( 305 , 0 ) ) ;
	// x , y , time
	queue<tuple<int , int , int>> q ;
	q.emplace( 0 , 0 , 0 ) ;
	while ( !q.empty() ) {
		// 标记陨石
		auto [x , y , t] = q.front() ; q.pop() ; 
		if ( stones.count( t ) ) {
			for (auto [xx, yy] : stones[t]) {
				st[xx][yy] = 1 ;
				for ( auto &dir : dirs ) {
					int nxx = xx + dir[0] , nyy = yy + dir[1] ;
					if ( judge( nxx , nyy ) ) st[nxx][nyy] = 1 ;
				}
			}
		}
		if ( st[x][y] == 1 ) continue ;
		if ( map[x][y] == 0 ) { cout << t << endl ; return 0 ; }
		// 搜索下一步
		for ( auto &dir : dirs ) {
			int nx = x + dir[0] , ny = y + dir[1] ;
			if ( judge( nx , ny ) && vis[nx][ny] != 1 ) {
				 vis[nx][ny] = 1 ;
				q.emplace( nx , ny , t + 1 ) ;
			}			
		}
	}
	cout << -1 ;
	return 0 ;
}
//questions ：
/*
为什么还要标记走过的格子？
什么时候不用标记？
*/