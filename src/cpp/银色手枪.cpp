#include <bits/stdc++.h>

using namespace std ;

#define int long long 
#define endl '\n'

void solve() {

}

/*

*/

signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
    	int n ; cin >> n ; 
    	stack <int> dmg ; 
    	for ( int i = 0 ; i < n ; i ++ ) {
    		int temp ; cin >> temp ;
    		if ( temp == 1 ) {
    			int value ; cin >> value ; 
    			dmg.push( value ) ;
			} else if ( temp == 2 ) dmg.pop() ;
			else {
				!dmg.empty() ? cout << dmg.top() << endl : cout << -1 << endl ;
			}
		}
	}
    return 0 ; 
}