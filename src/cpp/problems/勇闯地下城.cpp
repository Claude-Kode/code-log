// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
int n , m ;
int target_x , target_y ;
bool sign  = false ;
int dirs[4][2] = { {-1 , 0 } , { 1 , 0 } , { 0 , 1 } , { 0 , -1 } } ;
vector<vector<vector<int>>> st ( 1005 , vector<vector<int>> ( 1005 , vector<int>( 2 , 0 ) ) ) ;
vector<vector<int>> maze ( 1005 , vector<int> ( 1005 , 0 ) ) ;
// functions declarations

// DFS
void DFS ( int x , int y , int rem , vector<vector<int>> &maze , vector<vector<vector<int>>> &st ) {
	// return 
	if ( x == target_x && y == target_y ) {
		sign = true ; return ;
	}
	if ( sign ) return ;
	// search
	for ( auto &dir : dirs ) {
		int nx = x + dir[0] , ny = y + dir[1] ;
		if ( nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != 2 ) {
			// 此处要处理rem , 如果st[x][y][nrem] == 1 , 说明已经访问过了不能在访问了
			//
			int nrem = rem - maze[nx][ny] ;
			if ( nrem < 0 ) continue ;
			if ( st[nx][ny][nrem] == 1 ) continue ; 
			//  如果到了这里说明这个状态没有被标记过
			st[nx][ny][nrem] = 1 ;
			DFS ( nx , ny , nrem , maze , st ) ;
			st[nx][ny][nrem] = 0 ;
		}
	}
	return ;
}
// idea
/*

*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		sign = false ;
		cin >> n >> m ;
		for ( int i = 0 ; i < n ; i ++ ) {
			for ( int j = 0 ; j < m ; j ++ ) {
				char temp ; cin >> temp ;
				if ( temp == '#' ) maze[i][j] = 2 ;
				else if ( temp == '*' ) maze[i][j] = 1 ;
				else if ( temp == 'T' ) {
					target_x = i ; target_y = j ;
				}
//                 cout << maze[i][j] << ' ' ; 
			} 
//             cout << endl ;
		}
//         cout <<endl << target_x << ' ' << target_y << ' ' ;
		// 状态标记数组 st[x][y][rem] == 1证明点 ( x , y , rem ) 这个状态已经被访问过了
		// dfs的时候对于相同的状态不能退回
		// 这里有一个问题就是关于坐标的回溯和状态的回溯 , 坐标的位置是可以回溯的但是状态不能回溯吧 ?
		// 这里能不能接上记忆化呢>...
		
		if ( maze[0][0] == 1 ) { st[0][0][0] = 1 ; DFS ( 0 , 0 , 0 , maze , st ) ; } 
		else if ( maze[0][0] == 2 ) { cout << "NO" << endl ; continue ; }
		else { DFS ( 0 , 0 , 1 , maze , st ) ; }
		sign ? cout << "YES" << endl : cout << "NO" << endl ;
	}
}
//questions ：
/*

*/