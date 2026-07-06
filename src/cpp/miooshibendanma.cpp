#include <bits/stdc++.h>

using namespace std ; 

#define int long long 
#define endl '\n'

int n , k ;

vector<int> arr , tree ;

int lowbit( int i ) {
	return i & -i ; 
}
 
void update( int pos , int val ) {
	for ( int i = pos ; i <= n ; i += lowbit(i) ) {
		tree[i] &= val ; 
	} 
}

int query( int pos ) {
	int res = 0  ;
	for ( int i = pos ; i > 0 ; i -= lowbit(i) ) {
		res &= tree[i] ;  
	}
	return res ; 
}

void slove() {
	
		
	
}

signed main() {
	
    ios_base :: sync_with_stdio( false ) ; 
    cin.tie( 0 ) ; 
    cout.tie( 0 ) ;
	
	cin >> n >> k ; 
	
	arr.resize( n + 1 ) ;
    int exp = __lg( n ) ; 
    vector<vector<int>> st( exp + 1 , vector<int>( n + 1 )) ; 
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> arr[i] ;
		st[0][i] = arr[i] ; 
	}

    for ( int j = 1 ; j <= exp ; j ++ ) {
        for ( int i = 1 ; i + (1 << j) - 1 <= n ; i ++ ) {
            st[j][i] = st[j - 1][i] & st[j - 1][i + (1 << j - 1)] ; 
        }
    }
	
	int ans = 0 ; 
	while( k -- ) {
		int l , r ; cin >> l >> r ;
        int exp = __lg( r - l + 1 ) ;  
		int res = st[exp][l] & st[exp][r - (1 << exp) + 1] ; 
		cout << res << endl ; 
		ans ^= res ;	
	}
	
	ans ? cout << "bakamio" << endl : cout << "impossible" << endl ; 
    
	return 0 ; 
}