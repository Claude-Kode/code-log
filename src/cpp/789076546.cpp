// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
// #include <unordered_map>
// #include <stack>
// #include <map>
// #include <deque>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
typedef tuple<int , int , int> TUP ;
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
	priority_queue<TUP , vector<TUP> , [&]( TUP a , TUP b ) { return a[2] > b[2] ; }> pq ;
	vector<vector<bool>> vis ( n , vector<bool> ( n , 0 ) ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < n ; j ++ ) {
			cin >> map[i][j] ;
		}
		pq.emplace( i , 0 , map[i][0] ) ;
		vis[i][0] = true ;
	}
	// pq.emplace( nx , ny , min ( consume , nconsume ) ) ;
	auto BFS = [&]() -> int {
		while ( !pq.empty() ) {
			auto [x , y , consume] = pq.front() ; pq.pop() ;
			if ( x == n - 1 ) return consume ;
			for ( auto &dir : dirs ) {
				int nx = x + dir[0] , ny = y + dir[1] ;
				if ( nx <= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] ) {
					int nconsume = max( consume , map[nx][ny] ) ;
					pq.emplace( nx , ny , nconsume ) ;
					vis[nx][ny] = true ;
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