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
    int n ; cin >> n ; 
    vector<int> arr ( n + 1) ;
    int sum = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
    	cin >> arr[i] ;
    	if ( ( i & 1 ) == 1 ) sum += arr[i] ;
	}
	int boost = INT_MIN ; 
	for ( int i = 1 ; i <= n ; i ++ ) {
		if ( ( i & 1 ) == 0 ) 
			boost = max ( { boost , arr[i] - arr[i - 1] , arr[i] - arr[i + 1] } ) ;
	}
//     cout << sum << endl ;
	if ( boost > 0 ) sum += boost ;
	cout << sum << endl ; 
    return 0 ; 
}