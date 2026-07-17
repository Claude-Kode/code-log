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
int answer [10005] ;
bool beenUsed [10005] ;
int cnt = 0 ;
bool sign = false ;
// functions declarations
void DFS ( int step  , int n , int m ) {
	if ( sign ) return ;
	if ( step == n + 1 ) cnt ++ ;
	if ( cnt == m + 1 ) {
		for ( int i = 1 ; i <= n ; i ++ ) {
			cout << answer[i] << ' ' ;
		}
		sign = true ;
	} else {
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( cnt == 0 ) {
				i = answer[step] ;
			}
			if ( !beenUsed[i] ) {
				beenUsed[i] = true ;
				answer[step] = i ;
				DFS( step + 1 , n , m ) ;
				beenUsed[i] = false ;
			}
		}
		return ;
	}
}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , m ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) cin >> answer[i] ; 
	DFS ( 1 , n , m ) ; 
	return 0 ;
}
//questions ：
/*

*/
