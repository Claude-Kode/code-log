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

// functions declarations

//idea
/*
就是求 r缩小到x一下要多少个d 
如果 r > x 
如果2不可以缩 ， 如果是1才可以缩
如果小于x直接return 所有比赛
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int r , x , d , n ;
		cin >> r >> x >> d >> n ;
		string temp ;
		cin >> temp ;
		if ( r < x ) cout << n << endl ;
		else {
			int cnt = 0 ;
			for ( int i = 0 ; i < n ; i ++ ) {
				if ( r < x || temp[i] == '1' ) cnt ++ ;
				if ( temp[i] == '2' ) continue ;
				r -= d ;
			}
			cout << cnt << endl ;
		}
	}
	return 0 ;
}
//questions ：
/*

*/