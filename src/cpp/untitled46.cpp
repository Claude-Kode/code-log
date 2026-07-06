#include<iostream>
using namespace std;
bool dp[10005] ;
bool xdp[10005] ;
int main(){
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	cout.tie ( NULL ) ; 
	int n , x , a , b ;
	cin >> n >> x ;
	dp[0] = 1 ;
	while ( n-- ) {
		cin >> a >> b ;
		for ( int i = 0 ; i <= x ; i ++ ) {
			if ( dp[i] ) {
				if ( i + a <= x ) xdp[i+a] = 1 ;
				if ( i + b <= x ) xdp[i+b] = 1 ;
			}
		}
		if ( xdp[x] == 1 && n > 1 ) xdp[x] = 0 ;
		for ( int i = 0 ; i <= x ; i ++ ) {
			dp[i] = xdp[i] ;
		}
		for ( int i = 0 ; i <=x ; i ++ ) xdp[i] = 0 ; 
	}
	if ( dp[x] ) cout << "Yes" << '\n' ;
	else cout << "No" << '\n' ;
	return 0;
}

