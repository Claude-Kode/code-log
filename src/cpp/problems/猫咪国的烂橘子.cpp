// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
// #include <unordered_map>
// #include <stack>
// #include <map>
// #include <queue>
// #include <deque>
// macro definition
#define endl '\n'
#define int long long
#define gap ' ' 
// namespace declarations
using namespace std ;
// global variables && arrays
int dirs[4][2] = { { -1 , 0 } , { 1 , 0 } , { 0 , 1 } , { 0 , -1 } } ;
// functions declarations

// idea
/*

*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ; cin >> n ;
	vector<vector<int>> map ( n , vector<int> ( n , 0 ) ) ;
	queue<pair<int , int>> q ;
	vector<vector<int>> vis ( n , vector<int> ( n , 0 ) ) ;
	int fresh = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < n ; j ++ ) {
			cin >> map[i][j] ;
			if ( map[i][j] == 2 ) { 
				q.emplace( i , j ) ;
				vis[i][j] = 1 ;
			}
			if ( map[i][j] == 1 ) fresh ++ ;
		}
	}
	// BFS
	auto BFS = [&]() -> int {
		int round = 0 , fre = 0 ;
		while ( !q.empty() ) {
			int len = q.size() ;
			round ++ ;
			while ( len -- ) {
				auto [x , y] = q.front() ; q.pop() ;
				for ( auto &dir : dirs ) {
					int nx = x + dir[0] , ny = y + dir[1] ;
					if ( nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && map[nx][ny] == 1 ) {
						q.emplace( nx , ny ) ; vis[nx][ny] = 1 ;
						fre ++ ;
						if ( fre >= fresh ) { return round ; } // return 
					}
				}
			}
		}
		return -1 ;
	} ;
	cout << BFS() << endl ;
	return 0 ;
}
//questions ：
/*

*/