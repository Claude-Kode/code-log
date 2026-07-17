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

// functions declarations

// idea
/*

*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ; cin >> n ;
	vector<vector<int>> arr ( n , vector<int> ( n , 0 ) ) , vis ( n , vector<int> ( n , 0 ) ) ;
	for ( auto &row : arr ) {
		for ( auto &a : row ) {
			cin >> a ;
		}
	} 
	int ans = -1 ;
	int start_x , start_y , end_x , end_y ;
	cin >> start_x >> start_y >> end_x >> end_y ;
	// x , y , step 
	queue<tuple<int , int , int>> q ;
	q.emplace( start_x - 1 , start_y - 1 , 0 ) ;
	vis[start_x - 1][start_y - 1] = 1 ;
	auto BFS = [&] () -> void {
		while ( !q.empty() ) {
			auto [x , y , step] = q.front() ; q.pop() ;
			int dis = arr[x][y] ;
			int dirs[4][2] = { { dis , 0 } , { -dis , 0 } , { 0 , dis } , { 0 , -dis } } ;
			for ( auto &dir : dirs ) {
				int nx = x + dir[0] , ny = y + dir[1] ; 
				if ( nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] ) {
					if ( nx == end_x - 1 && ny == end_y - 1 ) { ans = step + 1 ; return ; }
					q.emplace( nx , ny , step + 1 ) ;
					vis[nx][ny] = 1 ;					
				}
			}
		}
	} ;
	BFS () ;
	cout << ans ;
	return 0 ;
}
//questions ：
/*

*/