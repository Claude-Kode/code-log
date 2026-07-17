#include <bits/stdc++.h>

using namespace std ;

#define int long long 
#define endl '\n'

void solve() {
	int n ; cin >> n ; 
	set<int> myset ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int temp ; cin >> temp ;
		myset.insert( temp ) ;
	}
	int res = 0 ; 
	if ( *(myset.begin()) != 0 ) { 
		cout << 0 << endl ; 
		return ; 
	}
    if ( *myset.rbegin() == myset.size() - 1 ) {
        cout << myset.size() << endl ;
        return ; 
    }
    int i = 0 ;
	for ( auto &it : myset ) {
		if ( it == i ) res ++ ;
		else break ;
        i ++ ;
	}
	cout << res << endl ;
}

/*

*/

signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
	solve() ; 
    return 0 ; 
} 