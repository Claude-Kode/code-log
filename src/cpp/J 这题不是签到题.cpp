#include <bits/stdc++.h>

using namespace std ; 

#define int long long 
#define endl '\n'

const int maxn = 1e9 ;
const int mod = 1e9 + 7 ; 

int n , m ; 

vector<int> parent ; 
vector<int> num ; 

void init() {
	parent.resize( n + 1 ) ;
	num.resize( n + 1 ) ;
	for ( int i = 1 ; i <= n ; i ++ ) 
		parent[i] = i ; 
}

int Find( int a ) {
	if ( parent[a] == a ) {
        return a ;
    }
    return parent[a] = Find( parent[a] ) ;
}

void merge( int a , int b ) {
	int fa = Find(a) , fb = Find(b) ; 
	if ( fa == fb ) 
		return ; 
	
	parent[fa] = fb ;
	
}



void solve() {
	
	int a , b ; cin >> a >> b ; 
//     cout << a << b << endl ; 
	merge( a , b ) ; 
	
}

signed main() {
	
	cin >> n >> m ; 
	init() ;
	while ( m -- ) solve() ;
	
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         cout << parent[i] << ' ' ; 
//     }
    
	for ( int i = 1 ; i <= n ; i ++ ) {
		num[Find(i)] ++ ; 
	}
	

	int mx = 1 , mn = 1e9 , cnt = 0 ; 	
	for ( int i = 1 ; i <= n ; i ++ ) {

		mx = max( mx , num[i] ) ;
        
        if ( num[i] ) {
            mn = min( mn , num[i] ) ;
        }
        
		if ( parent[i] == i ) {
			cnt ++ ;
		}
        
	}
	
	cout << cnt << ' ' << mx - mn << endl ; 
	
	return 0 ; 
}