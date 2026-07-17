#include <bits/stdc++.h>

using namespace std ; 

#define int long long 
#define endl '\n'

const int maxn = 1e9 ;
const int mod = 1e9 + 7 ; 

int x , y , z ; 


void solve() {
	
	
	
}

signed main() {
	
	int tt ; cin >> tt ; 
	while ( tt -- ) {

		cin >> x >> y >> z ;
		double dis = labs( y - x ) ;
		if ( dis <= z ) {
			cout << 1 << endl ; 
			continue ; 
		}
		int cnt = 0 ;
		while ( dis > z ) {
			dis /= 2 ;
			cnt ++ ; 
		}
		cout << cnt << endl ; 	
	
	}
	
	return 0 ; 
}