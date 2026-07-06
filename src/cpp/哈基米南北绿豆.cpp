#include <bits/stdc++.h>

using namespace std ;

#define int long long 
#define endl '\n'

void solve() {
	int n ; cin >> n ;
	vector<vector<int>> arr ( n , vector<int> ( n ) ) ;
	unordered_map<int , int> mp ;
	unordered_map<int , int> diag ;
    int mx = 0 ; 
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < n ; j ++ ) {
			cin >> arr[i][j] ;
			mp[arr[i][j]] ++ ; 
            mx = max ( mx , mp[arr[i][j]] ) ;
			if ( i == j ) {
                diag[arr[i][j]] ++ ;
//                 cout << arr[i][j] << ' ' ; 
//                 cout << i << ' ' << j << endl ;
            }
		}
	}
	int res = INT_MAX ;
	for ( auto &[ele , cnt] : diag ) {
//         cout << ele << ' ' << cnt << endl ;
		if ( mp[ele] - cnt >= n - cnt ) res = min ( res , n - cnt ) ;
	}
//     cout << endl ;
    if ( res == INT_MAX && mx >= n ) res = n ;
	res != INT_MAX ? cout << res << endl : cout << -1 << endl ;
}

/*

*/

signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) solve() ; 
    return 0 ; 
}