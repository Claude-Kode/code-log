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

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n , m ;
		cin >> n >> m ;
		vector<int> audio ( n ) , pos ( n ) ;
		for ( int i = 0 ; i < n ; i ++ ) {
			cin >> audio[i] >> pos[i] ;
		}
		// for ( auto &a : audio ) cout << "audio : " << a << ' ' ;
		// cout << endl ;
		int lpos = 0 , ans = 0 ;
		for ( int i = 0 ; i < n ; i ++ ) {
			int td = 0 , npos = pos[i] ;
			i > 0 ? td = audio[i] - audio[i - 1] : td = audio[i] ; 
			// cout << "i : " << i << ' ' << "td : " << td << " audio[i] : " << audio[i] << endl  ; 
			if ( lpos == npos ) { // 如果在同侧
				( td & 1 ) == 0 ? ans += td : ans += td - 1 ;
			}
			else { // 如果在异侧
				( td & 1 ) == 1 ? ans += td : ans += td - 1 ;
			}
			lpos = pos[i] ; 
		}
		ans += m - audio.back() ; 
		cout << ans << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/