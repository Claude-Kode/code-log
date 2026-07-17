#include <bits/stdc++.h>

using namespace std ; 

#define int long long 
#define endl '\n'

const int maxn = 1e9 ;
const int mod = 1e9 + 7 ; 

int a ; 

void solve() {
	
	
	
}

signed main() {
	
	int tt ; cin >> tt ; 
	while ( tt -- ) {
	
		cin >> a ; 
		if ( a <= 8 ) {
			cout << a << endl ;
			continue ; 
		}
        int res = a / 8 + a ; 
        if ( a % 8 == 0 ) res -- ; 
        cout << res << endl ;
	
	}
	
	return 0 ; 
}