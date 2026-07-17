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
int n , m ;
bool success = false ;
vector <vector<bool>> mp ( 101 , vector<bool> ( 101 , false ) ) ;
// functions declarations
void BFS ( int x , int y ) {
	queue<pair<int , int>> myqueue ;
	myqueue.push( { x , y } ) ;
	mp[x][y] = false ;
	while ( !myqueue.empty() ) {
		auto operating = myqueue.front() ;
		myqueue.pop() ;
		if ( operating.first == n && operating.second == m ) { success = true ; return ; }
		// join queue
		if ( mp[x + 1][y] ) {
			mp[x + 1][y] = false ;
			myqueue.push( { operating.first + 1 , operating.second } ) ;
		}
		if ( mp[x - 1][y] ) {
			mp[x - 1][y] = false ;
			myqueue.push( { operating.first - 1 , operating.second } ) ;
		}
		if ( mp[x][y + 1] ) {
			mp[x][y + 1] = false ;
			myqueue.push( { operating.first , operating.second + 1 } ) ;
		}
		if ( mp[x][y - 1] ) {
			mp[x][y - 1] = false ;
			myqueue.push( { operating.first , operating.second - 1 } ) ;
		}
	} 
}
// idea
/*
final target : x == n && y == m 
*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = 1 ; j <= m ; j ++ ) {
			char temp ; cin >> temp ;
			// wall 
			if ( temp == '.' ) mp[i][j] = true ;
		}
	}
	BFS ( 1 , 1 ) ;
	success ? cout << "Yes" << endl : cout << "No" << endl ;
	return 0 ;
}
//questions ：
/*

*/