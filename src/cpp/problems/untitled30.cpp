// header file
#include <iostream>
#include <string>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
int n , m ;
bool maze [ 110 ] [ 110 ] ;
bool sign = false ;
// functions declarations
void DFS ( int x , int y ) {
	if ( sign ) return ;
	if ( x == m  && y == n ) {
		sign = true ;
	} else { // the sequence is up , right , down , left
		maze [y] [x] = false ;
		if ( maze [y+1] [x] ) { // 上
			DFS ( y+1 , x ) ;
		} 
		if ( maze [y] [x+1] ) { // 右
			DFS ( y , x + 1 ) ;
		}
		if ( maze [y-1] [x] ) { // 下
			DFS ( y-1 , x ) ;
		}
		if ( maze [y] [x-1] ) { // 左
			DFS ( y , x - 1 ) ;
		}
	}
}
//idea
/*
n is max y
m is max x 
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	cin >> n >> m ;
	
	for ( int i = 1 ; i <= n ; i ++ ) {
		string str ;
		cin >> str ;
		for ( int j = 0 ; j < m ; j ++ ) {
			if ( str[j] == '.' ) maze [i] [j+1] = true ; 
		}
	}

	DFS ( 1 , 1 ) ;
	sign ? cout << "Yes" << endl : cout << "No" << endl ;
	return 0 ;
}
//questions ：
/*

*/
