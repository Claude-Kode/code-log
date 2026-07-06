#include <bits/stdc++.h>

using namespace std ; 

#define int long long 
#define endl '\n'

int n , m , p , q ;

vector<int> fa( 1e5 ) ; 

int Find( int a ) {
	return a == fa[a] ? a : fa[a] = Find( fa[a] ) ; 
}

void merge( int a , int b ) {
    int ra = Find( a ) ; 
    int rb = Find( b ) ;
    if ( ra == rb ) return ;
    fa[ra] = rb ; 
}

void slove() {
	
		
	
}

signed main() {
	
    ios_base :: sync_with_stdio( false ) ; cin.tie( 0 ) ; cout.tie( 0 ) ;
	
	cin >> n >> m >> p >> q ; 
    
    for( int i = 1 ; i <= n + m + 1 ; i ++ ) fa[i] = i ;
    merge( 1 , n + 1 ) ; 
    while ( p -- ) {
        int a , b ; cin >> a >> b ;
        merge( a , b ) ; 
    }

    while ( q -- ) {
        int a , b ; cin >> a >> b ;
        a = -a + n ; 
        b = -b + n ; 
        merge( a , b ) ;
	}
    
    int men = 0 , women = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( Find(i) == Find(1) ) men ++ ;
    }
    for ( int i = n + 1 ; i <= (n + m) ; i ++ ) {
        if ( Find(i) == Find(n + 1) ) women ++ ;
    }
    
    
    
    cout << min( men , women ) << endl ; 
    
	return 0 ; 
}