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
    string temp , str ;
    int cnt = 0 ;
    unordered_map<string , int> name ; 
    while ( cin >> temp ) {
    	if ( temp == "int" ) {
    		cin >> str ; name[str] ++ ; 
			if ( name[str] == 1 ) cnt += 4 ;	
		}
    	else if ( temp == "long") {
    		cin >> str ; cin >> str ; name[str] ++ ; 
    		if ( name[str] == 1 ) cnt += 8 ;	
		}
    	else if ( temp == "double" ) {
    		cin >> str ; name[str] ++ ; 
			if ( name[str] == 1 ) cnt += 8 ;
		}
		
    	else if ( temp == "char" || temp == "bool" ) {
    		cin >> str ; name[str] ++ ; 
			if ( name[str] == 1 ) cnt += 1 ;
		}
		
    	else if ( temp == "short" ) {
    		cin >> str ; name[str] ++ ; 
			if ( name[str] == 1 ) cnt += 2 ;
		}
	}
//	for ( auto &[a , b] : name ) cout << a << endl ;
	cout << cnt << endl ;
    return 0 ; 
}