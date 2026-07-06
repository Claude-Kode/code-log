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
    m %= n ;
    queue<int> q ; 
    for ( int i = 0 ; i < n ; i ++ ) {
    	int temp ; cin >> temp ;
    	q.push( temp ) ;
	}
	while ( m -- ) {
		int temp = q.front() ; q.pop() ;
		q.push( temp ) ;
	}
	while ( !q.empty() ) {
		cout << q.front() << ' ' ;
		q.pop() ;
	}
    return 0 ; 
}