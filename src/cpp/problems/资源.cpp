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
    int n , m ; cin >> n >> m ;
    vector<vector<int>> arr ( n , vector<int> ( m ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
    	for ( int j = 0 ; j < m ; j ++ ) {
    		cin >> arr[i][j] ;
		}
	}
	int cnt = 0 ; 
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			if ( arr[i][j] == 0 ) {
				cnt ++ ;
				if ( j < m - 1 && arr[i][j + 1] == 0 ) arr[i][j + 1] = 1 ;
			}
		} 
	}
	cout << cnt << endl ;
    return 0 ; 
}