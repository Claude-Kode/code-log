#include <bits/stdc++.h>

using namespace std ;

#define int long long 
#define endl '\n'

void solve() {
	int b , c , d ; cin >> b >> c >> d ;
	int a = 0 ; 
	for ( int i = 0 ; i < 63 ; i ++ ) {
		int bb = ( ( b >> i ) & 1 ) ;
		int cc = ( ( c >> i ) & 1 ) ;
		int dd = ( ( d >> i ) & 1 ) ;
//         cout << bb << ' ' << cc << ' ' << dd << endl ;
		if ( dd == 1 && bb == 0 && cc == 1 || dd == 0 && bb == 1 && cc == 0 ) {
			cout << -1 << endl ;
			return ; 			
		}
//         if ( dd == 0 && bb == 0 && cc == 1 ) a += ( 1 << i ) ;
//         if ( dd == 0 && bb == 1 && cc == 1 ) a += ( 1 << i ) ;
//         if ( dd == 1 && bb == 1 && cc )
		if  ( (dd == 0 && ((bb == 0 && cc == 1) || ( bb == 1 && cc == 1 ))) || (dd == 1 && ((bb == 1 && cc == 0) || (bb == 0 && cc == 0))) ) 
			{ a += ( 1 << i ) ; }
//         if ( dd == 0 && bb == 0 && cc == 0 ) 
	}
//     for ( int i = 0 ; i < 10 ; i ++ ) {
//         cout << "bb:" << ( ( b >> i ) & 1 ) << ' ' ;
//         cout << "cc:" << ( ( c >> i ) & 1 ) << ' ' ;
//         cout << "dd:" << ( ( d >> i ) & 1 ) << ' ' ;
//         cout << "a:"  << ( ( a >> i ) & 1 ) << ' ' ;
//         cout << endl ;
//     }
	cout << a << endl ;
//     cout <<( 0 & 0) << endl ;
}

/*

*/

signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) solve() ;
    return 0 ; 
} 