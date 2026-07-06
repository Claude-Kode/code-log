// header file
#include <iostream>
#include <algorithm>
#include <queue> 
#include <vector>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , m , x , y ;
	cin >> n >> m >> x >> y ;
	vector<vector<int>> ans ( n , vector<int> ( m , -1 ) ) ; 
	int dirs[8][2] = { { 2 , 1 } , { 2 , -1 } , { -2 , 1 } , { -2 , -1 } , { 1 , 2 } , { 1 , -2 } , { -1 , 2 } , { -1 , -2 } } ;
	// ans coordinate is 0 based
	// x , y , step 
	queue<tuple<int , int , int>> q ; 
	q.emplace( x - 1 , y - 1 , 0 ) ;
	ans[x - 1][y - 1] = 0 ;
	while ( !q.empty() ) {
		auto [x , y , step] = q.front() ; q.pop() ;
		for ( auto &dir : dirs ) {
			int nx = x + dir[0] , ny = y + dir[1] ;
			if ( nx >= 0 && nx < n && ny >= 0 && ny < m ) {
				if ( ans[nx][ny] != -1 ) continue ;
				q.emplace( nx , ny , step + 1 ) ;
				ans[nx][ny] = step + 1 ;
			} 
		}
	}
	for ( auto &row : ans ) {
		for ( auto &a : row ) {
			cout << a << ' ' ;
		}
		cout << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/